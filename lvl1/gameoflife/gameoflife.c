#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	grid[1000][1000] = {0};
char	next[1000][1000] = {0};
int		width;
int 	height;
int 	iter;


int check_neighboors(int r, int c)
{
    int count = 0;

    // Top-left, Top, Top-right
    if (r - 1 >= 0 && c - 1 >= 0 && grid[r - 1][c - 1] == 'O') ++count;
    if (r - 1 >= 0 && grid[r - 1][c] == 'O') ++count;
    if (r - 1 >= 0 && c + 1 < width && grid[r - 1][c + 1] == 'O') ++count;
    
    // Left, Right
    if (c - 1 >= 0 && grid[r][c - 1] == 'O') ++count;
    if (c + 1 < width && grid[r][c + 1] == 'O') ++count;
    
    // Bottom-left, Bottom, Bottom-right
    if (r + 1 < height && c - 1 >= 0 && grid[r + 1][c - 1] == 'O') ++count;
    if (r + 1 < height && grid[r + 1][c] == 'O') ++count;
    if (r + 1 < height && c + 1 < width && grid[r + 1][c + 1] == 'O') ++count;

    return(count);
}

void simulate()
{
	int i = 0;
	while (i < iter)
	{
		for(int r = 0; r < height; r++) {
			for(int c = 0; c < width; c++) {
				if(grid[r][c] == 'O')
				{
					if(check_neighboors(r, c) >= 4 || check_neighboors(r, c) <= 1)
						next[r][c] = ' ';
					else
						next[r][c] = 'O';
				}
				else if(grid[r][c] == ' ')
				{
					if(check_neighboors(r, c) == 3)
						next[r][c] = 'O';
					else
						next[r][c] = ' ';
				}
			}
		}
		for(int r = 0; r < height; r++) {
			for(int c = 0; c < width; c++) {
				grid[r][c] = next[r][c];
			}
		}
		++i;
	}
}

int main(int ac, char **av)
{
	if (ac != 4)
		return 1;
	
	width = atoi(av[1]);
	height = atoi(av[2]);
	iter = atoi(av[3]);
	for(int r = 0; r < height; r++) {
		for(int c = 0; c < width; c++) {
			grid[r][c] = ' ';
		}
	}

	int r = 0;
	int c = 0;
	int drawing = 0;
	char cmd;

	while (read(0, &cmd, 1) > 0)
	{
		if(cmd == 'x')
		{
			drawing = !drawing;
			if(drawing && ((r >= 0 && c >= 0) && (c < width && r < height)))
				grid[r][c] = 'O';
		}
		else if(cmd == 'd')
			c++;
		else if(cmd == 'a')
			c--;
		else if(cmd == 's')
			r++;
		else if(cmd == 'w')
			r--;
		
		if(drawing && ((r >= 0 && c >= 0) && (c < width && r < height)))
			grid[r][c] = 'O';
	}

	simulate();

	for(int r = 0; r < height; r++) {
		for(int c = 0; c < width; c++) {
			putchar(grid[r][c]);
		}
		putchar('\n');
	}
}