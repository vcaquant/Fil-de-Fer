/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:59:30 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/18 15:42:14 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	act_zoom(t_env *env, int keycode, double i)
{
	if (keycode == 24)
		env->up += i;
	else if (keycode == 27)
		env->up -= i;
}

int		ft_ex1(t_env *env)
{
	if ((env->tab[env->yc][env->xc + 1] >= 1 &&
		env->tab[env->yc][env->xc + 1] <= 10) ||
		(env->tab[env->yc + 1][env->xc] >= 1 &&
			env->tab[env->yc + 1][env->xc] <= 10) ||
			(env->tab[env->yc][env->xc] >= 1 &&
				env->tab[env->yc][env->xc] <= 10))
		return (1);
	else
		return (0);
}

int		ft_ex2(t_env *env)
{
	if ((env->tab[env->yc][env->xc + 1] >= 11 &&
		env->tab[env->yc][env->xc + 1] <= 30) ||
		(env->tab[env->yc + 1][env->xc] >= 11 &&
			env->tab[env->yc + 1][env->xc] <= 30) ||
			(env->tab[env->yc][env->xc] >= 11 &&
				env->tab[env->yc][env->xc] <= 30))
		return (1);
	else
		return (0);
}

int		ft_ex3(t_env *env)
{
	if ((env->tab[env->yc][env->xc + 1] >= 31 &&
		env->tab[env->yc][env->xc + 1] <= 40) ||
		(env->tab[env->yc + 1][env->xc] >= 31 &&
			env->tab[env->yc + 1][env->xc] <= 40) ||
			(env->tab[env->yc][env->xc] >= 31 &&
				env->tab[env->yc][env->xc] <= 40))
		return (1);
	else
		return (0);
}

int		ft_ex4(t_env *env)
{
	if ((env->tab[env->yc][env->xc + 1] >= 41 &&
		env->tab[env->yc][env->xc + 1] <= 70) ||
		(env->tab[env->yc + 1][env->xc] >= 41 &&
			env->tab[env->yc + 1][env->xc] <= 70) ||
			(env->tab[env->yc][env->xc] >= 41 &&
				env->tab[env->yc][env->xc] <= 70))
		return (1);
	else
		return (0);
}
