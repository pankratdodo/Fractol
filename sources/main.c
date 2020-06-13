/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:48:44 by crycherd          #+#    #+#             */
/*   Updated: 2020/03/01 22:05:08 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void		*on_crash(int err)
{
	(err == MALLOC_ERR) ? write(2, "Malloc error\n",
			ft_strlen("Malloc error\n")) : 0;
	(err == ERROR_CREATE_THREAD) ? ft_putstr_fd("Error create thread\n", 2) : 0;
	(err == ERROR_JOIN_THREAD) ? ft_putstr_fd("Error join thread\n", 2) : 0;
	exit(err);
}

static void		print_error(int i, int code)
{
	if (i == 1)
		ft_putstr_fd("Enter one name\n", 2);
	if (i == 2)
	{
		ft_putstr_fd("usage: ./fractol *name of fractal*\n", 2);
		ft_putstr_fd("Allowed names: julia, mandelbrot, heart\n", 2);
	}
	exit(code);
}


static int 		check_param(char *str, t_main *fract)
{
	int 	i;
	char	*new;

	i = -1;
	if (!(new = ft_memalloc(ft_strlen(str) + 1)))
		on_crash(MALLOC_ERR);
	while (str[++i])
	{
		if (str[i] > 64 && str[i] < 91)
			new[i] = (char)ft_tolower(str[i]);
		else
			new[i] = str[i];
	}
	new[i] = '\0';
	if (!ft_strcmp(new, "julia"))
		fract->type[JUL] = 1;
	else if (!ft_strcmp(new, "mandelbrot"))
		fract->type[MAND] = 1;
	else if (!ft_strcmp(new, "heart"))
		fract->type[HEART] = 1;
	else
	{
		free(new);
		return (0);
	}
	free(new);
	return (1);
}

static void		init_type(t_main *data)
{
	data->type[JUL] = 0;
	data->type[MAND] = 0;
	data->type[HEART] = 0;
	data->view.def_color = RED_COLOR;
	data->view.stop_mouse = 0;
}

int				main(int ac, char **av)
{
	t_main	fract;

	if (ac != 2)
		print_error(1, 0);
	init_type(&fract);
	if (!check_param(av[1], &fract))
		print_error(2, 0);
	init_struct(&fract);
	thread_create(&fract);
	//put_img(&fract);
	mlx_loop(fract.mlx);
	return (0);
}
