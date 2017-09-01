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

void	create_image(t_env *env)
{
	env->img = mlx_new_image(env->mlx, env->width, env->height);
	env->img_addr = mlx_get_data_addr(env->img, &(env->bits_per_pixel),
																&(env->size_line), &(env->endian));
}
