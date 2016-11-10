/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:38:06 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/10 18:56:06 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	end_line_color(t_env *env, int x, int y)
{
	if (env->iso == 1)
		write_end_color(env, x, y);
	else
		write_end_color_iso(env, x, y);
}

void	aff_color1(t_env *env, int x, int y)
{
	if (ft_ex1(env) == 1)
		mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, G_P);
	else if (ft_ex2(env) == 1)
		mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, G_F);
	else if (ft_ex3(env) == 1)
		mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, Y_P);
	else if (ft_ex4(env) == 1)
		mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, BRO);
	else
		mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, WHI);
}

void	aff_color2(t_env *env, int x, int y)
{
	if (ft_ex1(env) == 1)
		mlx_pixel_put(env->mlx, env->win, (x - y) + env->fix_x,
				((y + x) / env->iso) + env->fix_y, G_P);
	else if (ft_ex2(env) == 1)
		mlx_pixel_put(env->mlx, env->win, (x - y) + env->fix_x,
				((y + x) / env->iso) + env->fix_y, G_F);
	else if (ft_ex3(env) == 1)
		mlx_pixel_put(env->mlx, env->win, (x - y) + env->fix_x,
				((y + x) / env->iso) + env->fix_y, Y_P);
	else if (ft_ex4(env) == 1)
		mlx_pixel_put(env->mlx, env->win, (x - y) + env->fix_x,
				((y + x) / env->iso) + env->fix_y, BRO);
	else
		mlx_pixel_put(env->mlx, env->win, (x - y) + env->fix_x,
				((y + x) / env->iso) + env->fix_y, WHI);
}

void	color2(t_env *env, int x, int y)
{
	if (env->iso == 1)
		mlx_pixel_put(env->mlx, env->win, x + env->fix_x, y + env->fix_y, RED);
	else
		mlx_pixel_put(env->mlx, env->win, (x - y) + env->fix_x,
				((y + x) / env->iso) + env->fix_y, RED);
}

void	color1(t_env *env, int x, int y)
{
	if (env->iso == 1)
		aff_color1(env, x, y);
	else
		aff_color2(env, x, y);
}
