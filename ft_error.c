/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 16:54:08 by vcaquant          #+#    #+#             */
/*   Updated: 2016/10/17 14:21:01 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
