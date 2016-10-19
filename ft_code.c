/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_code.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 16:46:57 by vcaquant          #+#    #+#             */
/*   Updated: 2016/10/17 17:01:05 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		aff_key(int keycode, t_env *env)
{
	ft_putstr("touche");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 13 || keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 12)
	{
		env->fix_x--;
	}
	return (0);
}

int		aff_mouse(int mousecode)
{
	ft_putstr("souris");
	ft_putnbr(mousecode);
	ft_putchar('\n');
	if (mousecode == 1)
		ft_putstr("Arrete d'appuyer sur moi, ça ne fais rien !\n");
	return (0);
}

void	ft_color(t_env *env)
{
	env->fix_x = 350;
	env->fix_y = 80;
	if (env->yc + 1 < env->y && env->xc + 1 < env->x)
	{
		if (env->color == 1)
		//if ((env->tab[env->yc][env->xc + 1] >= 1 && env->tab[env->yc][env->xc + 1] <= 10) || (env->tab[env->yc + 1][env->xc] >= 1 && env->tab[env->yc + 1][env->xc + 1] <= 10) || (env->tab[env->yc][env->xc] >= 1 && env->tab[env->yc][env->xc] <= 10))
			mlx_pixel_put(env->mlx, env->win, ((env->tmp2x - env->tmp2y) + env->fix_x), ((env->tmp2y + env->tmp2x) / env->iso_y) + env->fix_y, AZUR);
		/*else if (env->tab[env->yc][env->xc] >= 120 && env->tab[env->yc][env->xc] <= 130)
			mlx_pixel_put(env->mlx, env->win, ((env->tmp2x - env->tmp2y)) + env->fix_x, ((env->tmp2y + env->tmp2x) / env->iso_y) + env->fix_y, AZUR_F);
		else if (env->tab[env->yc][env->xc] >= 26 && env->tab[env->yc][env->xc] <= 35)
			mlx_pixel_put(env->mlx, env->win, ((env->tmp2x - env->tmp2y)) + env->fix_x, ((env->tmp2y + env->tmp2x) / env->iso_y) + env->fix_y, ABSINTHE);*/
		else
			mlx_pixel_put(env->mlx, env->win, ((env->tmp2x - env->tmp2y) + env->fix_x), ((env->tmp2y + env->tmp2x) / env->iso_y) + env->fix_y, WHITE);
	}
	else if (env->yc < env->y || env->xc < env->x)
		mlx_pixel_put(env->mlx, env->win, ((env->tmp2x - env->tmp2y) + env->fix_x), ((env->tmp2y + env->tmp2x) / env->iso_y) + env->fix_y, WHITE);
}
