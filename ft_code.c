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

int 	aff_mouse(int mousecode)
{
	ft_putstr("souris");
	ft_putnbr(mousecode);
	ft_putchar('\n');
	if (mousecode == 1)
    ft_putstr("Arrete d'appuyer sur moi, ça ne fais rien !\n");
	return(0);
}
