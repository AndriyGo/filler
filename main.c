//
//  main.c
//  filler
//
//  Created by Andriy Gordiychuk on 18/10/2018.
//  Copyright © 2018 Glenmax Ltd. All rights reserved.
//

#import "libft/libft.h"
#import "filler.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdarg.h>

void	ft_log(char *msg, ...)
{
	va_list	args;
	FILE	*log_file;

	log_file = fopen("logs.txt", "a+");
		va_start(args, msg);
		vfprintf(log_file, msg, args);
		va_end(args);
		fclose(log_file);
}

void log_line(char *s)
{
}

int 	main(int argc, const char * argv[]) {
	char		*line;
	char		*line2;
	int			i;
	int         me;
	t_filler	*filler;

	get_next_line(0, &line);
	me = line[10] - '0';
	ft_strdel(&line);
	while (get_next_line(0, &line) > 0)
	{
		if ((line[1] == 'l') || (line[1] == 'i'))
		{
			i = 0;
			if (line[1] == 'l')
			{
				filler = init_filler();
				filler->me = (me == 1) ? 'O' : 'X';
				filler->enemy = (me == 1) ? 'X' : 'O';
				init_maps(filler, ft_atoi(line + 8), ft_atoi(ft_strrchr(line, ' ')));
			}
			else
			{
				init_shape(filler, ft_atoi(line + 6), ft_atoi(ft_strrchr(line, ' ')));
			}
		}
		else if (ft_isdigit(line[0]))
		{
			fill_map_line(filler, i++, line);
			if (i == filler->h)
				calc_map(filler);
		}
		else if (line[0] != ' ')
		{
			fill_shape_line(filler, i++, line);
			if (i >= filler->shape->h)
				release_filler(&filler);
		}
		ft_strdel(&line);
	}
    return (0);
}
