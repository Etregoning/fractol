/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:51:46 by etregoni          #+#    #+#             */
/*   Updated: 2017/08/23 14:17:34 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_error("Usage: ./fractol <fractal name>\n
				Available fractals: mandelbrot, julia");
	}

}
