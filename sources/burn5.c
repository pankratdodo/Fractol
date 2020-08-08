/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:04:55 by plettie           #+#    #+#             */
/*   Updated: 2020/08/08 18:04:58 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void		formula_burn5(t_data *data, int x, int y)
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
		temp.re = fabs(main.re) * (pow(main.re, 4) - 10 * pow(main.re, 2)
				* pow(main.im, 2) + 5 * pow(main.im, 4)) + ne_mouse.re;
		temp.im = main.im * (5 * pow(main.re, 4) - 10 * pow(main.re, 2) *
				pow(main.im, 2) + pow(main.im, 4)) + ne_mouse.im;
		main = temp;
	}
	data->image.adr[x + y * WIDTH] = (i ==
			data->view.iters) ? 0 : data->view.def_color * i;
}

void			init_burn5(t_data *data)
{
	data->type[BURN5] = 1;
	data->view.xmin = -2.0f;
	data->view.xmax = 1.0f;
	data->view.ymin = -1.0f;
	data->view.ymax = 1.0f;
	data->view.offx = 0.0f;
	data->view.offy = -0.3f;
	data->view.zoom = 1.3f;
	data->view.iters = 50;
}

void			do_burn5(t_threads *thr)
{
	int			x;
	int			y;

	y = thr->hight * thr->id - 1;
	while (++y < thr->hight * (thr->id + 1) && (x = -1))
		while (++x < WIDTH)
			formula_burn5(thr->data, x, y);
}
