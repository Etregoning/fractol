/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 19:26:05 by etregoni          #+#    #+#             */
/*   Updated: 2017/08/31 19:26:08 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_img(t_env *env, int x, int y, int color)
{
	int i;

	if (x > 0 && y > 0 && x < env->width && y < env->height)
	{
		i = (x * (env->bits_per_pixel / 8)) + (y * env->size_line);
		env->img_addr[i] = color;
	}
}

void	create_image(t_env *env)
{
	env->img = mlx_new_image(env->mlx, env->width, env->height);
	env->img_addr = mlx_get_data_addr(env->img, &(env->bits_per_pixel),
																&(env->size_line), &(env->endian));
}
