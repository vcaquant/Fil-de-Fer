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

	int		tmpx;
	int		tmpy;
	int		tmp2x;
	int		tmp2y;

	char	*line;
}				t_env;

int				ft_error(int ac);
int				aff_key(int keycode);
int				aff_mouse(int mousecode);
void			ft_bhm_x(t_env *env, int xend, int yend);
void			ft_bhm_y(t_env *env, int xend, int yend);
void			ft_while_x(t_env *env, int tmpx, int tmpy);
void			ft_while_y(t_env *env, int tmpx, int tmpy);
void			ft_recup(t_env *env);
void			ft_print_points(t_env *env);

#endif
