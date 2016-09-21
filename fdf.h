/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 16:49:27 by vcaquant          #+#    #+#             */
/*   Updated: 2016/09/18 17:05:58 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define W_X 1100
# define W_Y 800

# define black 0x000000
# define white 0xFFFFFF
# define azur 0x74D0F1
# define azur_f 0x1E7FCB
# define absinthe 0x7FDD4C

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

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		**tab;
	int		ret;
	int		fd;

	int		xc;
	int		xc2;
	int		yc;

	int		p;
	int		i;
	int		zoom;
	double 	iso_x;
	double	iso_y;

	int		tmpx;
	int		tmpy;
	int		tmp2x;
	int		tmp2y;

	char	*line;
}				t_env;

int				ft_error(int ac);
int				aff_key(int keycode, t_env *env);
int				aff_mouse(int mousecode);
int 			aff_exp(t_env *env);
void			ft_bhm_x(t_env *env, int xend, int yend);
void			ft_bhm_y(t_env *env, int xend, int yend);
void			ft_while_x(t_env *env);
void			ft_while_y(t_env *env);
void			ft_recup(t_env *env);
void			ft_print_points(t_env *env);
void 			ft_color(t_env *env);

#endif
