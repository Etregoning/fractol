/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:51:46 by etregoni          #+#    #+#             */
/*   Updated: 2017/08/23 14:27:20 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void usage(void)
{
	ft_error("Usage: ./fractol <fractal name>\n\n"
						"Available fractals: Mandelbrot, Julia");
}

int	main(int ac, char **av)
{
	void	*mlx;
	t_env	*env;

	if (ac != 2)
		usage();
	mlx = mlx_init();
	env =	make_environment(mlx);
	if (ft_strcmp(av[1], "Mandelbrot") == 0 || ft_strcmp(av[1], "mandelbrot") == 0)
		env->arg = 1;
	else if (ft_strcmp(av[1], "Julia") == 0 || ft_strcmp(av[1], "julia") == 0)
		env->arg = 2;
	else if (ft_strcmp(av[1], "Third") == 0 || ft_strcmp(av[1], "third") == 0)
		env->arg = 3;
	else
		usage();
	create_image(env);
	env->win = mlx_new_window(mlx, env->width, env->height, "Fractal Viewer");
	set_hooks(env);
	mlx_loop_hook(mlx, loop_hook, env);
	mlx_loop(mlx);
}
