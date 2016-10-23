/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bressenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:21:38 by vcaquant          #+#    #+#             */
/*   Updated: 2016/10/23 06:44:07 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_while_x(t_env *env)
{
	t_point		p1;
	t_point		p2;

	env->yc = 0;
	while (env->yc < env->y)
	{
		env->xc = 0;
		while (env->xc + 1 != env->x)
		{
			env->color = 0;
			if (env->xc != 0)
			{
				env->tmp2x = env->xend;
				env->tmp2y = env->yend;
			}
			//env->xend = env->xc * 30;
			env->xend = (env->xc + 1) * 30;
			env->yend = env->yc * 30;
			if (env->xc == 0)
			{
				env->tmp2x = env->xc - env->tab[env->yc][env->xc];
				env->tmp2y = env->yc * 30 - env->tab[env->yc][env->xc];
			}
			if (env->tab[env->yc][env->xc] > env->tab[env->yc][env->xc + 1])
				env->color = 1;
			if (env->xc == 1)
				env->tmp2x = env->xc * 30 - env->tab[env->yc][env->xc];
			if (env->tab[env->yc][env->xc + 1] == env->tab[env->yc][env->xc]
				&& env->tab[env->yc][env->xc] != 0)
			{
				env->yend = ((env->yc) * 30) - env->tab[env->yc][env->xc];
				env->xend = ((env->xc + 1) * 30) - env->tab[env->yc][env->xc];
				env->color = 1;
			}
			else if (env->tab[env->yc][env->xc + 1] > env->tab[env->yc][env->xc])
			{
				env->yend = (env->yc * 30) - env->tab[env->yc][env->xc + 1];
				//env->xend = ((env->xc) * 30) - env->tab[env->yc][env->xc + 1];
				env->xend = ((env->xc + 1) * 30) - env->tab[env->yc][env->xc + 1];
				env->color = 1;
			}
			p1.x = env->tmp2x;
			p1.y = env->tmp2y;
			p2.x = env->xend;
			p2.y = env->yend;
			//printf("----\nx1 = %f y1 = %f\n----\nx2 = %f y2 = %f\n", p1.x, p1.y, p2.x, p2.y);
			ft_drawline(env, p1, p2);
			env->xc++;
		}
		env->yc++;
	}
}

void	ft_while_y(t_env *env)
{
	t_point		p1;
	t_point		p2;

	ft_while_x(env);
	env->xc = 0;
	while (env->xc != env->x)
	{
		env->yc = 0;
		while (env->yc + 1 != env->y)
		{
			env->color = 0;
			if (env->xc != 0)
			{
				env->tmp2x = env->xend;
				env->tmp2y = env->yend;
			}
			env->xend = env->xc * 30;
			//env->yend = (env->yc) * 30;
			env->yend = (env->yc + 1) * 30;
			if (env->tab[env->yc][env->xc] > env->tab[env->yc + 1][env->xc])
				env->color = 1;
			if (env->yc == 0)
			{
				env->tmp2y = env->yc - env->tab[env->yc][env->xc];
				env->tmp2x = env->xc * 30 - env->tab[env->yc][env->xc];
			}
			if (env->yc == 1)
				env->tmp2y = env->yc * 30 - env->tab[env->yc][env->xc];
			if (env->tab[env->yc + 1][env->xc] == env->tab[env->yc][env->xc]
				&& env->tab[env->yc][env->xc] != 0)
			{
				env->color = 1;
				env->xend = ((env->xc) * 30) - env->tab[env->yc][env->xc];
				env->yend = ((env->yc + 1) * 30) - env->tab[env->yc][env->xc];
			}
			else if (env->tab[env->yc + 1][env->xc] > env->tab[env->yc][env->xc])
			{
				env->color = 1;
				env->yend = ((env->yc + 1) * 30) - env->tab[env->yc + 1][env->xc];
				//env->yend = ((env->yc) * 30) - env->tab[env->yc + 1][env->xc];
				env->xend = ((env->xc) * 30) - env->tab[env->yc + 1][env->xc];
			}
			p1.x = env->tmp2x;
			p1.y = env->tmp2y;
			p2.x = env->xend;
			p2.y = env->yend;
			ft_drawline(env, p1, p2);
			//ft_bhm_y(env, env->xend, env->yend);
			env->yc++;
		}
		env->xc++;
	}
}

int		expose_hook(t_env *env)
{
	ft_while_y(env);
	return (0);
}
