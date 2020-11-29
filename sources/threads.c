/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:48:44 by plettie           #+#    #+#             */
/*   Updated: 2020/09/12 15:46:39 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void		thread_create(t_data *data)
{
	int			id;
	t_put		*put;

	id = -1;
	put = &data->thr;
	while (++id < NUM_THREADS)
	{
		put->args[id].id = id;
		put->args[id].data = data;
		put->args[id].hight = data->thr.args->hight;
		if (pthread_create(&(put->thread[id]), NULL, put_img, &put->args[id]))
			on_crash(ERROR_CREATE_THREAD);
	}
	while (id-- > 0)
		if (pthread_join(put->thread[id], NULL))
			on_crash(ERROR_JOIN_THREAD);
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
	ft_menu(data);
}
