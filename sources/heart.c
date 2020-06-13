//
// Created by lox on 11.06.2020.
//

#include "fract.h"

static void		formula_heart(t_main *data, int x, int y)
{
	t_comp		main;
	t_comp		temp;
	t_comp		ne_mouse;
	int 		i;

	i = -1;
	ne_mouse = to_complex(x, y, data->view);
	main = ne_mouse;
	while (pow(main.re, 2) + pow(main.im, 2) <= 256 && ++i < data->view.iters)
	{
		temp.re = pow(main.re, 2) - pow(main.im, 2) + ne_mouse.re;
		temp.im = fabs(main.re) * main.im * 2 + ne_mouse.im;
		main = temp;
	}
	data->image.adr[x + y * WIDTH] = (i == data->view.iters) ? 0 : data->view.def_color * i;
}

static void		init_heart(t_main *data)
{
	data->view.xmin = -2.0f;
	data->view.xmax = 1.0f;
	data->view.ymin = -1.0f;
	data->view.ymax = 1.0f;
	data->view.offx = -0.88f;
	data->view.offy = -1.0f;
	data->view.zoom = 1.75f;
	data->view.iters = 50;
}

void			do_heart(t_main *data)
{
	int			x;
	int			y;

	y = -1;
	init_heart(data);
	while (++y < HEIGHT && (x = -1))
		while (++x < WIDTH)
			formula_heart(data, x, y);
}
