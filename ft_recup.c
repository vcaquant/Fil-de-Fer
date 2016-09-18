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
}
