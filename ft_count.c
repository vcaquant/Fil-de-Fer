/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:16:41 by vcaquant          #+#    #+#             */
/*   Updated: 2016/10/23 02:08:09 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_init_tab(t_env *env, char **av)
{
	char	*line;
	int		ret;
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	env->fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line((int const)env->fd, &line)) > 0)
	{
		x = 0;
		x = ft_count_x(line);
		env->endx = x;
		if (y == 0)
			env->x = x;
		if (x != env->x)
			return (-1);
		y++;
	}
	env->y = y;
	close(env->fd);
	return (1);
}

int		ft_count_x(char *str)
{
	int		count;
	int		x;

	count = 0;
	x = 0;
	while (str[x] != '\n' && str[x] != '\0')
	{
		while (str[x] == ' ')
			x++;
		if ((str[x] <= '9' && str[x] >= '0') || str[x] == '-')
			count++;
		while (str[x] != '\0' && str[x] != ' ' && str[x] != '\n')
			x++;
	}
	return (count);
}
