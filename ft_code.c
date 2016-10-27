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

void	truc(t_env *env, int keycode)
{
	int i;
	int	j;

	j = 0;
	mlx_clear_window(env->mlx, env->win);
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
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 124)
		env->fix_x += 10;
	else if (keycode == 123)
		env->fix_x -= 10;
	else if (keycode == 125)
		env->fix_y += 10;
	else if (keycode == 126)
		env->fix_y -= 10;
	ft_while_y(env);
}

int 	zoom(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 24)
		env->up += 2;
	else if (keycode == 27)
		env->up -= 2;
	ft_while_y(env);
	return (0);
}

int		aff_key(int keycode, t_env *env)
{
	ft_putstr("touche");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 4)
	{
		ft_putstr("\033[0;33mOpen Help\033[0m\n");
		aff_help(env);
	}
	if (keycode == 12 || keycode == 53)
	{
		ft_putstr("\033[0;32mFdF Closed\033[0m\n");
		exit(EXIT_SUCCESS);
	}
	if (keycode == 40 || keycode == 46)
		truc(env, keycode);
	if (keycode >= 123 && keycode <= 126)
		machin(env, keycode);
	if (keycode == 24 || keycode == 27)
		return(zoom(env, keycode));
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
