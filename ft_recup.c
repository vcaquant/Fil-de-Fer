/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 17:02:42 by vcaquant          #+#    #+#             */
/*   Updated: 2016/09/18 17:04:17 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_recup(t_env *env)
{
	int		**tmp;

	env->yc = 0;
	while ((env->ret = get_next_line((int const)env->fd, &env->line)) > 0)
	{
		tmp = env->tab;
		//if (env->yc != 0)
			env->tab = (int**)malloc(sizeof(int*) * (env->yc + 1));
		ft_memcpy(env->tab, tmp, sizeof(int*) * (env->yc));
		env->tab[env->yc] = (int*)malloc(sizeof(int) * (ft_count_x(env->line) + 1));
		//env->xc = 0;
		env->xc2 = 0;
		//while (env->line[env->xc2])
		//{
		env->tab[env->yc++] = ft_putline(env->line);
			/*while (env->line[env->xc2] == ' ')
				env->xc2++;
			if ((env->line[env->xc2] <= '9' && env->line[env->xc2] >= '0') || env->line[env->xc2] == '-')
			{
				env->tab[env->yc][env->xc] = ft_atoi(&env->line[env->xc2]);
				env->xc++;
			}
			while (env->line[env->xc2] != ' ' && env->line[env->xc2] != '\0')
				env->xc2++;*/
		//}
		env->yc++;
		free(tmp);
	}
	env->endx = ft_count_x(env->line);
	env->endy = env->yc;
	ft_print_points(env);
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
