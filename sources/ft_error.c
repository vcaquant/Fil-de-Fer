/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 16:54:08 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/10 14:02:11 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_error(int ac)
{
	if (ac != 2)
	{
		ft_putstr("error syntax : ./fdf <file>");
		return (-1);
	}
	return (0);
}

int		ft_map_not_valid(void)
{
	ft_putstr("It's not a valid map\n");
	return (-1);
}

void	inc_z(t_env *env)
{
	int		i;
	int		j;

	j = 0;
	while (j < env->y)
	{
		i = 0;
		while (i < env->x)
		{
			if (env->tab[j][i] > 0 || env->tab[j][i] < 0)
			{
				if (env->tab[j][i] != -10)
					env->tab[j][i] += 10;
				else
					env->tab[j][i] += 11;
			}
			i++;
		}
		j++;
	}
}

void	low_z(t_env *env)
{
	int		i;
	int		j;

	j = 0;
	while (j < env->y)
	{
		i = 0;
		while (i < env->x)
		{
			if (env->tab[j][i] > 0 || env->tab[j][i] < 0)
			{
				if (env->tab[j][i] != 10)
					env->tab[j][i] -= 10;
				else
					env->tab[j][i] -= 11;
			}
			i++;
		}
		j++;
	}
}
