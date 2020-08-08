/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:48:44 by plettie           #+#    #+#             */
/*   Updated: 2020/03/01 22:05:08 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	change_fract(int *nul, void init(t_data *), t_data *data)
{
	*nul = 0;
	init(data);
}

void		change_color_down(t_data *data)
{
	if (data->view.def_color == RED_COLOR)
		data->view.def_color = BLUE_COLOR;
	else if (data->view.def_color == GREEN_COLOR)
		data->view.def_color = RED_COLOR;
	else if (data->view.def_color == BLUE_COLOR)
		data->view.def_color = GREEN_COLOR;
}

void		change_color_up(t_data *data)
{
	if (data->view.def_color == RED_COLOR)
		data->view.def_color = GREEN_COLOR;
	else if (data->view.def_color == GREEN_COLOR)
		data->view.def_color = BLUE_COLOR;
	else if (data->view.def_color == BLUE_COLOR)
		data->view.def_color = RED_COLOR;
}

void		change_fract_right(t_data *data)
{
	if (data->type[JUL] == 1)
		change_fract(&data->type[JUL], init_mand, data);
	else if (data->type[MAND] == 1)
		change_fract(&data->type[MAND], init_heart, data);
	else if (data->type[HEART] == 1)
		change_fract(&data->type[HEART], init_burn, data);
	else if (data->type[BURN] == 1)
		change_fract(&data->type[BURN], init_mbar, data);
	else if (data->type[MBAR] == 1)
		change_fract(&data->type[MBAR], init_celtic, data);
	else if (data->type[CELTIC] == 1)
		change_fract(&data->type[CELTIC], init_mand5, data);
	else if (data->type[MAND5] == 1)
		change_fract(&data->type[MAND5], init_burn5, data);
	else if (data->type[BURN5] == 1)
		change_fract(&data->type[BURN5], init_julia, data);
}

void		change_fract_left(t_data *data)
{
	if (data->type[JUL] == 1)
		change_fract(&data->type[JUL], init_burn5, data);
	else if (data->type[MAND] == 1)
		change_fract(&data->type[MAND], init_julia, data);
	else if (data->type[HEART] == 1)
		change_fract(&data->type[HEART], init_mand, data);
	else if (data->type[BURN] == 1)
		change_fract(&data->type[BURN], init_heart, data);
	else if (data->type[MBAR] == 1)
		change_fract(&data->type[MBAR], init_burn, data);
	else if (data->type[CELTIC] == 1)
		change_fract(&data->type[CELTIC], init_mbar, data);
	else if (data->type[MAND5] == 1)
		change_fract(&data->type[MAND5], init_celtic, data);
	else if (data->type[BURN5] == 1)
		change_fract(&data->type[BURN5], init_mand5, data);
}
