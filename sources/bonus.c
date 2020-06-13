//
// Created by lox on 13.06.2020.
//

#include "fract.h"

static void	change_fract(int *nul, int *one)
{
	*nul = 0;
	*one = 1;
}

void		change_color_down(t_main *data)
{
	if (data->view.def_color == RED_COLOR)
		data->view.def_color = BLUE_COLOR;
	else if (data->view.def_color == GREEN_COLOR)
		data->view.def_color = RED_COLOR;
	else if (data->view.def_color == BLUE_COLOR)
		data->view.def_color = GREEN_COLOR;
}

void		change_color_up(t_main *data)
{
	if (data->view.def_color == RED_COLOR)
		data->view.def_color = GREEN_COLOR;
	else if (data->view.def_color == GREEN_COLOR)
		data->view.def_color = BLUE_COLOR;
	else if (data->view.def_color == BLUE_COLOR)
		data->view.def_color = RED_COLOR;
}

void		change_fract_right(t_main *data)
{
	if (data->type[JUL] == 1)
		change_fract(&data->type[JUL], &data->type[MAND]);
	else if (data->type[MAND] == 1)
		change_fract(&data->type[MAND], &data->type[HEART]);
	else if (data->type[HEART] == 1)
		change_fract(&data->type[HEART], &data->type[JUL]);
}

void		change_fract_left(t_main *data)
{
	if (data->type[JUL] == 1)
		change_fract(&data->type[JUL], &data->type[HEART]);
	else if (data->type[MAND] == 1)
		change_fract(&data->type[MAND], &data->type[JUL]);
	else if (data->type[HEART] == 1)
		change_fract(&data->type[HEART], &data->type[MAND]);
}