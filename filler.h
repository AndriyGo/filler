#ifndef FILLER_H
# define FILLER_H
#include <stdio.h>
#include <unistd.h>
typedef struct	s_point
{
	double	x;
	double	y;
	int			m;
}				t_point;

typedef struct	s_shape
{
	int		w;
	int		h;
	int		x_off;
	int		y_off;
	char	**map;
	int		x;
	int		y;
	int		score;
}				t_shape;

typedef struct	s_rect
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
}				t_rect;

typedef struct	s_field
{
	int			w;
	int			h;
	char		**map;
	t_rect		*rect;
	t_point		*cm;
}				t_field;

typedef struct	s_filler
{
	char		enemy;
	char		me;
	char		**map;
	int			w;
	int			h;
	t_rect		*rect;
	t_shape		*shape;
}				t_filler;

int			init_filler(t_filler **ret);
int			init_maps(t_filler *filler, int h, int w);
int			fill_map_line(t_filler *filler, int hi, char *line);
void		calc_map(t_filler *filler);
void		my_log(char *s);
void		release_filler(t_filler **filler);
int			init_shape(t_filler *filler, int h, int w);
int			fill_shape_line(t_filler *filler, int hi, char *line);
char 		**copy_map(t_filler *filler);
void		find_solution(t_filler *filler);
void		release_map(t_field *field);

#endif