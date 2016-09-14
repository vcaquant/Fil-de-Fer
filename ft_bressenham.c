#include "fdf.h"

void 	ft_bresenham_x(t_env *env, int xstart, int ystart, int xend, int yend)
{
	int 	dx;
	int 	dy;
	int 	e;

	e = xend - xstart;
	dx = e * 2;
	dy = (yend - ystart) * 2;
	while (xstart <= xend)
	{
		mlx_pixel_put(env->mlx, env->win, xstart, ystart, 0x00FFFFFF);
		xstart++;
		if ((e = e - dy) <= 0)
		{
			ystart++;
			e = e + dx;
		}
	}
}

void 	ft_bresenham_y(t_env *env, int xstart, int ystart, int xend, int yend)
{
	int 	dx;
	int 	dy;
	int 	e;

	e = yend - ystart;
	dy = e * 2;
	dx = (xend - xstart) * 2;
	while (ystart <= yend)
	{
		mlx_pixel_put(env->mlx, env->win, xstart, ystart, 0x00FFFFFF);
		ystart++;
		if ((e = e - dx) <= 0)
		{
			xstart++;
			e = e + dy;
		}
	}
}

void  ft_while_x(t_env *env, int xc, int yc, int tmpx, int tmpy)
{
  int   tmp2x;
  int   tmp2y;

  yc = 0;
  while (yc != tmpy)
  {
    xc = 0;
    while (xc + 1 != tmpx)
    {
      tmp2x = xc;
      tmp2y = yc * 20;
      if (xc != 0)
        tmp2x = xc * 20;
      ft_bresenham_x(env, tmp2x, tmp2y, (xc + 1) * 20, yc * 20);
      xc++;
    }
    yc++;
  }
}

void  ft_while_y(t_env *env, int xc, int yc, int tmpx, int tmpy)
{
  int   tmp2x;
  int   tmp2y;

  xc = 0;
  while (xc != tmpx)
  {
    yc = 0;
    while (yc + 1 != tmpy)
    {
      tmp2y = yc;
      tmp2x = xc * 20;
      if (yc != 0)
        tmp2y = yc * 20;
      ft_bresenham_y(env, tmp2x, tmp2y, xc * 20, (yc + 1) * 20);
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
