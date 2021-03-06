/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:19:06 by vcaquant          #+#    #+#             */
/*   Updated: 2016/10/31 15:41:01 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_init_struct(t_env **env, char **av)
{
	int		i;
	char	*str;

	i = 0;
	str = av[1];
	if (!(*env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	(*env)->fix_x = 200;
	(*env)->fix_y = 80;
	(*env)->iso = 1;
	(*env)->up = 10;
	(*env)->is = 0;
	(*env)->s_win = NULL;
	return (1);
}

t_point	init_point(t_point p1, t_point p2, int xory)
{
	if (xory != 0)
	{
		p1.x = p2.x;
		p1.y = p2.y;
	}
	return (p1);
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
	env->i = 0;
	while (env->i < env->y)
		env->tab[env->i++] = (int*)malloc(sizeof(int) * env->x);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, W_X, W_Y, "FDF_42");
	ft_recup(env);
	name_y(env);
	mlx_hook(env->win, 2, 0, aff_key, env);
	mlx_loop(env->mlx);
	return (0);
}
