/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:19:06 by vcaquant          #+#    #+#             */
/*   Updated: 2016/10/17 16:38:33 by vcaquant         ###   ########.fr       */
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
	//(*env)->fd = open(av[1], O_RDONLY);
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
	//env->tab = ft_memalloc(sizeof(int*) * (env->y + 1));
	env->tab[env->y] = NULL;
	printf("poulet\n");
	env->i = 0;
	while (env->i < env->y)
	{
		env->tab[env->i] = (int*)malloc(sizeof(int) * env->x);
		//env->tab[env->i] = ft_memalloc(sizeof(int) * env->x);
		(env->i)++;
	}
	//env->mlx = mlx_init();
	//env->win = mlx_new_window(env->mlx, W_X, W_Y, "FDF_42");
	ft_recup(env);
	ft_while_y(env);
	//mlx_key_hook(env->win, aff_key, env);
	//mlx_mouse_hook(env->win, aff_mouse, env);
	//mlx_loop(env->mlx);
	return (0);
}
