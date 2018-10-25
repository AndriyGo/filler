#import "filler.h"
#import "libft/libft.h"

int		next_sig_in_col(char **map, int x, int y, t_filler *filler)
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

int		next_sig_in_row(char **map, int x, int y, t_filler *filler)
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

int		point_row_score(char **map, int x, int y, t_filler *filler)
{
	int c;
	int score;
	int n;

	c = x + 1;
	score = 0;
	n = next_sig_in_col(map, x, y, filler);
	if (n == 0)
		return (0);
	while (c-- > 0)
		if ((map[y][c] == 0) || (map[y][c] == n))
			score++;
		else
			break;
	c = x;
	while (++c < filler->w)
		if ((map[y][c] == 0) || (map[y][c] == n))
			score++;
		else
			break;
	//printf("(%d, %d): %d \n",y, x, score );
	return (score * n);
}

int		point_col_score(char **map, int x, int y, t_filler *filler)
{
	int c;
	int score;
	int n;

	c = y + 1;
	score = 0;
	n = next_sig_in_row(map, x, y, filler);
	if (n == 0)
		return (0);
	while (c-- > 0)
		if ((map[c][x] == 0) || (map[c][x] == n))
			score++;
		else
			break;
	c = y;
	while (++c < filler->h)
		if ((map[c][x] == 0) || (map[c][x] == n))
			score++;
		else
			break;
	return (score * n);
}

int		rows_score(char **map, t_filler *filler)
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
			score += point_col_score(map, x, y, filler);
			/*if (map[y][x] == 0)
				cur += 1 + point_col_score(map, x, y, filler);
			else
			{
				score += (((prev == map[y][x]) || (prev == 0)) ? cur * map[y][x] : 0);
				cur = 0;
				prev = map[y][x];
			}*/
			x++;
		}
		score += cur * prev;
		y++;
	}
	return (score);
}

int		cols_score(char **map, t_filler *filler)
{
	int cur;
	int sum;
	int x;
	int y;
	int score;
	int prev;

	score = 0;
	x = 0;
	while (x < filler->w)
	{
		y = 0;
		cur = 0;
		prev = 0;
		while (y < filler->h)
		{
			score += point_row_score(map, x, y, filler);
			/*if (map[y][x] == 0)
				cur += 1 + point_row_score(map, x, y, filler);
			else
			{
				score += (((prev == map[y][x]) || (prev == 0)) ? cur * map[y][x] : 0);
				cur = 0;
				prev = map[y][x];
			}*/
			y++;
		}
		score += cur * prev;
		x++;
	}
	return (score);
}

int		calc_score(char **map, t_filler *filler)
{
	return (rows_score(map, filler) + cols_score(map, filler));
}

int		score_improves(t_filler *filler, int y, int x)
{
	int i;
	int j;
	char **copy;
	int score;

	copy = copy_map(filler);
	j = 0;
	while (j < filler->shape->h)
	{
		i = 0;
		while (i < filler->shape->w)
		{
			if (filler->shape->map[j][i] == 1)
			{
				copy[j+y][i+x] = 1;
			}
			i++;
		}
		j++;
	}
	//printf("%d %d\n",y,x );
	score = calc_score(copy, filler);
	i = 0;
	while (i < filler->h)
		free(copy[i++]);
	free(copy);
	if ((score > filler->shape->score) || (filler->shape->x == -1))
	{
		filler->shape->score = score;
		return (1);
	}
	return (0);
}

int		should_place_shape(t_filler *filler, int y, int x)
{
	int i;
	int c;
	int j;

	j = 0;
	c = 0;
	while (j < filler->shape->h)
	{
		i = 0;
		while (i < filler->shape->w)
		{
			if ((filler->map[j+y][i+x] == -1) && (filler->shape->map[j][i]))
				return (0);
			if ((filler->map[j+y][i+x] == 1) && (filler->shape->map[j][i]))
			{
				c++;
				if (c > 1)
					return (0);
			}
			i++;
		}
		j++;
	}
	//printf("\n");
	if (c != 1)
		return (0);
	if (score_improves(filler, y, x))
		return (1);
	return (0);
}

void	place_shape_if_possible(t_filler *filler, int y, int x)
{
	if (should_place_shape(filler, y, x))
	{
		filler->shape->x = x;
		filler->shape->y = y;
	}
}

void	skip_turn()
{
	dprintf(1, "%d %d\n", 0, 0);
}

void	find_solution(t_filler *filler)
{
	int	y_start;
	int x_start;
	int x_end;
	int y_end;
	int x;
	int y;

	filler->shape->score = calc_score(filler->map, filler);
	y_start = filler->rect->y0 - filler->shape->h + 1;
	if (y_start < 0)
		y_start = 0;
	x_start = filler->rect->x0 - filler->shape->w + 1;
	if (x_start < 0)
		x_start = 0;
	y = y_start;
	y_end = (filler->rect->y1 + filler->shape->h - 1 < filler->h) ? (filler->rect->y1) : (filler->h - filler->shape->h);
	x_end = (filler->rect->x1 + filler->shape->w - 1 < filler->w) ? (filler->rect->x1) : (filler->w - filler->shape->w);
	//printf("(%d, %d); (%d, %d); (%d %d)\n", y_start, x_start, y_end, x_end, filler->shape->h, filler->shape->w);
	//place_shape_if_possible(filler, 4, 7);
	while (y <= y_end)
	{
		x = x_start;
		while (x <= x_end)
		{
			place_shape_if_possible(filler, y, x++);
		}
		y++;
	}
	ft_log("Solved\n");
	if (filler->shape->x == -1)
		skip_turn();
	else
	{
		ft_log("%d %d\n", (int) (filler->shape->y - filler->shape->y_off), (int) (filler->shape->x - filler->shape->x_off));
		dprintf(1, "%d %d\n", (int) (filler->shape->y - filler->shape->y_off), (int) (filler->shape->x - filler->shape->x_off));
	}
}