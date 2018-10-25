#import "filler.h"
#import "libft/libft.h"

void	release_filler(t_filler **filler)
{
	while ((*filler)->h-- > 0)
		free((*filler)->map[(*filler)->h]);
	free((*filler)->map);
	if ((*filler)->shape != NULL)
	{
		while ((*filler)->shape->h-- > 0)
			free((*filler)->shape->map[(*filler)->shape->h]);
		free((*filler)->shape->map);
		free((*filler)->shape);
	}
	free((*filler)->rect);
	free(*filler);
	*filler = NULL;
}

char **copy_map(t_filler *filler)
{
	char **ret;
	int y;
	int x;

	ret = ft_memalloc(filler->h * sizeof(char *));
	y = 0;
	while (y < filler->h)
	{
		ret[y] = ft_memalloc(filler->w * sizeof(char));
		x = 0;
		while (x < filler->w)
		{
			ret[y][x] = filler->map[y][x];
			x++;
		}
		y++;
	}
	return (ret);
}

void	init_shape(t_filler *filler, int h, int w)
{
	if (filler->shape->map != NULL)
	{
		while (filler->shape->h-- > 0)
			free(filler->shape->map[filler->shape->h]);
		free(filler->shape->map);
	}
	filler->shape->h = h;
	filler->shape->w = w;
	filler->shape->x = -1;
	filler->shape->y = -1;
	filler->shape->x_off = w;
	filler->shape->y_off = h;
	filler->shape->score = 0;
	filler->shape->map = ft_memalloc(h * sizeof(char *));
	while (h-- > 0)
		filler->shape->map[h] = ft_memalloc(w * sizeof(char));
}

void	create_new_shape(t_filler *filler, int h, int w, int h_old)
{
	int x;
	int y;
	char **new;

	new = ft_memalloc(h * sizeof(char *));
	y = 0;
	while (y < h)
		new[y++] = ft_memalloc(w * sizeof(char));
	filler->shape->w = w;
	filler->shape->h = h;
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			new[y][x] = filler->shape->map[y + filler->shape->y_off][x + filler->shape->x_off];
			x++;
		}
		y++;
	}
	y = 0;
	while (y < h_old)
		free(filler->shape->map[y++]);
	free(filler->shape->map);
	filler->shape->map = new;
}

void	optimise_shape(t_filler *filler, int h, int w)
{
	int x;
	int h2;

	filler->shape->h = 0;
	filler->shape->w = 0;
	h2 = h;
	while (h-- > 0)
	{
		x = 0;
		while (x < w)
		{
			if (filler->shape->map[h][x] == 1)
			{
				if (x < filler->shape->x_off)
					filler->shape->x_off = x;
				if (h < filler->shape->y_off)
					filler->shape->y_off = h;
				if (x > filler->shape->w)
					filler->shape->w = x;
				if (h > filler->shape->h)
					filler->shape->h = h;
			}
			x++;
		}
	}
	create_new_shape(filler, filler->shape->h - filler->shape->y_off + 1, filler->shape->w - filler->shape->x_off + 1, h2);
	find_solution(filler);
}

void	fill_shape_line(t_filler *filler, int hi, char *line)
{
	int		w;
	int		i;

	w = filler->shape->w;
	i = 0;
	while (i < w)
	{
		if (line[i] == '.')
			filler->shape->map[hi][i] = 0;
		else 
			filler->shape->map[hi][i] = 1;
		i++;
	}
	if (hi == filler->shape->h - 1)
		optimise_shape(filler, filler->shape->h, filler->shape->w);
}
