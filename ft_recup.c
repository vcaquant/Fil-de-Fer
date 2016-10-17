/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 17:02:42 by vcaquant          #+#    #+#             */
/*   Updated: 2016/10/17 14:31:30 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*ft_recupline(char *str)
{
	int		*tab;
	int		columns;
	int		i;
	int		j;

	j = 0;
	if (!str || str[j] == '\n' || str[j] == '\0')
		return (NULL);
	columns = ft_count_x(str);
	if (str[j] == '\n' || columns == 0)
		return (NULL);
	tab = (int*)malloc(sizeof(int) * (columns + 1));
	i = 0;
	//tab[i++] = columns;
	while (str[j] != '\0' && str[j] != '\n')
	{
		while (str[j] == ' ')
			j++;
		if ((str[j] <= '9' && str[j] >= '0') || str[j] == '-')
		{
			tab[i] = ft_atoi(&str[j]);
			i++;
		}
		while (str[j] != '\0' && str[j] != '\n' && str[j] != ' ')
			j++;
	}
	return (tab);
}

void	ft_recup(t_env *env)
{
	env->yc = 0;
	while ((env->ret = get_next_line((int const)env->fd, &env->line)) > 0)
	{
		env->xc = 0;
		env->xc2 = 0;
		//env->tab[env->yc] = ft_recupline(env->line);
		while (env->line[env->xc2])
		{
			while (env->line[env->xc2] == ' ' && env->line[env->xc2])
				env->xc2++;
			if ((env->line[env->xc2] <= '9' && env->line[env->xc2] >= '0') || env->line[env->xc2] == '-')
			{
				env->tab[env->yc][env->xc] = ft_atoi(&env->line[env->xc2]);
				printf("%d\n", ft_atoi(env->line + env->xc2));
				env->xc++;
				printf("%d\n", env->tab[env->yc][env->xc - 1]);

			}
			while (env->line[env->xc2] != ' ' && env->line[env->xc2] != '\0')
				env->xc2++;
		}
		env->yc++;
		//env->endx = ft_count_x(env->line);
	}
	env->endy = env->yc;
//	ft_print_points(env);
}

void	ft_print_points(t_env *env)
{
	env->zoom = 20;
	env->yc = 0;
	while (env->yc != env->endy)
	{
		env->xc = 0;
		while (env->xc != env->endx)
		{
			env->tmp2x = env->xc;
			env->tmp2y = (env->yc * env->zoom) - env->tab[env->yc][env->xc];
			if (env->xc != 0)
				env->tmp2x = env->xc * env->zoom;
			//mlx_pixel_put(env->mlx, env->win, env->tmp2x, env->tmp2y, white);
			env->xc++;
		}
		env->yc++;
	}
}
