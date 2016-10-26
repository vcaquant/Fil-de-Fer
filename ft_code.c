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

void 	delete(t_env *env)
{
	int		x;
	int		y;
	int		y2;
	int		xend;
	int		yend;

	y = 0;
	y2 = y + 1;
	xend = W_X;
	yend = W_Y;
	while (y <= yend)
	{
		x = 0;
		while (x <= xend)
		{
			mlx_pixel_put(env->mlx, env->win, x, y, WHITE);
			x++;
		}
		y++;
	}
}

void	truc(t_env *env, int keycode)
{
	int i;
	int	j;

	j = 0;
	delete(env);
	if (keycode == 40)
	{
		while (j < env->y)
		{
			i = 0;
			while (i < env->x)
			{
				if (env->tab[j][i] > 0 || env->tab[j][i] < 0)
					env->tab[j][i] += 11;
				i++;
			}
			j++;
		}
	}
	if (keycode == 46)
	{
		while (j < env->y)
		{
			i = 0;
			while (i < env->x)
			{
				if (env->tab[j][i] > 0 || env->tab[j][i] < 0)
					env->tab[j][i] -= 11;
				i++;
			}
			j++;
		}
	}
	ft_while_y(env);
}

void 	machin(t_env *env, int keycode)
{
	//delete(env);
	if (keycode == 124)
		env->fix_x += 10;
	else if (keycode == 123)
		env->fix_x -= 10;
	else if (keycode == 125)
		env->fix_y += 10;
	else if (keycode == 126)
		env->fix_y -= 10;
	mlx_string_put(env->mlx, env->win, 0, 0, ABSINTHE, "deplacement vers la droite");
	ft_while_y(env);
}

void 	zoom(t_env *env, int keycode)
{
	if (keycode == 24)
		env->up += 2;
	else if (keycode == 27)
		env->up -= 2;
	ft_while_y(env);
}

int		aff_key(int keycode, t_env *env)
{
	ft_putstr("touche");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 13 || keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 40 || keycode == 46)
		truc(env, keycode);
	if (keycode >= 123 && keycode <= 126)
	{
		delete(env);
		machin(env, keycode);
	}
	if (keycode == 24 || keycode == 27)
		zoom(env, keycode);
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
