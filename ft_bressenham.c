/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bressenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:21:38 by vcaquant          #+#    #+#             */
/*   Updated: 2016/10/23 06:44:07 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_color(t_env *env, int x, int y)
{
	if (env->yc + 1 < env->y && env->xc + 1 < env->x)
	{
		if (env->color == 1)
		{
			if (env->iso_y == 1)
			{
				if ((env->tab[env->yc][env->xc + 1] >= 1 && env->tab[env->yc][env->xc + 1] <= 10) || (env->tab[env->yc + 1][env->xc] >= 1 && env->tab[env->yc + 1][env->xc + 1] <= 10) || (env->tab[env->yc][env->xc] >= 1 && env->tab[env->yc][env->xc] <= 10))
					mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, AZUR);
				else if ((env->tab[env->yc][env->xc + 1] >= 11 && env->tab[env->yc][env->xc + 1] <= 30) || (env->tab[env->yc + 1][env->xc] >= 11 && env->tab[env->yc + 1][env->xc + 1] <= 20) || (env->tab[env->yc][env->xc] >= 11 && env->tab[env->yc][env->xc] <= 20))
					mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, AZUR_F);
				else if ((env->tab[env->yc][env->xc + 1] >= 31 && env->tab[env->yc][env->xc + 1] <= 40) || (env->tab[env->yc + 1][env->xc] >= 21 && env->tab[env->yc + 1][env->xc + 1] <= 30) || (env->tab[env->yc][env->xc] >= 21 && env->tab[env->yc][env->xc] <= 30))
					mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, ABSINTHE);
				else
					mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, WHITE);
			}
			else
			{
				if ((env->tab[env->yc][env->xc + 1] >= 1 && env->tab[env->yc][env->xc + 1] <= 10) || (env->tab[env->yc + 1][env->xc] >= 1 && env->tab[env->yc + 1][env->xc + 1] <= 10) || (env->tab[env->yc][env->xc] >= 1 && env->tab[env->yc][env->xc] <= 10))
					mlx_pixel_put(env->mlx, env->win, (x - y)  + env->fix_x, ((y + x) / env->iso_y) + env->fix_y, AZUR);
				else if ((env->tab[env->yc][env->xc + 1] >= 11 && env->tab[env->yc][env->xc + 1] <= 30) || (env->tab[env->yc + 1][env->xc] >= 11 && env->tab[env->yc + 1][env->xc + 1] <= 20) || (env->tab[env->yc][env->xc] >= 11 && env->tab[env->yc][env->xc] <= 20))
					mlx_pixel_put(env->mlx, env->win, (x - y)  + env->fix_x, ((y + x) / env->iso_y) + env->fix_y, AZUR_F);
				else if ((env->tab[env->yc][env->xc + 1] >= 31 && env->tab[env->yc][env->xc + 1] <= 40) || (env->tab[env->yc + 1][env->xc] >= 21 && env->tab[env->yc + 1][env->xc + 1] <= 30) || (env->tab[env->yc][env->xc] >= 21 && env->tab[env->yc][env->xc] <= 30))
					mlx_pixel_put(env->mlx, env->win, (x - y)  + env->fix_x, ((y + x) / env->iso_y) + env->fix_y, ABSINTHE);
				else
					mlx_pixel_put(env->mlx, env->win, (x - y)  + env->fix_x, ((y + x) / env->iso_y) + env->fix_y, WHITE);
			}
		}
		else
		{
			if (env->iso_y == 1)
				mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, WHITE);
			else
				mlx_pixel_put(env->mlx, env->win, (x - y)  + env->fix_x, ((y + x) / env->iso_y) + env->fix_y, WHITE);
		}
	}
	else if (env->yc < env->y || env->xc < env->x)
	{
		if (env->iso_y == 1)
			mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, WHITE);
		else
			mlx_pixel_put(env->mlx, env->win, (x - y)  + env->fix_x, ((y + x) / env->iso_y) + env->fix_y, WHITE);
	}
}

void	ft_while_x(t_env *env)
{
	t_point		p1;
	t_point		p2;

	env->yc = 0;
	while (env->yc < env->y)
	{
		env->xc = 0;
		while (env->xc + 1 != env->x)
		{
			env->color = 0;
			if (env->xc != 0)
			{
				env->tmp2x = env->xend;
				env->tmp2y = env->yend;
			}
			//env->xend = env->xc * env->up;
			env->xend = (env->xc + 1) * env->up;
			env->yend = env->yc * env->up;
			if (env->xc == 0)
			{
				env->tmp2x = env->xc - env->tab[env->yc][env->xc];
				env->tmp2y = env->yc * env->up - env->tab[env->yc][env->xc];
			}
			if (env->tab[env->yc][env->xc] > env->tab[env->yc][env->xc + 1])
				env->color = 1;
			if (env->xc == 1)
				env->tmp2x = env->xc * env->up - env->tab[env->yc][env->xc];
			if (env->tab[env->yc][env->xc + 1] == env->tab[env->yc][env->xc]
				&& env->tab[env->yc][env->xc] != 0)
			{
				env->yend = (env->yc * env->up) - env->tab[env->yc][env->xc];
				env->xend = ((env->xc + 1) * env->up) - env->tab[env->yc][env->xc];
				env->color = 1;
			}
			else if (env->tab[env->yc][env->xc + 1] > env->tab[env->yc][env->xc])
			{
				env->yend = (env->yc * env->up) - env->tab[env->yc][env->xc + 1];
				env->xend = ((env->xc + 1) * env->up) - env->tab[env->yc][env->xc + 1];
				env->color = 1;
			}
			if (env->tab[env->yc][env->xc] < 0)
			{
				env->yend = (env->yc * env->up) - env->tab[env->yc][env->xc + 1];
				env->xend = ((env->xc + 1) * env->up) - env->tab[env->yc][env->xc + 1];
			}
			if (env->tab[env->yc][env->xc + 1] < 0)
			{
				env->yend = (env->yc * env->up) - env->tab[env->yc][env->xc + 1];
				env->xend = ((env->xc + 1) * env->up) - env->tab[env->yc][env->xc + 1];
			}
			p1.x = env->tmp2x;
			p1.y = env->tmp2y;
			p2.x = env->xend;
			p2.y = env->yend;
			//printf("----\nx1 = %f y1 = %f\n----\nx2 = %f y2 = %f\n", p1.x, p1.y, p2.x, p2.y);
			ft_drawline(env, p1, p2);
			env->xc++;
		}
		env->yc++;
	}
}

void	ft_while_y(t_env *env)
{
	t_point		p1;
	t_point		p2;

	ft_while_x(env);
	env->xc = 0;
	while (env->xc != env->x)
	{
		env->yc = 0;
		while (env->yc + 1 != env->y)
		{
			env->color = 0;
			if (env->xc != 0)
			{
				env->tmp2x = env->xend;
				env->tmp2y = env->yend;
			}
			env->xend = env->xc * env->up;
			env->yend = (env->yc + 1) * env->up;
			if (env->tab[env->yc][env->xc] > env->tab[env->yc + 1][env->xc])
				env->color = 1;
			if (env->yc == 0)
			{
				env->tmp2y = env->yc - env->tab[env->yc][env->xc];
				env->tmp2x = env->xc * env->up - env->tab[env->yc][env->xc];
			}
			if (env->yc == 1)
				env->tmp2y = env->yc * env->up - env->tab[env->yc][env->xc];
			if (env->tab[env->yc + 1][env->xc] == env->tab[env->yc][env->xc]
				&& env->tab[env->yc][env->xc] != 0)
			{
				env->color = 1;
				env->xend = ((env->xc) * env->up) - env->tab[env->yc][env->xc];
				env->yend = ((env->yc + 1) * env->up) - env->tab[env->yc][env->xc];
			}
			else if (env->tab[env->yc + 1][env->xc] > env->tab[env->yc][env->xc])
			{
				env->color = 1;
				env->yend = ((env->yc + 1) * env->up) - env->tab[env->yc + 1][env->xc];
				env->xend = ((env->xc) * env->up) - env->tab[env->yc + 1][env->xc];
			}
			if (env->tab[env->yc][env->xc] < 0)
			{
				//env->tmp2x = ((env->xc + 1) * env->up) - env->tab[env->yc][env->xc];
				//env->tmp2y = (env->yc * env->up) - env->tab[env->yc][env->xc];
				env->yend = ((env->yc + 1) * env->up) - env->tab[env->yc][env->xc + 1];
				env->xend = (env->xc * env->up) - env->tab[env->yc][env->xc + 1];
			}
			p1.x = env->tmp2x;
			p1.y = env->tmp2y;
			p2.x = env->xend;
			p2.y = env->yend;
			ft_drawline(env, p1, p2);
			env->yc++;
		}
		env->xc++;
	}
}
