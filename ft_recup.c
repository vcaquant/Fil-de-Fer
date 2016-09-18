#include "fdf.h"

void  ft_recup(t_env *env)
{
  env->yc = 0;
  while ((env->ret = get_next_line((int const)env->fd, &env->line)) > 0)
	{
		env->xc = 0;
		env->xc2 = 0;
		while (env->line[env->xc2])
		{
			while (env->line[env->xc2] == ' ')
				env->xc2++;
			env->tab[env->yc][env->xc] = ft_atoi(&env->line[env->xc2]);
			env->xc++;
			env->xc2++;
			if (env->line[env->xc2] >= '0' && env->line[env->xc2] <= '9')
				env->xc2++;
		}
		env->yc++;
	}
  env->tmpx = env->xc;
	env->tmpy = env->yc;
  ft_print_points(env);
}

void ft_print_points(t_env *env)
{
  env->zoom = 20;
  env->yc = 0;
  while (env->yc != env->tmpy)
  {
    env->xc = 0;
    while (env->xc != env->tmpx)
    {
      env->tmp2x = env->xc;
      env->tmp2y = (env->yc * env->zoom) - env->tab[env->yc][env->xc];
      if (env->xc != 0)
        env->tmp2x = env->xc * env->zoom;
      if (env->tab[env->yc][env->xc] == 10)
        mlx_pixel_put(env->mlx, env->win, env->tmp2x, env->tmp2y, 0x0000FF);
      else
        mlx_pixel_put(env->mlx, env->win, env->tmp2x, env->tmp2y, 0xFFFFFF);
      env->xc++;
    }
    env->yc++;
  }
}
