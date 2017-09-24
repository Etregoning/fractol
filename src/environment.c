/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 14:32:35 by etregoni          #+#    #+#             */
/*   Updated: 2017/09/18 17:51:05 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	redraw(t_env *env)
{
	env->expose = 0;
	if (env->arg == 1)
		env->fractal_choice = mandelbrot;
	else if (env->arg == 2)
		env->fractal_choice = julia;
	else if (env->arg == 3)
		env->fractal_choice = burning_ship;
	else if (env->arg == 4)
		env->fractal_choice = carpet;
	else if (env->arg == 5)
		env->fractal_choice = julia_cubed;
	mlx_clear_window(env->mlx, env->win);
	ft_bzero(env->img_addr, sizeof(env->img_addr));
	init_thread(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

void	setup_environment(t_env *env)
{
	env->expose = 1;
	env->width = 800;
	env->height = 800;
	env->max_iter = 80;
	env->mouse_x = 0;
	env->mouse_y = 0;
	env->x_move =  0;
	env->y_move = 0;
	env->zoom = 1.0;
	env->mov_speed = 0.5;
	env->key_pressed->up = 0;
	env->key_pressed->down = 0;
	env->key_pressed->left = 0;
	env->key_pressed->right = 0;
	env->key_pressed->plus = 0;
	env->key_pressed->minus = 0;
}

void	set_hooks(t_env *env)
{
	mlx_do_key_autorepeatoff(env->mlx);
	mlx_hook(env->win, 2, 0, pressed_hooks, env);
	mlx_hook(env->win, 3, 0, released_hook, env);
	mlx_hook(env->win, 4, 0, mouse_press_hook, env);
	mlx_hook(env->win, 5, 0, mouse_release_hook, env);
	mlx_hook(env->win, 6, 0, motion_hook, env);
	mlx_hook(env->win, 17, 0, exit_hook, env);
}

t_env	*make_environment(void *mlx)
{
	t_env *env;

	env = (t_env*)malloc(sizeof(t_env));
	env->key_pressed = (t_keys*)malloc(sizeof(t_keys));
	setup_environment(env);
	env->mlx = mlx;
	return (env);
}
