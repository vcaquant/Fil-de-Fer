/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 17:02:42 by vcaquant          #+#    #+#             */
/*   Updated: 2016/10/23 02:14:16 by vcaquant         ###   ########.fr       */
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
	while (str[j] != '\0' && str[j] != '\n')
	{
		while (str[j] == ' ')
			j++;
		if ((str[j] <= '9' && str[j] >= '0') || str[j] == '-')
			tab[i++] = ft_atoi(&str[j]);
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
		env->tab[env->yc] = ft_recupline(env->line);
		env->yc++;
	}
	close(env->fd);
	env->endy = env->yc;
}
