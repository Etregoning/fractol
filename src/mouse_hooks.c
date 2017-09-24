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
	env->mouse_y = y;
	env->julia_re = env->mouse_x * 4.0 / env->width - 2;
	env->julia_im = env->mouse_y * 4.0 / env->height - 2;
	env->expose = 1;
	return (0);
}

void	change_iter(int button, t_env *env)
{
	if (button == 1)
	{
		if (env->max_iter <= 400)
			env->max_iter += 4;
	}
	else if(button == 2)
	{
		if (env->max_iter >= 8)
			env->max_iter -= 8;
	}
	ft_putstr("Iterations: ");
	ft_putnbr(env->max_iter);
	ft_putchar('\n');
}

int	mouse_press_hook(int button, int x, int y, t_env *env)
{
	if (button == 1 || button == 2)
		change_iter(button, env);
	if (button == 4)
	{
		x -= env->width / 2;
		y -= env->height / 2;
		env->zoom = (env->zoom + 1) * 1.1;
		env->x_move += x / env->zoom / 1.5;
		env->y_move += y / env->zoom / 1.5;
		printf("zoom: %f\n")
	}
	else if (button == 5 && env->zoom > 1.0)
	{
		env->x_move -= ((((double)x - 1000 / 2) / 1000 / 2)
						/ env->zoom * 1.1) / 2;
		env->y_move -= ((((double)y - 1000 / 2) / 1000 / 2)
						/ env->zoom * 1.1) / 2;
		env->zoom /= 1.1;
	}
	env->expose = 1;
	return (0);
}

int	mouse_release_hook(int button, int x, int y, t_env *env)
{
	(void)button;
	(void)env;
	(void)x;
	(void)y;
	return (0);
}
