/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:07:55 by etregoni          #+#    #+#             */
/*   Updated: 2017/08/30 17:07:56 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_env *env, double re, double im)
{
	double	x_new;
	double	x;
	double	y;
	int			i;

	re = (4.0 * re / env->width - 2.0);
	im = (4.0 * im / env->height - 2.0);

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
	long double re;
	long double im;
	int	i;

	x = (4.0 * x / env->width - 2.0);
	y = (4.0 * y / env->height - 2.0);
	i = 0;
	re = 0;
	im = 0;

	while (x * x + y * y < 4.0 && i < env->max_iter)
	{
		x_new = x * x - y * y + re;
		y = 2 * x * y + im;
		x = x_new;
		i++;
	}
	return (i);
}

void	draw_fractal(t_env *env)
{
	int	x;
	int	y;
	int	f;

	y = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			f = env->fractal_choice(env, x, y);
			if (f < env->max_iter)
				put_pixel_to_img(env, x, y, WHITE);
			x++;
		}
		y++;
	}
}
