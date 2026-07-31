//1.Includes(3)
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char** argv){
    //2.main, args, vars
    (void) argc;
    int w = atoi(argv[1]);
    int h = atoi(argv[2]);
    int iter = atoi(argv[3]);
    int x = 0;
    int y = 0;
    int board[h][w];
    int next[h][w];
    int pen = 0;
    char c;
    //3.board
    for (int i=0; i<h;i++){
        for(int j=0;j<w;j++){
            board[i][j] = 0;
        }
    }
    //4.controls
    while(read(0,&c,1) == 1){
        if(c == 'w' && y>0) y--;
        else if (c == 's' && y < h-1) y++;
        else if (c == 'a' && x > 0) x--;
        else if (c == 'd' && x < w-1) x++;
        if (c == 'x') pen = !pen;
        if (pen) board[y][x] = 1;
    }
    //5.sim
    for(int t=0; t<iter;t++){
        for (int i=0; i<h;i++){
            for(int j=0;j<w;j++){
                int n = 0;
                for (int di=-1; di<=1;di++){
                    for(int dj=-1;dj<=1;dj++){
                        if((di||dj)&& i+di>=0 && i+di<h && j+dj>=0 && j+dj<w)
                            n+=board[i+di][j+dj];
                    }
                }
                //sim
                next[i][j] = (board[i][j] && (n==2||n==3))||(!board[i][j]&&n==3);
            }
        }
        for (int i=0; i<h;i++){
            for(int j=0;j<w;j++){
                board[i][j] = next[i][j];          
            }
        }
    }
    for (int i=0; i<h;i++){
        for(int j=0;j<w;j++){
            putchar(board[i][j] ? 'O' : ' ');        
        }
        putchar('\n');
    }
    return(0);
    //6.print
}

    // for (int i=0; i<h;i++){
    //     for(int j=0;j<w;j++){
            
    //     }
    // }