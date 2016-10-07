/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bressenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:21:38 by vcaquant          #+#    #+#             */
/*   Updated: 2016/09/21 15:40:30 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bhm_x(t_env *env, int xend, int yend)
{
	int		dx;
	int		dy;
	int		e;

	env->iso_x = 2;
	env->iso_y = 2;
	e = xend - env->tmp2x;
	dx = e * 2;
	dy = (yend - env->tmp2y) * 2;
	while (env->tmp2x <= xend)
	{
		//if (env->tab[env->tmp2y][env->tmp2x] == 10 && env->tab[yend][xend] == 10)
			//yend = yend - env->tab[yend][xend];
		ft_color(env);
		env->tmp2x++;
		if ((e = e - dy) <= 0)
		{
			env->tmp2y++;
			e = e + dx;
		}
		env->stock[0] = xend;
		env->stock[1] = yend;
	}
}

void	ft_bhm_y(t_env *env, int xend, int yend)
{
	int		dx;
	int		dy;
	int		e;

	e = yend - env->tmp2y;
	dy = e * 2;
	dx = (xend - env->tmp2x) * 2;
	while (env->tmp2y <= yend)
	{
		//if (env->tab[env->tmp2y][env->tmp2x] == 10 && env->tab[yend][xend])
			//xend = xend - env->tab[env->tmp2y][env->tmp2x];
		ft_color(env);
		env->tmp2y++;
		if ((e = e - dx) <= 0)
		{
			env->tmp2x++;
			e = e + dy;
		}
		env->stock[0] = xend;
		env->stock[1] = yend;
	}
}

void	ft_while_x(t_env *env)
{
	env->yc = 0;
	env->stock[1] = env->yc;
	while (env->yc != env->endy)
	{
		env->xc = 0;
		env->stock[0] = env->xc;
		while (env->xc + 1 != env->endx)
		{
			env->tmp2x = env->xc - env->tab[env->yc][env->xc];
			env->tmp2y = env->yc * 30 - env->tab[env->yc][env->xc];
			env->xend = ((env->xc + 1) * 30); //- env->tab[env->yc][env->xc];
			env->yend = (env->yc * 30); // - env->tab[env->yc][env->xc];
			if (env->xc != 0)
				env->tmp2x = env->xc * 30 - env->tab[env->yc][env->xc];
			if (env->tab[env->yc][env->xc + 1] == env->tab[env->yc][env->xc] && env->tab[env->yc][env->xc] != 0)
				env->yend = ((env->yc + 1) * 30) - env->tab[env->yc][env->xc] * 4;
			else if (env->tab[env->yc][env->xc + 1] > env->tab[env->yc][env->xc])
				env->yend = ((env->yc - 1) * 30) - env->tab[env->yc][env->xc];
			ft_bhm_x(env, env->xend, env->yend);
			env->xc++;
		}
		env->yc++;
	}
}

void	ft_while_y(t_env *env)
{
	ft_while_x(env);
	env->xc = 0;
	env->stock[0] = env->xc;
	while (env->xc != env->endx)
	{
		env->yc = 0;
		env->stock[1] = env->yc;
		while (env->yc + 1 != env->endy)
		{
			env->xend = (env->xc * 30);
			env->yend = ((env->yc + 1) * 30);
			env->tmp2y = env->yc - env->tab[env->yc][env->xc];
			env->tmp2x = env->xc * 30 - env->tab[env->yc][env->xc];
			if (env->yc != 0)
				env->tmp2y = env->yc * 30 - env->tab[env->yc][env->xc];
			if (env->tab[env->yc + 1][env->xc] == env->tab[env->yc][env->xc] && env->tab[env->yc][env->xc] != 0)
				env->xend = ((env->xc + 1) * 20) - env->tab[env->yc][env->xc] * 4;
			else if (env->tab[env->yc + 1][env->xc] > env->tab[env->yc][env->xc])
				env->xend = ((env->xc - 1) * 30) - env->tab[env->yc][env->xc];
			ft_bhm_y(env, env->xend, env->yend);
			env->yc++;
		}
		env->xc++;
	}
}

/*void 	ft_check(t_env *env)
{
	if (env->tab[env->yc][env->xc] != 0 && env->tab[env->yc][env->xc + 1] != env->tab[env->yc][env->xc])
	else if (env->tab[env->yc][env->xc] != 0 && env->tab[env->yc][env->xc + 1] != env->tab[env->yc][env->xc])
}*/
