/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ex_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:54:43 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/10 18:54:45 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	write_end_color(t_env *env, int x, int y)
{
	if (env->tab[env->yc][env->xc] == 0)
		mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, AZUR);
	else if (env->tab[env->yc][env->xc] >= 1 &&
			env->tab[env->yc][env->xc] <= 10)
		mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, G_P);
	else if (env->tab[env->yc][env->xc] >= 11 &&
			env->tab[env->yc][env->xc] <= 20)
		mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, G_F);
	else if (env->tab[env->yc][env->xc] >= 21 &&
			env->tab[env->yc][env->xc] <= 30)
		mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, Y_P);
	else if (env->tab[env->yc][env->xc] >= 31 &&
			env->tab[env->yc][env->xc] <= 60)
		mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, BRO);
	else
		mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, WHI);
}

void	write_end_color_iso(t_env *env, int x, int y)
{
	if (env->tab[env->yc][env->xc] == 0)
		mlx_pixel_put(env->mlx, env->win, (x - y) + env->fix_x,
				((y + x) / env->iso) + env->fix_y, AZUR);
	else if (env->tab[env->yc][env->xc] >= 1 &&
			env->tab[env->yc][env->xc] <= 10)
		mlx_pixel_put(env->mlx, env->win, (x - y) + env->fix_x,
				((y + x) / env->iso) + env->fix_y, G_P);
	else if (env->tab[env->yc][env->xc] >= 11 &&
			env->tab[env->yc][env->xc] <= 20)
		mlx_pixel_put(env->mlx, env->win, (x - y) + env->fix_x,
				((y + x) / env->iso) + env->fix_y, G_F);
	else if (env->tab[env->yc][env->xc] >= 21 &&
			env->tab[env->yc][env->xc] <= 30)
		mlx_pixel_put(env->mlx, env->win, (x - y) + env->fix_x,
				((y + x) / env->iso) + env->fix_y, Y_P);
	else if (env->tab[env->yc][env->xc] >= 31 &&
			env->tab[env->yc][env->xc] <= 60)
		mlx_pixel_put(env->mlx, env->win, (x - y) + env->fix_x,
				((y + x) / env->iso) + env->fix_y, BRO);
	else
		mlx_pixel_put(env->mlx, env->win, (x - y) + env->fix_x,
				((y + x) / env->iso) + env->fix_y, WHI);
}
