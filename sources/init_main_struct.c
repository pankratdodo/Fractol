/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:31:48 by plettie           #+#    #+#             */
/*   Updated: 2020/03/16 19:30:49 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_comp			to_complex(int x, int y, t_view v)
{
	t_comp		p;

	p.re = (((double)x / WIDTH) * (v.xmax - v.xmin)) * v.zoom
		   + v.xmin + v.offx;
	p.im = (((double)y / HEIGHT) * (v.ymax - v.ymin)) * v.zoom
		   + v.ymin + v.offy;
	return (p);
}

void			*put_img(void *t)
{
	t_threads	*thr;

	thr = (t_threads *)t;
	(thr->data->type[JUL] == 1) ? do_jul(thr->data) : 0;
	(thr->data->type[MAND] == 1) ? do_mand(thr->data) : 0;
	(thr->data->type[HEART] == 1) ? do_heart(thr->data) : 0;
	mlx_clear_window(thr->data->mlx, thr->data->win);
	mlx_put_image_to_window(thr->data->mlx, thr->data->win,
			thr->data->image.img, 0, 0);

}

static int		close_app(void *param)
{
	(void)param;
	exit(0);
}

void			init_struct(t_main *data)
{
	if ((data->mlx = mlx_init()) && (data->win = mlx_new_window(data->mlx,
			WIDTH, HEIGHT,"Fractol")))
	{
		data->image.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		data->image.adr = (int*)mlx_get_data_addr(data->image.img, &data->image.bits,
				&data->image.size_line, &data->image.endian);
		mlx_hook(data->win, 2, (1L << 0) , key_hook, data);
		mlx_hook(data->win, 4, (1L << 2), mouse_click_hook, data);
		mlx_hook(data->win, 6, (1L << 6), mouse_move_hook, data);
		mlx_hook(data->win, 17, 0L, close_app, data);
	}
}
