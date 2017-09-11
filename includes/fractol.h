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
# include <stdio.h>
# define WHITE 0x00FFFFFF

typedef struct	s_fractal
{
	long double x;
	long double y;
	long double re;
	long double im;
}							t_fractal;

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
	double			mouse_x;
	double			mouse_y;
	t_fractal		*fractal;
	int					(*fractal_choice)(struct s_env *env, double x, double y);
}							t_env;

t_env	*make_environment(void *mlx);
void	create_image(t_env *env);
void	redraw(t_env *env);
int	loop_hook(t_env *env);
void	put_pixel_to_img(t_env *env, int x, int y, int color);
int	mandelbrot(t_env *env, double re, double im);
int	julia(t_env *env, double x, double y);
void	draw_fractal(t_env *env);
void	set_hooks(t_env *env);
int	pressed_hooks(int keycode, t_env *env);
int	motion_hook(int x, int y, t_env *env);
int	esc_hook(t_env *env);

#endif
