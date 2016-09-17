/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:19:06 by vcaquant          #+#    #+#             */
/*   Updated: 2016/09/17 04:10:04 by vcaquant         ###   ########.fr       */
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
	int		xc;
	int		xc2;
	int		yc;
	int		**tab;
	int		tmpx;
	int		tmpy;
	int		tmp2x;
	int		tmp2y;
	int		test;
	int		zoom;
	int		i;

	env = NULL;
	tab = malloc(sizeof(*tab) * 20);
	i = 0;
	zoom = 20;
	test = ft_error(ac);
	if (test == -1)
		return (-1);
	while (i < 20)
	{
		tab[i] = malloc(sizeof(**tab) * 50);
		i++;
	}
	yc = 0;
	(void)ac;
	if (!ft_init_struct(&env, av))
		return (-1);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, W_X, W_Y, "FDF_42");
	while ((env->ret = get_next_line((int const)env->fd, &env->line)) > 0)
	{
		xc = 0;
		xc2 = 0;
		while (env->line[xc2])
		{
			while (env->line[xc2] == ' ')
				xc2++;
			tab[yc][xc] = ft_atoi(&env->line[xc2]);
			ft_debug(tab, xc, yc);
			xc++;
			xc2++;
			if (env->line[xc2] >= '0' && env->line[xc2] <= '9')
				xc2++;
		}
		ft_putstr("passe\n");
		yc++;
	}
	tmpx = xc;
	tmpy = yc;
	yc = 0;
	while (yc != tmpy)
	{
		xc = 0;
		while (xc != tmpx)
		{
			tmp2x = xc;
			tmp2y = (yc * zoom) - tab[yc][xc];
			if (xc != 0)
				tmp2x = xc * zoom;
			if (tab[yc][xc] == 10)
				mlx_pixel_put(env->mlx, env->win, tmp2x, tmp2y, 0x0000FF);
			else
				mlx_pixel_put(env->mlx, env->win, tmp2x, tmp2y, 0xFFFFFF);
			xc++;
			ft_putstr("\033[032;32m1\033[0m");
		}
		yc++;
		ft_putstr("\033[032;31m0\033[0m");
	}
	ft_putchar('\n');
	ft_while_x(env, xc, yc, tmpx, tmpy);
	ft_while_y(env, xc, yc, tmpx, tmpy);
	mlx_key_hook(env->win, aff_key, env->mlx);
	mlx_mouse_hook(env->win, aff_mouse, env->mlx);
	mlx_loop(env->mlx);
}
