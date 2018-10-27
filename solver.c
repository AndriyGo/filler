#import "filler.h"
#import "libft/libft.h"

void	log_map_c(char *s, char **map, t_filler *filler)
{
	ft_log("%s\n", s);
	int x;
	int y;
	int score;

	y = 0;
	while (y < filler->h)
	{
		x = 0;
		score = 0;
		while (x < filler->w)
		{
			ft_log("%3d ", map[y][x]);
			x++;
		}
		ft_log("\n");
		y++;
	}
}

void	log_map(char *s, int **map, t_filler *filler)
{
	ft_log("%s\n", s);
	int x;
	int y;
	int score;

	y = 0;
	while (y < filler->h)
	{
		x = 0;
		score = 0;
		while (x < filler->w)
		{
			ft_log("%3d ", map[y][x]);
			x++;
		}
		ft_log("\n");
		y++;
	}
}

void	log_problem(t_filler *filler)
{
	int x;
	int y;
	int score;

	ft_log("MAP\n");
	y = 0;
	while (y < filler->h)
	{
		x = 0;
		score = 0;
		while (x < filler->w)
		{
			ft_log("%3d ", filler->map[y][x]);
			x++;
		}
		ft_log("\n");
		y++;
	}

	ft_log("\nMY SCORE\n");
	y = 0;
	while (y < filler->h)
	{
		x = 0;
		score = 0;
		while (x < filler->w)
		{
			ft_log("%3d ", point_score(filler, y, x));
			x++;
		}
		ft_log("\n");
		y++;
	}

	ft_log("\nPREV SCORE\n");
	y = 0;
	while (y < filler->h)
	{
		x = 0;
		score = 0;
		while (x < filler->w)
		{
			ft_log("%3d ", point_col_score2(filler->map, x, y, filler) + point_row_score2(filler->map, x, y, filler));
			x++;
		}
		ft_log("\n");
		y++;
	}
}

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

	c = x + 1;
	score = 0;
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
	return (score);
}

int		point_col_score(char **map, int x, int y, t_filler *filler)
{
	int c;
	int score;

	c = y + 1;
	score = 0;
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
	return (score);
}

void	update_score_row(t_filler *filler, int y)
{
	int x;
	int score;

	x = 0;
	score = 0;
	while (x < filler->w)
	{
		if (filler->map[y][x] != 0)
		{
			score = 0;
			filler->row_sc[y][x] = 1;
		}
		else
		{
			if (score == 0)
				score = point_row_score(filler->map, x, y, filler);
			filler->row_sc[y][x] = score;
		}
		x++;
	}
}

void	update_sig_row(t_filler *filler, int y)
{
	int x;
	int score;

	x = 0;
	score = 0;
	while (x < filler->w)
	{
		if (filler->map[y][x] != 0)
		{
			score = 0;
			filler->sig_r[y][x] = filler->map[y][x];
		}
		else
		{
			if (score == 0)
				score = next_sig_in_row(filler->map, x, y, filler);
			filler->sig_r[y][x] = score;
		}
		x++;
	}
}

void	update_score_col(t_filler *filler, int x)
{
	int y;
	int score;

	y = 0;
	score = 0;
	while (y < filler->h)
	{
		if (filler->map[y][x] != 0)
		{
			score = 0;
			filler->col_sc[y][x] = 1;
		}
		else
		{
			if (score == 0)
				score = point_col_score(filler->map, x, y, filler);
			filler->col_sc[y][x] = score;
		}
		y++;
	}
}

void	update_sig_col(t_filler *filler, int x)
{
	int y;
	int score;

	y = 0;
	score = 0;
	while (y < filler->h)
	{
		if (filler->map[y][x] != 0)
		{
			score = 0;
			filler->sig_c[y][x] = filler->map[y][x];
		}
		else
		{
			if (score == 0)
				score = next_sig_in_col(filler->map, x, y, filler);
			filler->sig_c[y][x] = score;
		}
		y++;
	}
}

void	update_score(t_filler *filler, int y, int x)
{
	update_sig_row(filler, y);
	update_sig_col(filler, x);
	update_score_col(filler, x);
	update_score_row(filler, y);
}

int		score(char **map, t_filler *filler)
{
	int x;
	int y;
	int score;

	score = 0;
	x = 0;
	while (x < filler->w)
	{
		y = 0;
		while (y < filler->h)
		{
			score += point_score(filler, y, x);
			y++;
		}
		x++;
	}
	return (score);
}

int		point_score(t_filler *filler, int y, int x)
{
	int score;

	if (filler->map[y][x] == 0)
		return (filler->row_sc[y][x] * filler->sig_c[y][x] + filler->col_sc[y][x] * filler->sig_r[y][x]);
	score = 0;
	if (x > 0)
		score += (filler->map[y][x-1] == 0);
	if (x < filler->w - 1)
		score += (filler->map[y][x+1] == 0);
	if (y > 0)
		score += (filler->map[y-1][x] == 0);
	if (y < filler->h - 1)
		score += (filler->map[y+1][x] == 0);
	return (score * filler->map[y][x]);
}

