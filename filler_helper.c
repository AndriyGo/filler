#import "filler.h"
#import "libft/libft.h"

t_filler	*init_filler()
{
	t_filler	*ret;

	ret = ft_memalloc(sizeof(t_filler));
	ret->rect = ft_memalloc(sizeof(t_rect));
	ret->shape = NULL;
	ret->map = NULL;
	ret->shape = ft_memalloc(sizeof(t_shape));
	ret->shape->map = NULL;
	return (ret);
}

void		init_maps(t_filler *filler, int h, int w)
{
	int	y;

	if (filler->map != NULL)
	{
		y = 0;
		while (y < filler->h)
			free(filler->map[y++]);
		free(filler->map);
	}
	filler->map = ft_memalloc(h * sizeof(char *));
	y = 0;
	while (y < h)
	{
		filler->map[y++] = ft_memalloc(w * sizeof(char));
	}
	filler->w = w;
	filler->h = h;
	filler->rect->x0 = w;
	filler->rect->x1 = 0;
	filler->rect->y0 = h;
	filler->rect->y1 = 0;
}

void		fill_map_line(t_filler *filler, int hi, char *line)
{
	int		w;
	int		i;

	w = filler->w;
	i = 0;
	while (i < w)
	{
		if (line[i + 4] == '.')
			filler->map[hi][i] = 0;
		else if (ft_toupper(line[i + 4]) == filler->me)
			filler->map[hi][i] = 1;
		else
			filler->map[hi][i] = -1;
		i++;
	}
}

void		calc_map(t_filler *filler)
{
	int		x;
	int		y;

	x = 0;
	while (x < filler->w)
	{
		y = 0;
		while (y < filler->h)
		{
			if (filler->map[y][x] == 1)
			{
				if (x < filler->rect->x0)
					filler->rect->x0 = x;
				if (x > filler->rect->x1)
					filler->rect->x1 = x;
				if (y < filler->rect->y0)
					filler->rect->y0 = y;
				if (y > filler->rect->y1)
					filler->rect->y1 = y;
			}
			y++;
		}
		x++;
	}
}






























