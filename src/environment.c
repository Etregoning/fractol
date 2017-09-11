/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 14:32:35 by etregoni          #+#    #+#             */
/*   Updated: 2017/08/29 14:32:37 by etregoni         ###   ########.fr       */
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
	else
		// set function pointer to third choice
		exit (0);
	draw_fractal(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

void	setup_environment(t_env *env)
{
	env->expose = 1;
	env->width = 800;
	env->height = 800;
	env->max_iter = 64;
	env->mouse_x = 0;
	env->mouse_y = 0;
}

void	set_hooks(t_env *env)
{
	mlx_do_key_autorepeatoff(env->mlx);
	mlx_hook(env->win, 2, 0, pressed_hooks, env);
	mlx_hook(env->win, 6, 0, motion_hook, env);
	mlx_hook(env->win, 13, 0, esc_hook, env);
}

t_env	*make_environment(void *mlx)
{
	t_env *env;

	env = (t_env*)malloc(sizeof(t_env));
	env->fractal = (t_fractal*)malloc(sizeof(t_fractal));
	setup_environment(env);
	env->mlx = mlx;
	return (env);
}
