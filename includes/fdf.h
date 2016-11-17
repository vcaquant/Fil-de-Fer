/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 16:49:27 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/15 15:57:13 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define W_X 1200
# define W_Y 800
# define FIX_Y 80
# define FIX_X 450

# define BLACK		0x000000
# define WHI		0xFFFFFF
# define AZUR		0x74D0F1
# define AZUR_F		0x1E7FCB
# define ABSINTHE	0x7FDD4C
# define RED		0x00FF0000
# define BRO		0x00996600
# define G_P		0x0099FF00
# define G_F		0x0000CC00
# define Y_P		0x00CCCC66

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "../libft/get_next_line.h"

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*s_win;
	int		**tab;
	int		ret;
	int		fd;

	int		x;
	int		y;
	int		z;
	int		z2;
	int		xc;
	int		xc2;
	int		yc;
	int		color;

	int		i;
	int		is;
	double	iso;
	int		fix_x;
	int		fix_y;
	int		up;

	int		endx;
	int		endy;
	int		xend;
	int		yend;

	char	*line;
}				t_env;

typedef struct	s_drawline
{
	double		dx;
	double		dy;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		z1;
	double		z2;
	double		e;
}				t_drawline;

int				ft_init_struct(t_env **env, char **av);
t_point			init_point(t_point p1, t_point p2, int xory);

int				ft_error(int ac);
int				ft_map_not_valid(void);
void			too_much_help(t_env *env);
void			inc_z(t_env *env);
void			low_z(t_env *env);

int				ft_count_x(char *str);
int				ft_init_tab(t_env *env, char **av);
int				*ft_recupline(char *str);
void			ft_recup(t_env *env);

void			color1(t_env *env, int x, int y);
void			color2(t_env *env, int x, int y);
void			aff_color1(t_env *env, int x, int y);
void			aff_color2(t_env *env, int x, int y);
void			end_line_color(t_env *env, int x, int y);

void			write_end_color(t_env *env, int x, int y);
void			write_end_color_iso(t_env *env, int x, int y);
int				aff_key(int keycode, t_env *env);
void			zoom(t_env *env, int keycode);
void			move(t_env *env, int keycode);
void			var_z(t_env *env, int keycode);
void			iso(t_env *env, int keycode);

int				aff_help_exit(int keycode, t_env *env);
void			write_command(t_env *env);
void			write_title1(t_env *env);
void			write_title2(t_env *env);
void			aff_help(t_env *env);

void			ft_drawline(t_env *env, t_point p1, t_point p2);
void			cadran1_a(t_drawline *draw, t_env *env);
void			cadran1_b(t_drawline *draw, t_env *env);
void			cadran2_a(t_drawline *draw, t_env *env);
void			cadran2_b(t_drawline *draw, t_env *env);
void			cadran3_a(t_drawline *draw, t_env *env);
void			cadran3_b(t_drawline *draw, t_env *env);
void			cadran4_a(t_drawline *draw, t_env *env);
void			cadran4_b(t_drawline *draw, t_env *env);
void			dx_null_a(t_drawline *draw, t_env *env);
void			dx_null_b(t_drawline *draw, t_env *env);
void			dy_null_a(t_drawline *draw, t_env *env);
void			dy_null_b(t_drawline *draw, t_env *env);

void			name_x(t_env *env);
void			name_y(t_env *env);
void			while_x(t_env *env);
void			while_y(t_env *env);
void			ft_color(t_env *env, int x, int y);

int				ft_ex1(t_env *env);
int				ft_ex2(t_env *env);
int				ft_ex3(t_env *env);
int				ft_ex4(t_env *env);

#endif
