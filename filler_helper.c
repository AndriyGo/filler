#import "filler.h"
#import "libft/libft.h"

int		init_filler(t_filler **ret)
{
	if ((*ret = ft_memalloc(sizeof(t_filler))) == NULL)
		return (-1);
	if (((*ret)->rect = ft_memalloc(sizeof(t_rect))) == NULL)
		return (-1);
	if (((*ret)->shape = ft_memalloc(sizeof(t_shape))) == NULL)
		return (-1);
	(*ret)->map = NULL;
	(*ret)->shape->map = NULL;
	return (0);
}

int		init_maps(t_filler *filler, int h, int w)
{
	int	y;

	if ((h == 0) || (w == 0))
		return (-1);
	if (filler->map != NULL)
	{
		y = 0;
		while (y < filler->h)
			free(filler->map[y++]);
		free(filler->map);
	}
	if ((filler->map = ft_memalloc(h * sizeof(char *))) == NULL)
		return (-1);
	y = 0;
	while (y < h)
	{
		if ((filler->map[y++] = ft_memalloc(w * sizeof(char))) == NULL)
			return (-1);
	}
	filler->w = w;
	filler->h = h;
	filler->rect->x0 = w;
	filler->rect->x1 = 0;
	filler->rect->y0 = h;
	filler->rect->y1 = 0;
	return (0);
}

int			fill_map_line(t_filler *filler, int hi, char *line)
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
		else if (ft_toupper(line[i + 4]) == filler->enemy)
			filler->map[hi][i] = -1;
		else
			return (-1);
		i++;
	}
	if (i != w)
		return (-1);
	return (0);
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






























