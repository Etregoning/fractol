/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:51:28 by etregoni          #+#    #+#             */
/*   Updated: 2017/08/23 15:32:15 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include <math.h>
# include <pthread.h>
# include <stdio.h>
# define NUM_THREADS 16

typedef	struct	s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*img_addr;
	int					expose;
	int					arg;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int					width;
	int					height;
	int					max_iter;
	int					zoom;
	float				mov_speed;
	double			mouse_x;
	double			mouse_y;
	double			x_move;
	double			y_move;
	long double	julia_re;
	long double	julia_im;
	t_keys			*key_pressed;
	int					(*fractal_choice)(struct s_env *env, double x, double y);
}							t_env;

typedef struct s_thread
{
	t_env	*env;
	int		count;
	int		index;
}				t_thread;

typedef union	u_colors
{
	unsigned int	channels[3];
}								t_colors;

t_env	*make_environment(void *mlx);
void	create_image(t_env *env);
void	redraw(t_env *env);
int	loop_hook(t_env *env);
void	put_pixel_to_img(t_env *env, int x, int y, int color);
int	mandelbrot(t_env *env, double re, double im);
int	julia(t_env *env, double x, double y);
int	julia_cubed(t_env *env, double x, double y);
int	burning_ship(t_env *env, double x, double y);
int	carpet(t_env *env, double x, double y);
void	draw_fractal(void *current_thread);
void	set_hooks(t_env *env);
int	pressed_hooks(int keycode, t_env *env);
int	released_hook(int keycode, t_env *env);
int	motion_hook(int x, int y, t_env *env);
void	toggle_keys(int keycode, t_env *env, int toggle);
int	mouse_press_hook(int button, int x, int y, t_env *env);
int	mouse_release_hook(int button, int x, int y, t_env *env);
int	exit_hook(t_env *env);
void	change_mov_speed(t_env *env, int flag);
void	hook_output(t_env *env, int flag);
void	init_thread(t_env *env);
unsigned int	get_color(int i, double x, double y);

#endif
