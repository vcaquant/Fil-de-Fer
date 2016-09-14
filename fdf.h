#ifndef FDF_H
# define FDF_H

# define W_X 600
# define W_Y 450

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "libft/get_next_line.h"

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>

typedef struct 	s_env
{
	void		*mlx;
	void		*win;
	int			ret;
	int			fd;
	int			x;
	int			y;
	char		*line;
	int 		p;
}								t_env;

int 	ft_error(int ac);
int 	aff_key(int keycode);
int 	aff_mouse(int mousecode);
void 	ft_bresenham_x(t_env *env, int xstart, int ystart, int xend, int yend);
void 	ft_bresenham_y(t_env *env, int xstart, int ystart, int xend, int yend);
void 	ft_while_x(t_env *env, int xc, int yc, int tmpx, int tmpy);
void 	ft_while_y(t_env *env, int xc, int yc, int tmpx, int tmpy);

#endif
