/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:19:06 by vcaquant          #+#    #+#             */
/*   Updated: 2016/09/18 15:46:56 by vcaquant         ###   ########.fr       */
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
	int		zoom;

	test = ft_error(ac);
	if (test == -1)
		return (-1);
	if (!ft_init_struct(&env, av))
		return (-1);
	zoom = 20;
	env->yc = 0;
	(void)ac;
	env->i = 0;
	env->tab = malloc(sizeof(*env->tab) * 20);
	while (env->i < 20)
	{
		env->tab[env->i] = malloc(sizeof(**env->tab) * 50);
		env->i++;
	}
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, W_X, W_Y, "FDF_42");
	while ((env->ret = get_next_line((int const)env->fd, &env->line)) > 0)
	{
		env->xc = 0;
		env->xc2 = 0;
		while (env->line[env->xc2])
		{
			while (env->line[env->xc2] == ' ')
				env->xc2++;
			env->tab[env->yc][env->xc] = ft_atoi(&env->line[env->xc2]);
			ft_debug(env->tab, env->xc, env->yc);
			env->xc++;
			env->xc2++;
			if (env->line[env->xc2] >= '0' && env->line[env->xc2] <= '9')
				env->xc2++;
		}
		ft_putchar('\n');
		env->yc++;
	}
	env->tmpx = env->xc;
	env->tmpy = env->yc;
	env->yc = 0;
	while (env->yc != env->tmpy)
	{
		env->xc = 0;
		while (env->xc != env->tmpx)
		{
			env->tmp2x = env->xc;
			env->tmp2y = (env->yc * zoom) - env->tab[env->yc][env->xc];
			if (env->xc != 0)
				env->tmp2x = env->xc * zoom;
			if (env->tab[env->yc][env->xc] == 10)
				mlx_pixel_put(env->mlx, env->win, env->tmp2x, env->tmp2y, 0x0000FF);
			else
				mlx_pixel_put(env->mlx, env->win, env->tmp2x, env->tmp2y, 0xFFFFFF);
			env->xc++;
			ft_putstr("\033[032;32m1\033[0m");
		}
		env->yc++;
		ft_putstr("\033[032;31m0\033[0m");
	}
	ft_putchar('\n');
	ft_while_x(env, env->tmpx, env->tmpy);
	ft_while_y(env, env->tmpx, env->tmpy);
	mlx_key_hook(env->win, aff_key, env->mlx);
	mlx_mouse_hook(env->win, aff_mouse, env->mlx);
	mlx_loop(env->mlx);
}
