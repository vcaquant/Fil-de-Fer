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

void ft_Line(void *mlx, void *win, int x1, int y1, int x2, int y2) //bress
{
    int x,y;
    int Dx,Dy;
    int xincr,yincr;
    int erreur;
    int i;

    Dx = abs(x2 - x1);
    Dy = abs(y2 - y1);
    if(x1 < x2)
        xincr = 1;
    else
        xincr = -1;
    if(y1 < y2)
        yincr = 1;
    else
        yincr = -1;
    x = x1;
    y = y1;
    if(Dx > Dy)
    {
        erreur = Dx / 2;
        for(i=0;i<Dx;i++)
        {
            x += xincr;
            erreur += Dy;
            if(erreur > Dx)
            {
                erreur -= Dx;
                y += yincr;
            }
            mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
        }
    }
    else
    {
        erreur = Dy / 2;
        for(i = 0; i < Dy; i++)
        {
            y += yincr;
            erreur += Dx;
            if(erreur > Dy)
            {
                erreur -= Dy;
                x += xincr;
            }
            mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
        }
    }
    mlx_pixel_put(mlx, win, x1, y1, 0x00FFFFFF);
    mlx_pixel_put(mlx, win, x2, y2, 0x00FFFFFF);
}

int 	ft_init_struct(t_env **env, char **av)
{
	int 	i;

	i = 0;
	if (!(*env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	(*env)->fd = open(av[1], O_RDONLY);
	return (1);
}

void	ft_debug(int **tab, int xc, int yc)
{
	ft_putnbr(tab[yc][xc]);
	if (tab[yc][xc] == 10 || tab[yc][xc] == 11 || tab[yc][xc] == 90)
		ft_putchar(' ');
	else
		ft_putstr("  ");
	//ft_putstr("xc = ");
	//ft_putnbr(xc);
	//ft_putstr("yc = ");
	//ft_putnbr(yc);
	//ft_putchar('\n');
}

int		main(int ac, char **av)
{
	t_env	*env = NULL;
	int 	xc;
	int 	xc2;
	int 	yc;
	int 	**tab = malloc(sizeof(*tab) * 20);
	int 	i;
	int 	tmpx;
	int 	tmpy;
	int 	tmp2x;
	int 	tmp2y;

	i = 0;
	/*if ((env->fd = open(av[1], O_RDONLY)) > 0)
		while ((env->ret = get_next_line((int const)env->fd, &env->line)) > 0)
			i++;
	tab = (int**)malloc(sizeof(int*) * (i + 1));*/
	while (i < 20)
	{
    	tab[i] = malloc(sizeof(**tab) * 50);
    	i++;
	}
	yc = 0;
	(void)ac;
	if (!ft_init_struct(&env, av))
		return (-1);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, W_X, W_Y, "FDF_42");
	//ft_putstr("avant\n");
	while ((env->ret = get_next_line((int const)env->fd, &env->line)) > 0)
	{
		xc = 0;
		xc2 = 0;
		while (env->line[xc2])
		{
			while (env->line[xc2] == ' ')
				xc2++;
			tab[yc][xc] = ft_atoi(&env->line[xc2]);
			ft_debug(tab, xc, yc);
			xc++;
			xc2++;
			if (env->line[xc2] >= '0' && env->line[xc2] <= '9')
				xc2++;
		}
		ft_putstr("passe\n");
		yc++;
	}
	tmpx = xc;
	tmpy = yc;
	yc = 0;
	while (yc != tmpy)
	{
		xc = 0;
		while (xc != tmpx)
		{
			tmp2x = xc;
			tmp2y = yc * 20;
			if (xc != 0)
				tmp2x = xc * 20;
			mlx_pixel_put(env->mlx, env->win, tmp2x, tmp2y, 0x00FFFFFF);
			xc++;
			ft_putstr("\033[032;32m1\033[0m");
		}
		yc++;
		ft_putstr("\033[032;31m0\033[0m");
	}
	ft_putchar('\n');
	yc = 0;
	while (yc != tmpy)
	{
		xc = 0;
		while (xc != tmpx)
		{
			tmp2x = xc;
			tmp2y = yc * 20;
			if (xc != 0)
				tmp2x = xc * 20;
			ft_Line(env->mlx, env->win, tmp2x, tmp2y, xc + 1, yc + 1);
			xc++;
		}
		yc++;
	}
	mlx_key_hook(env->win, aff_key, env->mlx);
	mlx_loop(env->mlx);
}
