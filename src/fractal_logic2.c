/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_logic2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:58:14 by etregoni          #+#    #+#             */
/*   Updated: 2017/09/21 16:58:17 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_cubed(t_env *env, double x, double y)
{
	long double x_new;
	int	i;

	i = 0;
	x = ((4.0 * x / env->width - 2.0) / env->zoom) + (env->x_move / env->width);
	y = ((4.0 * y / env->height - 2.0) / env->zoom) + (env->y_move / env->height);

	while (x * x + y * y < 4.0 && i < env->max_iter)
	{
		x_new = x * x * x - y * y * x - (2 * x * y * y) + env->julia_re;
		y = 2 * x * x * y - y * y * y + env->julia_im;
		x = x_new;
		i++;
	}
	return (i);
}
