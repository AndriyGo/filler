#include "filler.h"

int		next_sig_in_col2(char **map, int x, int y, t_filler *filler)
{
	int cand;

	cand = 0;
	if (map[y][x] != 0)
		return (map[y][x]);
	while (y < filler->h)
	{
		if (map[y][x] != 0)
		{
			cand = map[y][x];
			break ;
		}
		y++;
	}
	y--;
	while (y >= 0)
	{
		if (map[y][x] != 0)
		{
			if ((map[y][x] == cand) || (cand == 0))
				return (map[y][x]);
			else
				return (0);
		}
		y--;
	}
	return (cand);
}

int		next_sig_in_row2(char **map, int x, int y, t_filler *filler)
{
	int cand;

	cand = 0;
	if (map[y][x] != 0)
		return (map[y][x]);
	while (x < filler->w)
	{
		if (map[y][x] != 0)
		{
			cand = map[y][x];
			break ;
		}
		x++;
	}
	x--;
	while (x >= 0)
	{
		if (map[y][x] != 0)
		{
			if ((map[y][x] == cand) || (cand == 0))
				return (map[y][x]);
			else
				return (0);
		}
		x--;
	}
	return (cand);
}

int		point_row_score2(char **map, int x, int y, t_filler *filler)
{
	int c;
	int score;
	int n;

	c = x + 1;
	score = 0;
	n = next_sig_in_col2(map, x, y, filler);
	if (n == 0)
		return (0);
	while (c-- > 0)
		if ((map[y][c] == 0))
			score++;
		else
			break;
	c = x;
	while (++c < filler->w)
		if ((map[y][c] == 0))
			score++;
		else
			break;
	//printf("(%d, %d): %d \n",y, x, score );
	return (score * n);
}

int		point_col_score2(char **map, int x, int y, t_filler *filler)
{
	int c;
	int score;
	int n;

	c = y + 1;
	score = 0;
	n = next_sig_in_row2(map, x, y, filler);
	if (n == 0)
		return (0);
	while (c-- > 0)
		if ((map[c][x] == 0))
			score++;
		else
			break;
	c = y;
	while (++c < filler->h)
		if ((map[c][x] == 0))
			score++;
		else
			break;
	return (score * n);
}

int		rows_score2(char **map, t_filler *filler)
{
	int cur;
	int sum;
	int x;
	int y;
	int score;
	int prev;

	score = 0;
	y = 0;
	while (y < filler->h)
	{
		x = 0;
		cur = 0;
		prev = 0;
		while (x < filler->w)
		{
			score += point_col_score2(map, x, y, filler) + point_row_score2(map, x, y, filler);
			x++;
		}
		score += cur * prev;
		y++;
	}
	return (score);
}

int		calc_score2(char **map, t_filler *filler)
{
	return (rows_score2(map, filler));
}