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
	ft_error("Usage: ./fractol <fractal name>\n\nAvailable fractals: "
						"mandelbrot, julia, julia_cubed, burning_ship, carpet");
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
	else if (ft_strcmp(av[1], "Burning_Ship") == 0 || ft_strcmp(av[1], "burning_ship") == 0)
		env->arg = 3;
	else if (ft_strcmp(av[1], "Carpet") == 0 || ft_strcmp(av[1], "carpet") == 0)
		env->arg = 4;
	else if (ft_strcmp(av[1], "Julia_cubed") == 0 || ft_strcmp(av[1], "julia_cubed") == 0)
		env->arg = 5;
	else
		usage();
	create_image(env);
	env->win = mlx_new_window(mlx, env->width, env->height, "Fractal Viewer");
	set_hooks(env);
	mlx_loop_hook(mlx, loop_hook, env);
	mlx_loop(mlx);
}
