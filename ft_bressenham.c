/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bressenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:21:38 by vcaquant          #+#    #+#             */
/*   Updated: 2016/09/18 17:05:05 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bhm_x(t_env *env, int xend, int yend)
{
	int		dx;
	int		dy;
	int		e;

	e = xend - env->tmp2x;
	dx = e * 2;
	dy = (yend - env->tmp2y) * 2;
	while (env->tmp2x <= xend)
	{
		mlx_pixel_put(env->mlx, env->win, env->tmp2x, env->tmp2y, 0x00FFFFFF);
		env->tmp2x++;
		if ((e = e - dy) <= 0)
		{
			env->tmp2y++;
			e = e + dx;
		}
	}
}

void	ft_bhm_y(t_env *env, int xend, int yend)
{
	int		dx;
	int		dy;
	int		e;

	e = yend - env->tmp2y;
	dy = e * 2;
	dx = (xend - env->tmp2x) * 2;
	while (env->tmp2y <= yend)
	{
		mlx_pixel_put(env->mlx, env->win, env->tmp2x, env->tmp2y, 0x00FFFFFF);
		env->tmp2y++;
		if ((e = e - dx) <= 0)
		{
			env->tmp2x++;
			e = e + dy;
		}
	}
}

void	ft_while_x(t_env *env, int tmpx, int tmpy)
{
	int		xc;
	int		yc;

	yc = 0;
	while (yc != tmpy)
	{
		xc = 0;
		while (xc + 1 != tmpx)
		{
			env->tmp2x = xc;
			env->tmp2y = (yc * 20) - env->tab[yc][xc];
			if (xc != 0)
				env->tmp2x = xc * 20;
			ft_bhm_x(env, (xc + 1) * 20, yc * 20);
			xc++;
		}
		yc++;
	}
}

void	ft_while_y(t_env *env, int tmpx, int tmpy)
{
	int		xc;
	int		yc;

	ft_while_x(env, tmpx, tmpy);
	xc = 0;
	while (xc != tmpx)
	{
		yc = 0;
		while (yc + 1 != tmpy)
		{
			env->tmp2y = yc - env->tab[yc][xc];
			env->tmp2x = xc * 20;
			if (yc != 0)
				env->tmp2y = yc * 20;
			ft_bhm_y(env, xc * 20, (yc + 1) * 20);
			yc++;
		}
		xc++;
	}
}

/*void ft_Line(void *mlx, void *win, int x1, int y1, int x2, int y2) //bress
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
}*/
