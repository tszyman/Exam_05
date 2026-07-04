#include "life.h"

//print map

//free map

//fill map
static void fill_map(t_game *game)
{
    char buffer;
    int x = 0;
    int y = 0;
    bool draw = false;

    while (read(STDIN_FILENO, &buffer, 1) == 1)
    {
        swithch (buffer)
        {
            case ('w'): if(y > 0) {--y; }; break;
            case ('a'): if()
            case ('s')
            case ('d')
            case ('x')
        }
    }
}

//count neighbors
static int count_neighbors(t_game game, int y, int x)
{
    int count = 0;

    for(int dy = -1; dy < 2; ++dy)
    for(int dx = -1; dx < 2; ++dx)
    {
        //skip iteration for origin point
        if (dx == 0 && dy == 0)
            continue;
        int nx = x + dx;
        int ny = y + dy;
        // if cell is within the game AND is marked alive
        if (nx >= 0 && nx < game.width && ny >= 0 && ny < game.height && game.map[ny][nx] == '0')
            count++;
    }
    return(count);
}

//play game
static void play_game(t_game *game)
{
    //allocate new map (easier than redraw)
    char **new_map = malloc(game->height * sizeof(char *));
    for (int y = 0; y < game->height; ++y)
        new_map[y] = malloc(game->width * sizeof(char *));

    for(int y = 0; y < game->height, ++y)
        for (int x = 0; x < game->width; ++x)
        {
            int neighbors = count_neighbors(*game, x, y);
            if(game->map[y][x] == '0')
            {
                //if cell ia alive with 2 or 3 meghbours - do nothing
                if (neighbors == 2 || neighbors == 3)
                    new_map[y][x] = '0';
                //otherwise - kill it
                else
                    new_map[y][x] = ' ';
            }
            //if cell is dead with 3 naighbours - make it alive
            else
            {
                if (neighbors == 3)
                    new_map[y][x] = '0';
                else
                    new_map[y][x] = ' ';
            }

        }
        //Free old map and replace with new
        free_map(game);
        game->map = new_map;
}


//init game
static void init_game(t_game *game, const char **argv)
{
    game->width = atoi(argv[1]);
    game->height = atoi(argv[2]);
    game->iterarion = atoi(argv[3]);

    game->map = malloc(game->height * sizeof(char *));
    for (int y = 0; y < game->height; ++y)
    {
        game->map[y] = malloc(game->width * sizeof(char *));
        // Fill the map wigh dead cells
        for (int x = 0; x < game->width; ++x))
            game->map[y][x] = ' ';
    }
}
//main
int main(const int argc, const char **argv)
{
    if(argc != 4)
        return (1);

    t_game game;

    init_game(&game, argv);

    fill_map(&game);

    for (int i = 0; i < game.iteration; ++i)
        play_game(&game);

    print_map(game);
    free_map(&game);

    return(0);
}