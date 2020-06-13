/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:50:17 by plettie           #+#    #+#             */
/*   Updated: 2020/03/10 20:50:20 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	change_zoom(int x, int y, t_view *view, double d)
{
	double		x_temp;
	double		y_temp;

	x_temp = (view->xmax - view->xmin) * view->zoom * (d - 1);
	y_temp = (view->ymax - view->ymin) * view->zoom * (d - 1);
	view->zoom *= d;
	view->offx -= ((double)x / WIDTH) * x_temp;
	view->offy -= ((double)y /HEIGHT) * y_temp;
}
