/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_code.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 16:46:57 by vcaquant          #+#    #+#             */
/*   Updated: 2016/09/16 16:47:59 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		aff_key(int keycode)
{
	ft_putstr("touche");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 12 || keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		aff_mouse(int mousecode)
{
	ft_putstr("souris");
	ft_putnbr(mousecode);
	ft_putchar('\n');
	if (mousecode == 1)
		ft_putstr("Arrete d'appuyer sur moi, ça ne fais rien !\n");
	return (0);
}
