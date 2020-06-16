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
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
	data->type[JUL] == 1 ? mlx_string_put(data->mlx, data->win,
			10, 1070, 0x808080, "Push left mouse but to stop move") : 0;
	mlx_string_put(data->mlx, data->win, 10, 890, 0,
			"Push 'ESC' to exit");
	mlx_string_put(data->mlx, data->win, 10, 910, 0x808080,
			"Push 'LEFT' and 'RIGHT' to change fractal");
	mlx_string_put(data->mlx, data->win, 10, 930, 0x808080,
			"Push 'UP' and 'DOWN' to change color");
	mlx_string_put(data->mlx, data->win, 10, 950, 0x808080,
			"Scroll up to increase the global size of the fractal");
	mlx_string_put(data->mlx, data->win, 10, 970, 0x808080,
			"Scroll down to decrease the global size of the fractal");
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
