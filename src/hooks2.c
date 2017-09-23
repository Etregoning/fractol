/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 23:05:37 by etregoni          #+#    #+#             */
/*   Updated: 2017/09/22 23:05:40 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_mov_speed(t_env *env, int flag)
{
	if (flag == 1)
	{
		if (env->mov_speed < 10)
			env->mov_speed += 0.5;
		flag = 0;
	}
	if (flag == 2)
	{
		if (env->mov_speed >= 0.6)
			env->mov_speed -= 0.5;
		else if (env->mov_speed >= 0.1)
			env->mov_speed -= 0.1;
		flag = 0;
	}
}

void	hook_output(t_env *env, int flag)
{
	if (flag == 1)
	{
		ft_putstr("Movement speed: ");
		ft_putnbr(env->mov_speed);
		ft_putchar('\n');
	}
}
