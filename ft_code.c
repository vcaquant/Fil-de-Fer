/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_code.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 16:46:57 by vcaquant          #+#    #+#             */
/*   Updated: 2016/09/21 18:45:52 by vcaquant         ###   ########.fr       */
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
		env->iso_x = env->iso_x + 10;
	}
	mlx_loop(env->mlx);
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
	if (env->tab[env->yc][env->xc] >= 5 && env->tab[env->yc][env->xc] <= 15)
		mlx_pixel_put(env->mlx, env->win, ((env->tmp2x - env->tmp2y)) + FIX_X, ((env->tmp2y + env->tmp2x) / env->iso_y) + FIX_Y, AZUR);
	else if (env->tab[env->yc][env->xc] >= 16 && env->tab[env->yc][env->xc] <= 25)
		mlx_pixel_put(env->mlx, env->win, ((env->tmp2x - env->tmp2y)) + FIX_X, ((env->tmp2y + env->tmp2x) / env->iso_y) + FIX_Y, AZUR_F);
	else if (env->tab[env->yc][env->xc] >= 26 && env->tab[env->yc][env->xc] <= 35)
		mlx_pixel_put(env->mlx, env->win, ((env->tmp2x - env->tmp2y)) + FIX_X, ((env->tmp2y + env->tmp2x) / env->iso_y) + FIX_Y, ABSINTHE);
	else
		mlx_pixel_put(env->mlx, env->win, ((env->tmp2x - env->tmp2y)) + FIX_X, ((env->tmp2y + env->tmp2x) / env->iso_y) + FIX_Y, WHITE);
}
