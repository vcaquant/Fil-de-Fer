#include "fdf.h"

int 	aff_help_exit(int keycode, t_env *env)
{
	if (keycode == 12 || keycode == 53)
		mlx_destroy_window(env->mlx, env->s_win);
	return (0);
}

void 	aff_help(t_env *env)
{
	env->s_win = mlx_new_window(env->mlx, 400, 400, "HELP_FDF");
	mlx_string_put(env->mlx, env->s_win, 0, 0, WHITE, "Deplacement avec les fleches");
	mlx_string_put(env->mlx, env->s_win, 0, 15, WHITE, "K = Augmentation des Z");
	mlx_string_put(env->mlx, env->s_win, 0, 30, WHITE, "M = Diminution des Z");
	mlx_string_put(env->mlx, env->s_win, 0, 45, WHITE, "+ = Zoom");
	mlx_string_put(env->mlx, env->s_win, 0, 60, WHITE, "- = Dezoom");
	mlx_key_hook(env->s_win, aff_help_exit, env);
} 
