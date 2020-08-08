/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:50:17 by plettie           #+#    #+#             */
/*   Updated: 2020/03/10 20:50:20 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_menu(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 10, HEIGHT - 130, 0x808080,
			"Push 'ESC' to exit");
	mlx_string_put(data->mlx, data->win, 10, HEIGHT - 110, 0x808080,
			"Push 'LEFT' and 'RIGHT' to change fractal");
	mlx_string_put(data->mlx, data->win, 10, HEIGHT - 90, 0x808080,
			"Push 'UP' and 'DOWN' to change color");
	mlx_string_put(data->mlx, data->win, 10, HEIGHT - 70, 0x808080,
			"Scroll up to increase the global size of the fractal");
	mlx_string_put(data->mlx, data->win, 10, HEIGHT - 50, 0x808080,
			"Scroll down to decrease the global size of the fractal");
	data->type[JUL] == 1 ? mlx_string_put(data->mlx, data->win,
			10, HEIGHT - 30, 0x808080, "Push left mouse but to stop move") : 0;
}

void	change_zoom(int x, int y, t_view *view, double d)
{
	double		x_temp;
	double		y_temp;

	x_temp = (view->xmax - view->xmin) * view->zoom * (d - 1);
	y_temp = (view->ymax - view->ymin) * view->zoom * (d - 1);
	view->zoom *= d;
	view->offx -= ((double)x / WIDTH) * x_temp;
	view->offy -= ((double)y / HEIGHT) * y_temp;
}
