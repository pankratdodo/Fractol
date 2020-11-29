/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:31:48 by plettie           #+#    #+#             */
/*   Updated: 2020/09/12 15:46:14 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_comp			to_complex(int x, int y, t_view v)
{
	t_comp		p;

	p.re = (((double)x / WIDTH) * (v.xmax - v.xmin)) * v.zoom + v.xmin + v.offx;
	p.im = (((double)y / HEIGHT) * (v.ymax - v.ymin)) * v.zoom + v.ymin +
			v.offy;
	return (p);
}

void			*put_img(void *t)
{
	t_threads	*thr;

	thr = (t_threads *)t;
	(thr->data->type[JUL] == 1) ? do_jul(thr) : 0;
	(thr->data->type[MAND] == 1) ? do_mand(thr) : 0;
	(thr->data->type[HEART] == 1) ? do_heart(thr) : 0;
	(thr->data->type[BURN] == 1) ? do_burn(thr) : 0;
	(thr->data->type[MBAR] == 1) ? do_mbar(thr) : 0;
	(thr->data->type[CELTIC] == 1) ? do_celtic(thr) : 0;
	(thr->data->type[MAND5] == 1) ? do_mand5(thr) : 0;
	(thr->data->type[BURN5] == 1) ? do_burn5(thr) : 0;
	return (thr);
}

static int		close_app(void *param)
{
	(void)param;
	exit(0);
}

void			init_struct(t_data *data)
{
	if ((data->mlx = mlx_init()) && WIDTH > 0 && HEIGHT > 0)
	{
		if ((data->win = mlx_new_window(data->mlx,
										WIDTH, HEIGHT, "Fractol")))
		{
			data->image.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
			data->image.adr = (int *)mlx_get_data_addr(data->image.img,
					&data->image.bits, &data->image.size_line,
					&data->image.endian);
			mlx_hook(data->win, 2, (1L << 0), key_hook, data);
			mlx_hook(data->win, 4, (1L << 2), mouse_click_hook, data);
			mlx_hook(data->win, 6, (1L << 6), mouse_move_hook, data);
			mlx_hook(data->win, 17, 0L, close_app, data);
		}
	}
	else
		exit(-1);
}
