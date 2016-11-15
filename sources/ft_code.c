/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_code.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 16:46:57 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/15 12:44:51 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	iso(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (env->is == 0)
		env->is++;
	else
		env->is--;
	if (keycode == 34)
	{
		if (env->iso == 1)
			env->iso = 2;
		else
			env->iso = 1;
	}
	name_y(env);
}

void	var_z(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 40)
		inc_z(env);
	if (keycode == 46)
		low_z(env);
	name_y(env);
}

void	move(t_env *env, int keycode)
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
	name_y(env);
}

void	zoom(t_env *env, int keycode)
{
	mlx_clear_window(env->mlx, env->win);
	if (env->up > 9)
	{
		if (keycode == 24)
			env->up += 2 * (env->up / 10);
		else if (keycode == 27)
			env->up -= 2 * (env->up / 10);
	}
	else
	{
		if (keycode == 24)
			env->up += 2;
		else if (keycode == 27)
			env->up -= 2;
	}
	name_y(env);
}

int		aff_key(int keycode, t_env *env)
{
	ft_putstr("touche : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 4)
		too_much_help(env);
	if (keycode == 12 || keycode == 53)
	{
		ft_putstr("\033[0;32m✔︎ FdF Closed\033[0m\n");
		exit(EXIT_SUCCESS);
	}
	if (keycode == 40 || keycode == 46)
		var_z(env, keycode);
	if (keycode >= 123 && keycode <= 126)
		move(env, keycode);
	if (keycode == 24 || keycode == 27)
		zoom(env, keycode);
	if (keycode == 34)
		iso(env, keycode);
	return (0);
}
