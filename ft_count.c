/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:16:41 by vcaquant          #+#    #+#             */
/*   Updated: 2016/10/17 14:20:37 by vcaquant         ###   ########.fr       */
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

	count = 0;
	while (*str != '\n' && *str != '\0')
	{
		while (*str == ' ')
			str++;
		if ((*str <= '9' && *str >= '0') || *str == '-')
			count++;
		while (*str != '\0' && *str != ' ' && *str != '\n')
			str++;
	}
	return (count);
}
