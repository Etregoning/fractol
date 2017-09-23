/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:31:54 by etregoni          #+#    #+#             */
/*   Updated: 2017/08/30 15:31:56 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_hook(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
	return (0);
}

int	pressed_hooks(int keycode, t_env *env)
{
	if (keycode == 53)
		exit_hook(env);
	toggle_keys(keycode, env, 1);
	return (0);
}

int	released_hook(int keycode, t_env *env)
{
	toggle_keys(keycode, env, 0);
	env->expose = 1;
	return (0);
}

void	toggle_keys(int keycode, t_env *env, int toggle)
{
	if (keycode == KEY_UP)
		env->key_pressed->up = toggle;
	if (keycode == KEY_DOWN)
		env->key_pressed->down = toggle;
	if (keycode == KEY_LEFT)
		env->key_pressed->left = toggle;
	if (keycode == KEY_RIGHT)
		env->key_pressed->right = toggle;
	if (keycode == KEY_MINUS)
	{
		env->key_pressed->minus = toggle;
		hook_output(env, 1);
		change_mov_speed(env, 1);
	}
	if (keycode == KEY_PLUS)
	{
		env->key_pressed->plus = toggle;
		hook_output(env, 1);
		change_mov_speed(env, 2);
	}
}

int	loop_hook(t_env *env)
{
	if (env->key_pressed->up || env->key_pressed->down || env->key_pressed->left ||
			env->key_pressed->right)
		env->expose = 1;
	if (env->key_pressed->up)
		env->y_move += env->mov_speed;
	if (env->key_pressed->down)
		env->y_move -= env->mov_speed;
	if (env->key_pressed->left)
		env->x_move += env->mov_speed;
	if (env->key_pressed->right)
		env->x_move -= env->mov_speed;
	if (env->expose)
		redraw(env);
	return (0);
}
