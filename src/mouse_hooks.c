/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:31:50 by etregoni          #+#    #+#             */
/*   Updated: 2017/09/10 17:31:54 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	motion_hook(int x, int y, t_env *env)
{
	env->mouse_x = x;
	printf("mouse x = %d", x);
	env->mouse_y = y;
	printf("mouse y = %d\n", y);
	env->expose = 1;
	return (0);
}
