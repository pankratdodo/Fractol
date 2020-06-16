/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:48:44 by plettie           #+#    #+#             */
/*   Updated: 2020/03/01 22:05:08 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void		formula_julia(t_data *data, int x, int y)
{
	t_comp		main;
	t_comp		temp;
	int			i;

	main = to_complex(x, y, data->view);
	i = -1;
	while (pow(main.re, 2) + pow(main.im, 2) < 256 && ++i < data->view.iters)
	{
		temp.re = pow(main.re, 2) - pow(main.im, 2) + data->view.mouse.re;
		temp.im = main.re * main.im * 2 + data->view.mouse.im;
		main = temp;
	}
	data->image.adr[x + y * WIDTH] = (i ==
			data->view.iters) ? 0 : data->view.def_color * i;
}

void			init_julia(t_data *data)
{
	data->type[JUL] = 1;
	data->view.xmin = -2.0f;
	data->view.xmax = 1.0f;
	data->view.ymin = -1.0f;
	data->view.ymax = 1.0f;
	data->view.offx = -0.88f;
	data->view.offy = -1.0f;
	data->view.zoom = 1.92f;
	data->view.iters = 50;
	data->view.mouse.re = -0.6;
	data->view.mouse.im = -0.5;
}

void			do_jul(t_threads *thr)
{
	int			x;
	int			y;

	y = thr->hight * thr->id - 1;
	while (++y < thr->hight * (thr->id + 1) && (x = -1))
		while (++x < WIDTH)
			formula_julia(thr->data, x, y);
}
