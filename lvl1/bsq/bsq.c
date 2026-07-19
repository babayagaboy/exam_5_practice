#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char matrix[1000][1000] = {0};
int dp[1000][1000];

int 	row;
int		col;
char	empty;
char	full;
char	obs;

int min3(int a, int b, int c)
{
	int min = a;
	if( b < min ) min = b;
	if( c < min ) min = c;
	return(min);
}

void solve()
{
	int max_size_square = 0;
	int max_row = 0;
	int max_col = 0;

	for(int r = 0; r < row; r++) {
		for(int c = 0; c < col; c++) {
			if(matrix[r][c] == obs) dp[r][c] = 0;
			else if (r == 0 || c == 0) dp[r][c] = 1;
			else
			{
				dp[r][c] = 1 + min3(dp[r - 1][c],
									dp[r][c - 1],
									dp[r - 1][c - 1]);
			}
			if (dp[r][c] > max_size_square)
			{
				max_size_square = dp[r][c];
				max_row = r;
				max_col = c;
			}
		}
	}
	for(int r = max_row; r > max_row - max_size_square; r--) {
		for(int c = max_col; c > max_col - max_size_square; c--) {
			matrix[r][c] = full;
		}
	}
}

int get_matrix(FILE *file)
{
	char* line = NULL;
	size_t	len = 0;
	int read;
	int r = 0;

	while ((read = getline(&line, &len, file)) != -1)
	{
		if (r >= row)
			return (free(line), 1);
		if(read <= 0 || line[read - 1] != '\n')
			return (free(line), 1);
		line[read - 1] = '\0';
		read--;
		if(r == 0)
			col = read;
		else if (read != col || col <= 0)
			return (free(line), 1);
		for(int c = 0; c < read; c++) {
			if (line[c] != obs && line[c] != empty)
				return(free(line), 1);
			matrix[r][c] = line[c];
		}
		r++;
	}
	free(line);
	if ( r != row )
		return 1;
	return(0);
}

int main(int ac, char **av)
{
	if(ac != 2)
		return 1;
	FILE *file = fopen(av[1], "r");
	if (!file)
		return 1;
	if(fscanf(file, "%d %c %c %c", &row, &empty, &obs, &full) != 4)
		return(1);
	// printf("%d, %c, %c, %c", row, empty, obs, full);
	
	char *temp_line = NULL;
    size_t temp_len = 0;
    getline(&temp_line, &temp_len, file);
    free(temp_line);
	
	if(get_matrix(file) == 1)
		return (1);

	solve();

	for(int r = 0; r < row; r++) {
		for(int c = 0; c < col; c++) {
			printf("%c", matrix[r][c]);
		}
		printf("\n");
	}
	fclose(file);

	// printf("\n");
	// printf("\n");
	// for(int r = 0; r < row; r++) {
	// 	for(int c = 0; c < col; c++) {
	// 		printf("%i", dp[r][c]);
	// 	}
	// 	printf("\n");
	// }
}