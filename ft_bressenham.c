/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bressenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:21:38 by vcaquant          #+#    #+#             */
/*   Updated: 2016/30/17 16:46:30 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	ft_bresenham(t_env *env, )
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		ex;
	int		ey;

	dx = (env->tmp2x - env->xend >= 0 ? env->tmp2x - env->xend : env->xend - env->tmp2x);
	dy = (env->tmp2y - env->yend >= 0 ? env->yend - env->yend : env->yend - env->tmp2y);
	sx = (env->tmp2x < env->xend ? 1 : -1);
	sy = (env->tmp2y < env->yend ? 1 : -1);
	ex = (dx > dy ? dx : -dy) / 2;
	while (env->tmp2x != env->xend || env->tmp2y != env->yend)
	{
		mlx_pixel_put(env->mlx, env->win, env->tmp2x, env->tmp2y, WHITE);
		ey = ex;
		if (ey > -dx)
		{
			ex -= dy;
			env->tmp2x += sx;
		}
		if (ey < dy)
		{
			ex += dx;
			env->tmp2y += sy;
		}
	}
	mlx_pixel_put(env->mlx, env->win, env->tmp2x, env->tmp2y, WHITE);
}*/

/*void	ft_bresenham(t_env *env, t_coo start, t_coo end)
{
	t_coo	d;
	t_coo	s;
	t_coo	err;

	d.x = (start.x - end.x >= 0 ? start.x - end.x : end.x - start.x);
	d.y = (start.y - end.y >= 0 ? start.y - end.y : end.y - start.y);
	s.x = (start.x < end.x ? 1 : -1);
	s.y = (start.y < end.y ? 1 : -1);
	err.x = (d.x > d.y ? d.x : -d.y) / 2;
	while (start.x != end.x || start.y != end.y)
	{
		mlx_pixel_put(env->mlx, env->win, start.x, start.y, start.c + end.c);
		err.y = err.x;
		if (err.y > -d.x)
		{
			err.x -= d.y;
			start.x += s.x;
		}
		if (err.y < d.y)
		{
			err.x += d.x;
			start.y += s.y;
		}
	}
	mlx_pixel_put(env->mlx, env->win, start.x, start.y, start.c + end.c);
}

int		ft_travel_right(t_env *env, int x, int y)
{
	t_coo	current;

	current = ft_trdtotwd(x, y, env->tab[y][x]);
	//if (grid->right)
		ft_bresenham(env, current, ft_trdtotwd(x + 1, y, env->tab[y][x]));
	//if (grid->down)
	//{
	//	if (grid->down->exist)
			ft_bresenham(env, current, ft_trdtotwd(x, y + 1, env->tab[y][x]));
	//}
	//if (grid->right)
	//{
		return (ft_travel_right(env, x + 1, y));
	//}
	//else
	//	return (0);
}

int		ft_travel_down(t_env *env, int x, int y)
{
	//if (grid->right)
		ft_travel_right(env, x, y);
	//if (grid->down)
		return (ft_travel_down(env, x, y + 1));
	//else
	//	return (0);
}*/

/*void	ft_bhm_x(t_env *env, int xend, int yend)
{
	int		dx;
	int		dy;
	int		e;

	env->iso_x = 2;
	env->iso_y = 2;
	e = xend - env->tmp2x;
	dx = e * 2;
	dy = (yend - env->tmp2y) * 2;
	if (yend < env->tmp2y)
		dy = (env->tmp2y - yend) * 2;
	while (env->tmp2x <= xend)
	{
		ft_color(env);
		env->tmp2x++;
		if ((e = e - dy) <= 0)
		{
			if (yend > env->tmp2y)
				env->tmp2y++;
			else
				env->tmp2y--;
			e = e + dx;
		}
	}
	env->stockx = xend;
	env->stocky = yend;
}

void	ft_bhm_y(t_env *env, int xend, int yend)
{
	int		dx;
	int		dy;
	int		e;

	e = yend - env->tmp2y;
	dy = e * 2;
	dx = (xend - env->tmp2x) * 2;
	if (env->xend < env->tmp2x)
		dx = (env->tmp2x - xend) * 2;
	while (env->tmp2y <= yend)
	{
		ft_color(env);
		env->tmp2y++;
		if ((e = e - dx) <= 0)
		{
			if (env->xend > env->tmp2x)
				env->tmp2x++;
			else
				env->tmp2x--;
			e = e + dy;
		}
	}
}*/

