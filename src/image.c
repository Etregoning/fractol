/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 19:26:05 by etregoni          #+#    #+#             */
/*   Updated: 2017/09/18 17:53:09 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_img(t_env *env, int x, int y, int color)
{
	int i;

	i = (x * (env->bits_per_pixel / 8)) + (y * env->size_line);
	if (x > 0 && y > 0 && x < env->width && y < env->height)
	{
	//	i = (x * (env->bits_per_pixel / 8)) + (y * env->size_line);
		env->img_addr[i] = color;
		env->img_addr[++i] = color >> 8;
		env->img_addr[++i] = color >> 16;
	}
	else
	{
		env->img_addr[i] = 0;
		env->img_addr[++i] = 0;
		env->img_addr[++i] = 0;
	}

}

void	create_image(t_env *env)
{
	env->img = mlx_new_image(env->mlx, env->width, env->height);
	env->img_addr = mlx_get_data_addr(env->img, &(env->bits_per_pixel),
																&(env->size_line), &(env->endian));
}

unsigned int	get_color(int i, double x, double y)
{
	unsigned int	color;
	double m;
	double index;
	t_colors	c;

	m = sqrt(x * x + y * y);
	index = i + 1 - (log(2) / m) / log(2);
	c.channels[0] = (unsigned char)(sin(0.040 * index + 10) * 230 + 25);
	c.channels[1] = (unsigned char)(sin(0.037 * index + 5) * 230 + 25);
	c.channels[2] = (unsigned char)(sin(0.020 * index + 2) * 230 + 25);
	color = (c.channels[0] << 16) + (c.channels[1] << 8) + c.channels[2] + 255;
	return (color);
}
