/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:06:05 by plettie           #+#    #+#             */
/*   Updated: 2020/08/08 18:06:12 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void		formula_celtic(t_data *data, int x, int y)
{
	t_comp		main;
	t_comp		temp;
	t_comp		ne_mouse;
	int			i;

	i = -1;
	ne_mouse = to_complex(x, y, data->view);
	main = ne_mouse;
	while (pow(main.re, 2) + pow(main.im, 2) <= 256 && ++i < data->view.iters)
	{
		temp.re = fabs(pow(main.re, 2) - pow(main.im, 2)) + ne_mouse.re;
		temp.im = -2 * fabs(main.re) * main.im + ne_mouse.im;
		main = temp;
	}
	data->image.adr[x + y * WIDTH] = (i ==
			data->view.iters) ? 0 : data->view.def_color * i;
}

void			init_celtic(t_data *data)
{
	data->type[CELTIC] = 1;
	data->view.xmin = -2.0f;
	data->view.xmax = 1.0f;
	data->view.ymin = -1.0f;
	data->view.ymax = 1.0f;
	data->view.offx = -1.0f;
	data->view.offy = -0.8f;
	data->view.zoom = 1.75f;
	data->view.iters = 50;
}

void			do_celtic(t_threads *thr)
{
	int			x;
	int			y;

	y = thr->hight * thr->id - 1;
	while (++y < thr->hight * (thr->id + 1) && (x = -1))
		while (++x < WIDTH)
			formula_celtic(thr->data, x, y);
}