void	ft_while_x(t_env *env)
{
	t_point		p1;
	t_point		p2;

	env->yc = 0;
	while (env->yc < env->y)
	{
		env->xc = 0;
		while (env->xc + 1 != env->x)
		{
			env->color = 0;
			 if (env->xc != 0)
			{
				env->tmp2x = env->xend;
				env->tmp2y = env->yend;
			}
			//env->xend = env->xc * 30;
			env->xend = (env->xc + 1) * 30;
			env->yend =	env->yc * 30;
			if (env->xc == 0)
			{
				env->tmp2x = env->xc - env->tab[env->yc][env->xc];
				env->tmp2y = env->yc * 30 - env->tab[env->yc][env->xc];
			}
			if (env->tab[env->yc][env->xc] > env->tab[env->yc][env->xc + 1])
				env->color = 1;
			if (env->xc == 1)
				env->tmp2x = env->xc * 30 - env->tab[env->yc][env->xc];
			if (env->tab[env->yc][env->xc + 1] == env->tab[env->yc][env->xc]
				&& env->tab[env->yc][env->xc] != 0)
			{
				env->yend = ((env->yc) * 30) - env->tab[env->yc][env->xc];
				env->xend = ((env->xc + 1) * 30) - env->tab[env->yc][env->xc];
				env->color = 1;
			}
			else if (env->tab[env->yc][env->xc + 1] > env->tab[env->yc][env->xc])
			{
				env->yend = (env->yc * 30) - env->tab[env->yc][env->xc + 1];
				//env->xend = ((env->xc) * 30) - env->tab[env->yc][env->xc + 1];
				env->xend = ((env->xc + 1) * 30) - env->tab[env->yc][env->xc + 1];
				env->color = 1;
			}
			//ft_bhm_x(env, env->xend, env->yend);
			p1.x = env->tmp2x;
			p1.y = env->tmp2y;
			p2.x = env->xend;
			p2.y = env->yend;
			//printf("----\nx1 = %f y1 = %f\n----\nx2 = %f y2 = %f\n", p1.x, p1.y, p2.x, p2.y);
			ft_drawline(env, p1, p2);
			env->xc++;
		}
		env->yc++;
	}
}

void	ft_while_y(t_env *env)
{
	t_point		p1;
	t_point		p2;

	ft_while_x(env);
	env->xc = 0;
	while (env->xc != env->x)
	{
		env->yc = 0;
		while (env->yc + 1 != env->y)
		{
			env->color = 0;
			if (env->xc != 0)
		   	{
			   env->tmp2x = env->xend;
			   env->tmp2y = env->yend;
		   	}
			env->xend = env->xc * 30;
			//env->yend = (env->yc) * 30;
			env->yend = (env->yc + 1) * 30;
			if (env->tab[env->yc][env->xc] > env->tab[env->yc + 1][env->xc])
				env->color = 1;
			if (env->yc == 0)
			{
				env->tmp2y = env->yc - env->tab[env->yc][env->xc];
				env->tmp2x = env->xc * 30 - env->tab[env->yc][env->xc];
			}
			if (env->yc == 1)
				env->tmp2y = env->yc * 30 - env->tab[env->yc][env->xc];
			if (env->tab[env->yc + 1][env->xc] == env->tab[env->yc][env->xc]
				&& env->tab[env->yc][env->xc] != 0)
			{
				env->color = 1;
				env->xend = ((env->xc) * 30) - env->tab[env->yc][env->xc];
				env->yend = ((env->yc + 1) * 30) - env->tab[env->yc][env->xc];
			}
			else if (env->tab[env->yc + 1][env->xc] > env->tab[env->yc][env->xc])
			{
				env->color = 1;
				env->yend = ((env->yc + 1) * 30) - env->tab[env->yc + 1][env->xc];
				//env->yend = ((env->yc) * 30) - env->tab[env->yc + 1][env->xc];
				env->xend = ((env->xc) * 30) - env->tab[env->yc + 1][env->xc];
			}
			p1.x = env->tmp2x;
			p1.y = env->tmp2y;
			p2.x = env->xend;
			p2.y = env->yend;
			ft_drawline(env, p1, p2);
			//ft_bhm_y(env, env->xend, env->yend);
			env->yc++;
		}
		env->xc++;
	}
}

int		expose_hook(t_env *env)
{
	ft_while_y(env);
	return (0);
}
