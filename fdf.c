/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:19:06 by vcaquant          #+#    #+#             */
/*   Updated: 2016/09/21 18:43:55 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_init_struct(t_env **env, char **av)
{
	int		i;

	i = 0;
	if (!(*env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	(*env)->fd = open(av[1], O_RDONLY);
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
	env->i = 0;
	env->tab = (int**)malloc(sizeof(int*) * (env->i + 1));
	/*while (env->i < 20)
	{
		env->tab[env->i] = malloc(sizeof(**env->tab) * 50);
		env->i++;
	}*/
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, W_X, W_Y, "FDF_42");
	ft_recup(env);
	ft_while_y(env);
	mlx_key_hook(env->win, aff_key, env);
	mlx_mouse_hook(env->win, aff_mouse, env);
	mlx_loop(env->mlx);
}
