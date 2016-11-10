/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bressenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:21:38 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/03 13:54:17 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_color(t_env *env, int x, int y)
{
	if (env->yc + 1 < env->y && env->xc + 1 < env->x)
	{
		if (env->color == 1)
			color1(env, x, y);
		else if (env->color == 2)
			color2(env, x, y);
		else
		{
			if (env->iso == 1)
				mlx_pixel_put(env->mlx, env->win, x + env->fix_x,
					y + env->fix_y, AZUR);
			else
				mlx_pixel_put(env->mlx, env->win, (x - y) + env->fix_x,
					((y + x) / env->iso) + env->fix_y, AZUR);
		}
	}
	else if (env->yc < env->y || env->xc < env->x)
	{
		if (env->color == 2)
			color2(env, x, y);
		else
			end_line_color(env, x, y);
	}
}

void	name_x(t_env *env)
{
	t_point		p1;
	t_point		p2;
	int			z;
	int			z2;

	env->yc = 0;
	env->xoy = 0;
	while (env->yc < env->y)
	{
		env->xc = 0;
		while (env->xc + 1 != env->x)
		{
			if (env->is == 1)
			{
				z = env->tab[env->yc][env->xc];
				z2 = env->tab[env->yc][env->xc + 1];
			}
			else
			{
				z = 0;
				z2 = 0;
			}
			env->color = 0;
			if (env->xc != 0)
			{
				p1.x = p2.x;
				p1.y = p2.y;
			}
			if (env->xc == 0)
			{
				p1.y = env->yc * env->up - z;
				p1.x = env->xc - z;
			}
			if (env->tab[env->yc][env->xc] > 0 &&
				env->tab[env->yc][env->xc + 1] > 0)
				env->color = 1;
			else if (env->tab[env->yc][env->xc] > 0 &&
				env->tab[env->yc][env->xc + 1] == 0)
				env->color = 2;
			else if (env->tab[env->yc][env->xc] == 0 &&
				env->tab[env->yc][env->xc + 1] > 0)
				env->color = 2;
			p2.x = (env->xc + 1) * env->up - z2;
			p2.y = env->yc * env->up - z2;
			ft_drawline(env, p1, p2);
			env->xc++;
		}
		env->yc++;
	}
}

void	name_y(t_env *env)
{
	t_point		p1;
	t_point		p2;
	int			z;
	int			z2;

	name_x(env);
	env->xc = 0;
	env->xoy = 1;
	while (env->xc < env->x)
	{
		env->yc = 0;
		while (env->yc + 1 != env->y)
		{
			if (env->is == 1)
			{
				z = env->tab[env->yc][env->xc];
				z2 = env->tab[env->yc + 1][env->xc];
			}
			else
			{
				z = 0;
				z2 = 0;
			}
			env->color = 0;
			if (env->yc != 0)
			{
				p1.x = p2.x;
				p1.y = p2.y;
			}
			if (env->yc == 0)
			{
				p1.x = env->xc * env->up - z;
				p1.y = env->yc - z;
			}
			if (env->tab[env->yc][env->xc] > 0 &&
				env->tab[env->yc + 1][env->xc] > 0)
				env->color = 1;
			else if (env->tab[env->yc][env->xc] > 0 &&
				env->tab[env->yc + 1][env->xc] == 0)
				env->color = 2;
			else if (env->tab[env->yc][env->xc] == 0 &&
				env->tab[env->yc + 1][env->xc] > 0)
				env->color = 2;
			p2.y = (env->yc + 1) * env->up - z2;
			p2.x = env->xc * env->up - z2;
			ft_drawline(env, p1, p2);
			env->yc++;
		}
		env->xc++;
	}
}