void	set_col_sig(t_filler *filler)
{
	int x;
	int y;
	int score;

	x = 0;
	while (x < filler->w)
	{
		y = 0;
		score = 0;
		while (y < filler->h)
		{
			if (filler->map[y][x] != 0)
			{
				score = 0;
				filler->sig_c[y][x] = filler->map[y][x];
			}
			else
			{
				if (score == 0)
					score = next_sig_in_col(filler->map, x, y, filler);
				filler->sig_c[y][x] = score;
			}
			y++;
		}
		x++;
	}
}

void	set_row_sig(t_filler *filler)
{
	int x;
	int y;
	int score;

	y = 0;
	while (y < filler->h)
	{
		x = 0;
		score = 0;
		while (x < filler->w)
		{
			if (filler->map[y][x] != 0)
			{
				score = 0;
				filler->sig_r[y][x] = filler->map[y][x];
			}
			else
			{
				if (score == 0)
					score = next_sig_in_row(filler->map, x, y, filler);
				filler->sig_r[y][x] = score;
			}
			x++;
		}
		y++;
	}
}

void	set_col_scores(t_filler *filler)
{
	int x;
	int y;
	int score;

	x = 0;
	while (x < filler->w)
	{
		y = 0;
		score = 0;
		while (y < filler->h)
		{
			if (filler->map[y][x] != 0)
			{
				score = 0;
				filler->col_sc[y][x] = 1;
			}
			else
			{
				if (score == 0)
					score = point_col_score(filler->map, x, y, filler);
				filler->col_sc[y][x] = score;
			}
			y++;
		}
		x++;
	}
}

void	set_row_scores(t_filler *filler)
{
	int x;
	int y;
	int score;

	y = 0;
	while (y < filler->h)
	{
		x = 0;
		score = 0;
		while (x < filler->w)
		{
			if (filler->map[y][x] != 0)
			{
				score = 0;
				filler->row_sc[y][x] = 1;
			}
			else
			{
				if (score == 0)
					score = point_row_score(filler->map, x, y, filler);
				filler->row_sc[y][x] = score;
			}
			x++;
		}
		y++;
	}
}

int		calc_score(char **map, t_filler *filler)
{
	set_row_sig(filler);
	set_col_sig(filler);
	set_row_scores(filler);
	set_col_scores(filler);
	/*int score1 = score(map, filler);
	if(score1 != calc_score2(filler->map, filler))
	{
		log_problem(filler);
		log_map("row sc", filler->row_sc, filler);
		log_map("col sc", filler->col_sc, filler);
		log_map_c("row sig", filler->sig_r, filler);
		log_map_c("col sig", filler->sig_c, filler);
	}*/
	return (score(map, filler));
}

void	clear_map(t_filler *filler, int y, int x)
{
	int i;
	int j;

	j = 0;
	while (j < filler->shape->h)
	{
		i = 0;
		while (i < filler->shape->w)
		{
			if (filler->shape->map[j][i] == 1)
			{
				if ((j+y != filler->a_y) || (i+x != filler->a_x))
				{
					filler->map[j+y][i+x] = 0;
					update_score(filler, j+y, i+x);
				}
			}
			i++;
		}
		j++;
	}
}

int		score_improves(t_filler *filler, int y, int x)
{
	int i;
	int j;
	int my_score;

	j = 0;
	while (j < filler->shape->h)
	{
		i = 0;
		while (i < filler->shape->w)
		{
			if ((filler->shape->map[j][i] == 1) && (filler->map[j+y][i+x] != 1))
			{
				if ((j+y != filler->a_y) || (i+x != filler->a_x))
				{
					filler->map[j+y][i+x] = 1;
					update_score(filler, j+y, i+x);
				}
			}
			i++;
		}
		j++;
	}
	//printf("%d %d\n",y,x );
	my_score = score(filler->map, filler);
	clear_map(filler, y, x);
	if ((my_score > filler->shape->score) || (filler->shape->x == -1))
	{
		filler->shape->score = my_score;
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
				filler->a_x = i+x;
				filler->a_y = j+y;
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

void	skip_turn(void)
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
	while (y <= y_end)
	{
		x = x_start;
		while (x <= x_end)
		{
			place_shape_if_possible(filler, y, x++);
		}
		y++;
	}
	if (filler->shape->x == -1)
		skip_turn();
	else
	{
		dprintf(1, "%d %d\n", (int) (filler->shape->y - filler->shape->y_off), (int) (filler->shape->x - filler->shape->x_off));
	}
	if (filler->op_stopped)
	{
		skip_turn();
		return ;
	}
}