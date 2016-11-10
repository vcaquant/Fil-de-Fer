/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:37:01 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/10 13:48:28 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		aff_help_exit(int keycode, t_env *env)
{
	if (keycode == 12 || keycode == 53)
	{
		ft_putstr("\033[0;32mHelp Closed\033[0m\n");
		mlx_destroy_window(env->mlx, env->s_win);
		env->s_win = NULL;
	}
	return (0);
}

void	write_command(t_env *env)
{
	mlx_string_put(env->mlx, env->s_win, 0, 105, WHITE,
		"> = Deplacement de la map vers la droite");
	mlx_string_put(env->mlx, env->s_win, 0, 120, WHITE,
		"< = Deplacement de la map vers la gauche");
	mlx_string_put(env->mlx, env->s_win, 0, 135, WHITE,
		"^ = Deplacement de la map vers le haut");
	mlx_string_put(env->mlx, env->s_win, 0, 150, WHITE,
		"v = Deplacement de la map vers le bas");
	mlx_string_put(env->mlx, env->s_win, 0, 215, WHITE, "+ = Zoom");
	mlx_string_put(env->mlx, env->s_win, 0, 230, WHITE, "- = Dezoom");
	mlx_string_put(env->mlx, env->s_win, 0, 295, WHITE,
		"K = Augmentation des Z");
	mlx_string_put(env->mlx, env->s_win, 0, 310, WHITE, "M = Diminution des Z");
	mlx_string_put(env->mlx, env->s_win, 0, 375, WHITE,
		"I = Mettre ou enlever isometrie");
	mlx_string_put(env->mlx, env->s_win, 0, 390, WHITE,
		"O = Augmenter l'isometrie");
	mlx_string_put(env->mlx, env->s_win, 0, 405, WHITE,
		"P = Baisser l'isometrie");
}

void	write_title1(t_env *env)
{
	mlx_string_put(env->mlx, env->s_win, 0, 0, ABSINTHE,
		" ===========================================");
	mlx_string_put(env->mlx, env->s_win, 0, 15, ABSINTHE,
		"|                    HELP                   |");
	mlx_string_put(env->mlx, env->s_win, 0, 30, ABSINTHE,
		" ===========================================");
	mlx_string_put(env->mlx, env->s_win, 0, 60, AZUR,
		" ===================================");
	mlx_string_put(env->mlx, env->s_win, 0, 75, AZUR,
		"|           Deplacements            |");
	mlx_string_put(env->mlx, env->s_win, 0, 90, AZUR,
		" ===================================");
}

void	write_title2(t_env *env)
{
	mlx_string_put(env->mlx, env->s_win, 0, 170, AZUR,
		" ===================================");
	mlx_string_put(env->mlx, env->s_win, 0, 185, AZUR,
		"|               Zoom                |");
	mlx_string_put(env->mlx, env->s_win, 0, 200, AZUR,
		" ===================================");
	mlx_string_put(env->mlx, env->s_win, 0, 250, AZUR,
		" ===================================");
	mlx_string_put(env->mlx, env->s_win, 0, 265, AZUR,
		"|      Variations de la hauteur     |");
	mlx_string_put(env->mlx, env->s_win, 0, 280, AZUR,
		" ===================================");
	mlx_string_put(env->mlx, env->s_win, 0, 330, AZUR,
		" ===================================");
	mlx_string_put(env->mlx, env->s_win, 0, 345, AZUR,
		"|             Isometrie             |");
	mlx_string_put(env->mlx, env->s_win, 0, 360, AZUR,
		" ===================================");
}

void	aff_help(t_env *env)
{
	env->s_win = mlx_new_window(env->mlx, 450, 450, "HELP_FDF");
	write_command(env);
	write_title1(env);
	write_title2(env);
	mlx_key_hook(env->s_win, aff_help_exit, env);
}
