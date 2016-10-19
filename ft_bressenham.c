/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bressenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:21:38 by vcaquant          #+#    #+#             */
/*   Updated: 2016/30/17 16:46:30 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bhm_x(t_env *env, int xend, int yend)
{
	int		dx;
	int		dy;
	int		e;

	env->iso_x = 2;
	env->iso_y = 2;
	e = xend - env->tmp2x;
	dx = e * 2;
	dy = (yend - env->tmp2y) * 2;
	if (env->yend < env->tmp2y)
		dy = (env->tmp2y - yend) * 2;
	while (env->tmp2x <= xend)
	{
		ft_color(env);
		env->tmp2x++;
		if ((e = e - dy) <= 0)
		{
			if (env->yend > env->tmp2y)
				env->tmp2y++;
			else
				env->tmp2y--;
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
	if (env->xend < env->tmp2x)
		dx = (env->tmp2x - xend) * 2;
	while (env->tmp2y <= yend)
	{
		ft_color(env);
		env->tmp2y++;
		if ((e = e - dx) <= 0)
		{
			if (env->xend > env->tmp2x)
				env->tmp2x++;
			else
				env->tmp2x--;
			e = e + dy;
		}
	}
}

void	ft_while_x(t_env *env)
{
	env->yc = 0;
	while (env->yc < env->y)
	{
		env->xc = 0;
		while (env->xc + 1 != env->x)
		{
			env->color = 0;
			env->yend = env->yc * 30;
			env->xend = (env->xc + 1) * 30;
			env->tmp2x = env->xc - env->tab[env->yc][env->xc];
			env->tmp2y = env->yc * 30 - env->tab[env->yc][env->xc];
			if (env->tab[env->yc][env->xc] > env->tab[env->yc][env->xc + 1])
				env->color = 1;
			if (env->xc != 0)
				env->tmp2x = env->xc * 30 - env->tab[env->yc][env->xc];
			if (env->tab[env->yc][env->xc + 1] == env->tab[env->yc][env->xc]
				&& env->tab[env->yc][env->xc] != 0)
			{
				env->yend = ((env->yc + 1) * 30) - env->tab[env->yc][env->xc] * 4;
				env->color = 1;
			}
			else if (env->tab[env->yc][env->xc + 1] > env->tab[env->yc][env->xc])
			{
				env->yend = (env->yc * 30) - env->tab[env->yc][env->xc + 1];
				env->xend = ((env->xc + 1) * 30) - env->tab[env->yc][env->xc + 1];
				env->color = 1;
			}
			ft_bhm_x(env, env->xend, env->yend);
			env->xc++;
		}
		env->yc++;
	}
}

void	ft_while_y(t_env *env)
{
	ft_while_x(env);
	env->xc = 0;
	while (env->xc != env->x)
	{
		env->yc = 0;
		while (env->yc + 1 != env->y)
		{
			env->color = 0;
			env->xend = env->xc * 30;
			env->yend = (env->yc + 1) * 30;
			env->tmp2y = env->yc - env->tab[env->yc][env->xc];
			env->tmp2x = env->xc * 30 - env->tab[env->yc][env->xc];
			if (env->tab[env->yc][env->xc] > env->tab[env->yc + 1][env->xc])
				env->color = 1;
			if (env->yc != 0)
				env->tmp2y = env->yc * 30 - env->tab[env->yc][env->xc];
			if (env->tab[env->yc + 1][env->xc] == env->tab[env->yc][env->xc]
				&& env->tab[env->yc][env->xc] != 0)
			{
				env->color = 1;
				env->xend = ((env->xc + 1) * 30) - env->tab[env->yc][env->xc] * 4;
			}
			else if (env->tab[env->yc + 1][env->xc] > env->tab[env->yc][env->xc])
			{
				env->color = 1;
				env->yend = ((env->yc + 1) * 30) - env->tab[env->yc + 1][env->xc];
				env->xend = ((env->xc) * 30) - env->tab[env->yc + 1][env->xc];
			}
			ft_bhm_y(env, env->xend, env->yend);
			env->yc++;
		}
		env->xc++;
	}
}
