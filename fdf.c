/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:19:06 by vcaquant          #+#    #+#             */
/*   Updated: 2016/10/23 02:05:44 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_init_struct(t_env **env, char **av)
{
	int		i;
	char	*str;

	i = 0;
	str = av[1];
	if (!(*env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	return (1);
}

void	ft_debug(int **tab, int xc, int yc)
{
	ft_putnbr(tab[yc][xc]);
	if (tab[yc][xc] == 10 || tab[yc][xc] == 11 || tab[yc][xc] == 90)
		ft_putchar(' ');
	else
		ft_putstr("  ");
}

int		main(int ac, char **av)
{
	t_env	*env;
	int		test;

	test = ft_error(ac);
	if (test == -1)
		return (-1);
	if (!ft_init_struct(&env, av))
		return (-1);
	if (ft_init_tab(env, av) == -1)
		return (ft_map_not_valid());
	env->fd = open(av[1], O_RDONLY);
	env->tab = (int**)malloc(sizeof(int*) * (env->y + 1));
	env->tab[env->y] = NULL;
	env->fix_x = 200;
	env->fix_y = 80;
	env->iso_y = 1;
	env->up = 10;
	env->i = 0;
	env->s_win = NULL;
	while (env->i < env->y)
	{
		env->tab[env->i] = (int*)malloc(sizeof(int) * env->x);
		(env->i)++;
	}
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, W_X, W_Y, "FDF_42");
	ft_recup(env);
	ft_while_y(env);
	mlx_hook(env->win, 2, 0, aff_key, env);
	mlx_mouse_hook(env->win, aff_mouse, env);
	mlx_loop(env->mlx);
	return (0);
}
