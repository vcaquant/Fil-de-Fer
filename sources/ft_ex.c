/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:59:30 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/10 15:24:59 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_ex1(t_env *env)
{
	if ((env->tab[env->yc][env->xc + 1] >= 1 &&
		env->tab[env->yc][env->xc + 1] <= 10) ||
		(env->tab[env->yc + 1][env->xc] >= 1 &&
			env->tab[env->yc + 1][env->xc + 1] <= 10) ||
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
			env->tab[env->yc + 1][env->xc + 1] <= 20) ||
			(env->tab[env->yc][env->xc] >= 11 &&
				env->tab[env->yc][env->xc] <= 20))
		return (1);
	else
		return (0);
}

int		ft_ex3(t_env *env)
{
	if ((env->tab[env->yc][env->xc + 1] >= 31 &&
		env->tab[env->yc][env->xc + 1] <= 40) ||
		(env->tab[env->yc + 1][env->xc] >= 21 &&
			env->tab[env->yc + 1][env->xc + 1] <= 30) ||
			(env->tab[env->yc][env->xc] >= 21 &&
				env->tab[env->yc][env->xc] <= 30))
		return (1);
	else
		return (0);
}

int		ft_ex4(t_env *env)
{
	if ((env->tab[env->yc][env->xc + 1] >= 41 &&
		env->tab[env->yc][env->xc + 1] <= 70) ||
		(env->tab[env->yc + 1][env->xc] >= 31 &&
			env->tab[env->yc + 1][env->xc + 1] <= 60) ||
			(env->tab[env->yc][env->xc] >= 31 &&
				env->tab[env->yc][env->xc] <= 60))
		return (1);
	else
		return (0);
}
