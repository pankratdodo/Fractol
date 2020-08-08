/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mand5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:23:34 by plettie           #+#    #+#             */
/*   Updated: 2020/08/08 18:23:38 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void		formula_mand5(t_data *data, int x, int y)
{
	t_comp		main;
	t_comp		temp;
	t_comp		ne_mouse;
	int			i;

	i = -1;
	ne_mouse = to_complex(x, y, data->view);
	main = ne_mouse;
	while (pow(main.re, 2) + pow(main.im, 2) <= 4 && ++i < data->view.iters)
	{
		temp.re = main.re * (pow(main.re, 4) - 10 * pow(main.re, 2) *
				pow(main.im, 2) + 5 * pow(main.im, 4)) + ne_mouse.re;
		temp.im = main.im * (5 * pow(main.re, 4) - 10 * pow(main.re, 2)
				* pow(main.im, 2) + pow(main.im, 4)) + ne_mouse.im;
		main = temp;
	}
	data->image.adr[x + y * WIDTH] = (i ==
			data->view.iters) ? 0 : data->view.def_color * i;
}

void			init_mand5(t_data *data)
{
	data->type[MAND5] = 1;
	data->view.xmin = -2.0f;
	data->view.xmax = 1.0f;
	data->view.ymin = -1.0f;
	data->view.ymax = 1.0f;
	data->view.offx = 0.4f;
	data->view.offy = -0.1f;
	data->view.zoom = 1.1f;
	data->view.iters = 50;
}

void			do_mand5(t_threads *thr)
{
	int			x;
	int			y;

	y = thr->hight * thr->id - 1;
	while (++y < thr->hight * (thr->id + 1) && (x = -1))
		while (++x < WIDTH)
			formula_mand5(thr->data, x, y);
}
