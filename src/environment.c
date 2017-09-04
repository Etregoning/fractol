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
}

t_env	*make_environment(void *mlx)
{
	t_env *env;

	env = (t_env*)malloc(sizeof(t_env));
	setup_environment(env);
	env->mlx = mlx;
	return (env);
}
