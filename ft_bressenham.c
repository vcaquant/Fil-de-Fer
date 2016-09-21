/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bressenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:21:38 by vcaquant          #+#    #+#             */
/*   Updated: 2016/09/18 17:05:05 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bhm_x(t_env *env, int xend, int yend)
{
	int		dx;
	int		dy;
	int		e;

	env->iso_x = 1;
	env->iso_y = 1;
	e = xend - env->tmp2x;
	dx = e * 2;
	dy = (yend - env->tmp2y) * 2;
	while (env->tmp2x <= xend)
	{
		ft_color(env);
		env->tmp2x++;
		if ((e = e - dy) <= 0)
		{
			env->tmp2y++;
			e = e + dx;
		}
	}
}

void	ft_bhm_y(t_env *env, int xend, int yend)
{
	int		dx;
	int		dy;
	int		e;

	e = yend - env->tmp2y;
	dy = e * 2;
	dx = (xend - env->tmp2x) * 2;
	while (env->tmp2y <= yend)
	{
		ft_color(env);
		env->tmp2y++;
		if ((e = e - dx) <= 0)
		{
			env->tmp2x++;
			e = e + dy;
		}
	}
}

void	ft_while_x(t_env *env)
{
	env->yc = 0;
	while (env->yc != env->tmpy)
	{
		env->xc = 0;
		while (env->xc + 1 != env->tmpx)
		{
			env->tmp2x = env->xc;
			env->tmp2y = (env->yc * 20) - env->tab[env->yc][env->xc];
			if (env->xc != 0)
				env->tmp2x = env->xc * 20;
			ft_bhm_x(env, (env->xc + 1) * 20, env->yc * 20);
			//ft_bhm_x(env, env->tmp2x + 1, env->tmp2y);
			env->xc++;
		}
		env->yc++;
	}
}

void	ft_while_y(t_env *env)
{
	ft_while_x(env);
	env->xc = 0;
	while (env->xc != env->tmpx)
	{
		env->yc = 0;
		while (env->yc + 1 != env->tmpy)
		{
			env->tmp2y = env->yc - env->tab[env->yc][env->xc];
			env->tmp2x = env->xc * 20;
			if (env->yc != 0)
				env->tmp2y = env->yc * 20;
			ft_bhm_y(env, env->xc * 20, (env->yc + 1) * 20);
			//ft_bhm_y(env, env->tmp2x, env->tmp2y + 1);
			env->yc++;
		}
		env->xc++;
	}
}
