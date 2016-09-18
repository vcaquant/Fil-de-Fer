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

	e = xend - env->tmp2x;
	dx = e * 2;
	dy = (yend - env->tmp2y) * 2;
	while (env->tmp2x <= xend)
	{
		mlx_pixel_put(env->mlx, env->win, env->tmp2x, env->tmp2y, 0x00FFFFFF);
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
		mlx_pixel_put(env->mlx, env->win, env->tmp2x, env->tmp2y, 0x00FFFFFF);
		env->tmp2y++;
		if ((e = e - dx) <= 0)
		{
			env->tmp2x++;
			e = e + dy;
		}
	}
}

void	ft_while_x(t_env *env, int tmpx, int tmpy)
{
	int		xc;
	int		yc;

	yc = 0;
	while (yc != tmpy)
	{
		xc = 0;
		while (xc + 1 != tmpx)
		{
			env->tmp2x = xc;
			env->tmp2y = (yc * 20) - env->tab[yc][xc];
			if (xc != 0)
				env->tmp2x = xc * 20;
			ft_bhm_x(env, (xc + 1) * 20, yc * 20);
			xc++;
		}
		yc++;
	}
}

void	ft_while_y(t_env *env, int tmpx, int tmpy)
{
	int		xc;
	int		yc;

	ft_while_x(env, tmpx, tmpy);
	xc = 0;
	while (xc != tmpx)
	{
		yc = 0;
		while (yc + 1 != tmpy)
		{
			env->tmp2y = yc - env->tab[yc][xc];
			env->tmp2x = xc * 20;
			if (yc != 0)
				env->tmp2y = yc * 20;
			ft_bhm_y(env, xc * 20, (yc + 1) * 20);
			yc++;
		}
		xc++;
	}
}
