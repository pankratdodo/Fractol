/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:32:05 by plettie           #+#    #+#             */
/*   Updated: 2020/03/10 18:32:09 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void			*on_crash(int err)
{
	(err == MALLOC_ERR) ? write(2, "Malloc error\n",
			ft_strlen("Malloc error\n")) : 0;
	(err == ERROR_CREATE_THREAD) ? ft_putstr_fd("Error create thread\n", 2) : 0;
	(err == ERROR_JOIN_THREAD) ? ft_putstr_fd("Error join thread\n", 2) : 0;
	exit(err);
}

static void		ft_destroy(t_data *data)
{
	t_img *image;

	image = &data->image;
	mlx_destroy_image(data->mlx, image->img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int				mouse_click_hook(int num_but, int x, int y, t_data *data)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (num_but == 1 && data->type[JUL] == 1)
			data->view.stop_mouse = !data->view.stop_mouse;
		else if (num_but == 4)
		{
			change_zoom(x, y, &data->view, 0.95f);
			data->view.iters -= data->view.iters < 10 ? 0 : 1;
		}
		else if (num_but == 5)
		{
			change_zoom(x, y, &data->view, 1 / 0.95f);
			data->view.iters += data->view.zoom < 9 ? 1 : 0;
		}
		thread_create(data);
	}
	return (0);
}

int				key_hook(int key, t_data *data)
{
	if (key == ESC)
		ft_destroy(data);
	else if (key == KEY_LEFT)
		change_fract_left(data);
	else if (key == KEY_RIGHT)
		change_fract_right(data);
	else if (key == KEY_UP)
		change_color_up(data);
	else if (key == KEY_DOWN)
		change_color_down(data);
	thread_create(data);
	return (0);
}

int				mouse_move_hook(int x, int y, t_data *fract)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && !fract->view.stop_mouse)
	{
		fract->view.mouse = to_complex(x, y, fract->view);
		thread_create(fract);
	}
	return (0);
}
