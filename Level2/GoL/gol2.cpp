//1.includes
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//2.args, vars (10)
int main(int argc, char** argv){
	(void) argc;
	int w = atoi(argv[1]);
	int h = atoi(argv[2]);
	int iter = atoi(argv[3]);
	int x = 0;
	int y = 0;
	int pen = 0;
	int board[h][w];
	int next[h][w];
	char c;
	//3.create board (2 for)
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			board[i][j] = 0;
		}
	}
	//4.controls (while, 6 if, yx)
	while (read(0, &c, 1) == 1){
		if (c == 'w' && y > 0) y--;
		else if (c == 's' && y< h-1) y++;
		else if (c == 'a' && x > 0) x--;
		else if (c == 'd' && x < w-1) x++;
		else if (c == 'x') pen = !pen;
		if(pen) board[y][x] = 1;
	}
	//5.simulation
	//iters
	for (int t = 0; t < iter;t++){
		//height
		for(int i = 0; i < h; i++){
			//width
			for(int j = 0; j < w;j++){
				//check neighbors (n, 2 for po di)
				int n = 0;
				for (int di = -1;di<=1;di++){
					for (int dj = -1; dj <=1;dj++){
						if((di || dj) && i+di>=0 && i+di<h && j+dj >=0 && j+dj < w){
							n+=board[i+di][j+dj];
						}
					}
				}
				//simulate life
				next[i][j] = (board[i][j] && (n == 2 || n == 3)) || (!board[i][j] && n == 3);
			}
		}
			//copy next2board (2 for)
			for (int i = 0; i < h;i++){
				for (int j = 0; j < w; j++){
					board[i][j] = next[i][j];
				}
			}
	}
	//6.printout (2 for, putchar, putchar)
	for (int i = 0; i < h;i++){
		for (int j = 0; j < w;j++){
			putchar(board[i][j] ? 'O' : ' ');
		}
		putchar('\n');
	}
	return(0);
}