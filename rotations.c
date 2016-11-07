/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 13:42:49 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/23 19:42:46 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		apply_matrix(t_env *env)
{
	double x_tmp;
	double y_tmp;
	double tab_tmp;

	x_tmp = (env->xc * env->matrix->a1 + env->yc *
			env->matrix->b1 + env->tab[env->yc][env->xc] * env->matrix->c1);
	y_tmp = (env->xc * env->matrix->a2 + env->yc *
			env->matrix->b2 + env->tab[env->yc][env->xc] * env->matrix->c2);
	tab_tmp = (env->xc * env->matrix->a3 + env->yc *
			env->matrix->b3 + env->tab[env->yc][env->xc] * env->matrix->c3);
	env->xc++; //= x_tmp;
	mlx_pixel_put(env->mlx, env->win, x_tmp, y_tmp, WHITE);
	//= y_tmp;
}

static void		x_rotate(t_env *env, double teta)
{
	int i;

	i = 0;
	env->xc = 0;
	env->yc = 0;
	env->matrix->a1 = 1;
	ft_putstr("matrix\n");
	env->matrix->a2 = 0;
	env->matrix->a3 = 0;
	env->matrix->b1 = 0;
	env->matrix->b2 = cos(teta);
	env->matrix->b3 = -(sin(teta));
	env->matrix->c1 = 0;
	env->matrix->c2 = sin(teta);
	env->matrix->c3 = cos(teta);
	while (env->yc < env->y)
	{
		while (env->xc < env->x)
		{
			//env->xc -= (W_X / 3);
			//env->yc -= (W_Y / 3);
			apply_matrix(env);
			//env->xc += (W_X / 3);
			//env->yc += (W_Y / 3);
			//i++;
		}
		env->yc++;
	}
}

static void		y_rotate(t_env *env, double teta)
{
	int i;

	i = 0;
	env->matrix->a1 = cos(teta);
	env->matrix->a2 = 0;
	env->matrix->a3 = sin(teta);
	env->matrix->b1 = 0;
	env->matrix->b2 = 1;
	env->matrix->b3 = 0;
	env->matrix->c1 = -sin(teta);
	env->matrix->c2 = 0;
	env->matrix->c3 = cos(teta);
	while (i < env->x * env->y)
	{
		//env->xc -= (W_X / 3);
		//env->yc -= (W_Y / 3);
		apply_matrix(env);
		//env->xc += (W_X / 3);
		//env->yc += (W_Y / 3);
		i++;
	}
}

static void		z_rotate(t_env *env, double teta)
{
	int i;

	i = 0;
	env->matrix->a1 = cos(teta);
	env->matrix->a2 = -sin(teta);
	env->matrix->a3 = 0;
	env->matrix->b1 = sin(teta);
	env->matrix->b2 = cos(teta);
	env->matrix->b3 = 0;
	env->matrix->c1 = 0;
	env->matrix->c2 = 0;
	env->matrix->c3 = 1;
	while (i < env->x * env->y)
	{
		//env->xc -= (W_X / 3);
		//env->yc -= (W_Y / 3);
		apply_matrix(env);
		//env->xc += (W_X / 3);
		//env->yc += (W_Y / 3);
		i++;
	}
}

void			rotate_points(t_env *env, char axe, double teta)
{
	if (axe == 'x')
		x_rotate(env, teta);
	else if (axe == 'y')
		y_rotate(env, teta);
	else if (axe == 'z')
		z_rotate(env, teta);
}
