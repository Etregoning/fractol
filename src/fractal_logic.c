/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:07:55 by etregoni          #+#    #+#             */
/*   Updated: 2017/09/18 17:56:21 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_env *env, double re, double im)
{
	double	x_new;
	double	x;
	double	y;
	int			i;

	re = ((4.0 * re / env->width - 2.0) / env->zoom) + (env->x_move / env->width);
	im = ((4.0 * im / env->height - 2.0) / env->zoom) + (env->y_move / env->height);

	x = 0;
	y = 0;
	i = 0;
	while (x * x + y * y <= 4 && i < env->max_iter)
	{
		x_new = x * x - y * y + re;
		y = 2 * x * y + im;
		x = x_new;
		i++;
	}
		return (i);
}

int	julia(t_env *env, double x, double y)
{
	long double x_new;
	int	i;

	i = 0;
	x = ((4.0 * x / env->width - 2.0) / env->zoom) + (env->x_move / env->width);
	y = ((4.0 * y / env->height - 2.0) / env->zoom) + (env->y_move / env->height);

	while (x * x + y * y < 4.0 && i < env->max_iter)
	{
		x_new = x * x - y * y + env->julia_re;
		y = 2 * x * y + env->julia_im;
		x = x_new;
		i++;
	}
	return (i);
}

int	burning_ship(t_env *env, double x, double y)
{
	int i;
	double x_new;
	double	re;
	double	im;

	x = ((4.0 * x / env->width - 2.0) / env->zoom) + (env->x_move / env->width);
	y = ((4.0 * y / env->height - 2.0) / env->zoom) + (env->y_move / env->height);
	re = 0;
	im = 0;
	i = 0;

	while (re  * re + im * im < 4 && ++i < env->max_iter)
	{
		x_new = re;
		re = re * re - im * im + x;
		im = 2 * fabs(im * x_new) + y;
	}
	return (i);
}

int	carpet(t_env *env, double x, double y)
{
	int i;

	i = 0;
	x *= env->zoom;
	y *= env->zoom;
	while ((x > 0 || y > 0) && i < env->max_iter)
	{
		if ((int)x % 3 == 1 && (int)y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
		i++;
	}
	return (1);
}

void	draw_fractal(void *current_thread)
{
	int	x;
	int	y;
	int	f;
	t_env *env;
	t_thread *thread;

	thread = (t_thread*)current_thread;
	env = thread->env;
	f = 0;
	y = (env->height / thread->count * (thread->index - 1)) - 1;
	while (++y < env->height / thread->count * thread->index)
	{
		x = -1;
		while (++x < env->width)
		{
			f = env->fractal_choice(env, x, y);
			if (f < env->max_iter)
				put_pixel_to_img(env, x, y, f * 10000);
			else
				put_pixel_to_img(env, x, y, 0);
		}
	}
}
