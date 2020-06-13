//
// Created by lox on 11.06.2020.
//

#include "fract.h"

static void		formula_julia(t_main *data, int x, int y)
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
	data->image.adr[x + y * WIDTH] = (i == data->view.iters) ? 0 : data->view.def_color * i;
}

static void		init_julia(t_main *data)
{
	data->view.xmin = -2.0f;
	data->view.xmax = 1.0f;
	data->view.ymin = -1.0f;
	data->view.ymax = 1.0f;
	data->view.offx = -0.88f;
	data->view.offy = -1.0f;
	data->view.zoom= 1.92f;
	data->view.iters = 50;
	data->view.mouse.re = -0.6;
	data->view.mouse.im = -0.5;
}

void			do_jul(t_main *fract)
{
	int			x;
	int			y;

	y = -1;
	init_julia(fract);
	while (++y < HEIGHT && (x = -1))
		while (++x < WIDTH)
			formula_julia(fract, x, y);
}
