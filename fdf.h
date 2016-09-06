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
}				t_env;

#endif
