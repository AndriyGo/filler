//
//  main.c
//  filler
//
//  Created by Andriy Gordiychuk on 18/10/2018.
//  Copyright © 2018 Glenmax Ltd. All rights reserved.
//

#import "libft/libft.h"
#import "filler.h"

int		read_map(t_filler **filler, char me, char *line)
{
	char	*line2;
	int		h;
	int		i;

	if ((me == 0) || (ft_strchr(line, ' ') == NULL) || (ft_strrchr(line, ' ') == NULL))
		return (-1);
	if (init_filler(filler) == -1)
		return (-1);
	(*filler)->me = (me == 1) ? 'O' : 'X';
	(*filler)->enemy = (me == 1) ? 'X' : 'O';
	h = ft_atoi(ft_strchr(line, ' '));
	if (init_maps(*filler, h, ft_atoi(ft_strrchr(line, ' '))) == -1)
		return (-1);
	i = 0;
	while ((i < h) && (get_next_line(0, &line2) > 0))
	{
		if ((line2[0] != ' ') && (fill_map_line(*filler, i++, line2) == -1))
			return (-1);
		ft_strdel(&line2);
	}
	if ((i != h) || (i == 0))
		return (-1);
	if (line2 != NULL)
		ft_strdel(&line2);
	calc_map(*filler);
	return (0);
}

int		read_piece(t_filler **filler, char *line)
{
	char	*line2;
	int		h;
	int		i;

	if ((ft_strchr(line, ' ') == NULL) || (ft_strrchr(line, ' ') == NULL))
		return (-1);
	h = ft_atoi(ft_strchr(line, ' '));
	if (init_shape(*filler, h, ft_atoi(ft_strrchr(line, ' '))) == -1)
		return (-1);
	if (((*filler)->shape->h > (*filler)->h) || ((*filler)->shape->w > (*filler)->w))
		return (-1);
	i = 0;
	while ((i < h) && (get_next_line(0, &line2) > 0))
	{
		if (fill_shape_line(*filler, i++, line2) == -1)
			return (-1);
		ft_strdel(&line2);
	}
	if (i != h)
		return (-1);
	if (line2 != NULL)
		ft_strdel(&line2);
	release_filler(filler);
	return (0);
}

int 	main(int argc, const char * argv[])
{
	char		*line;
	int         me;
	int			i;
	t_filler	*filler;

	me = 0;
	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if ((i != -2) && (line[0] == '$'))
		{
			if (ft_strlen(line) < 11)
				i = -2;
			me = line[10] - '0';
			if ((me < 0) || (me > 2))
				i = -2;
			i--;
		}
		else if ((i != -2) && (i % 2 == 0) && (read_map(&filler, me, line) == -1))
			i = -2;
		else if ((i != -2) && (i % 2 == 1) && (read_piece(&filler, line) == -1))
			i = -2;
		i++;
		ft_strdel(&line);
	}
    return (0);
}
