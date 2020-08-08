/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:20:39 by plettie           #+#    #+#             */
/*   Updated: 2020/08/08 18:20:44 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void		print_error(int i, int code)
{
	if (i == 1)
		ft_putstr_fd("Enter one name\n", 2);
	if (i == 2)
	{
		ft_putstr_fd("usage: ./fractol *name of fractal*\n", 2);
		ft_putstr_fd("Allowed names: julia, mandelbrot, heart, ", 2);
		ft_putstr_fd("burning, mandelbar, celtic, mand5, burn5\n", 2);
	}
	exit(code);
}

static int		init_fract(char *new, t_data *fract)
{
	if (!ft_strcmp(new, "julia"))
		init_julia(fract);
	else if (!ft_strcmp(new, "mandelbrot"))
		init_mand(fract);
	else if (!ft_strcmp(new, "heart"))
		init_heart(fract);
	else if (!ft_strcmp(new, "burning"))
		init_burn(fract);
	else if (!ft_strcmp(new, "mandelbar"))
		init_mbar(fract);
	else if (!ft_strcmp(new, "celtic"))
		init_celtic(fract);
	else if (!ft_strcmp(new, "mand5"))
		init_mand5(fract);
	else if (!ft_strcmp(new, "burn5"))
		init_burn5(fract);
	else
		return (0);
	return (1);
}

static int		check_param(char *str, t_data *fract)
{
	int		i;
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
	if (!init_fract(new, fract))
	{
		free(new);
		return (0);
	}
	free(new);
	return (1);
}

static void		init_type(t_data *data)
{
	data->type[JUL] = 0;
	data->type[MAND] = 0;
	data->type[HEART] = 0;
	data->type[BURN] = 0;
	data->type[MBAR] = 0;
	data->type[CELTIC] = 0;
	data->type[MAND5] = 0;
	data->type[BURN5] = 0;
	data->view.def_color = RED_COLOR;
	data->view.stop_mouse = 0;
	data->thr.args->hight = HEIGHT / NUM_THREADS;
}

int				main(int ac, char **av)
{
	t_data	fract;

	if (ac != 2)
		print_error(1, 0);
	init_type(&fract);
	if (!check_param(av[1], &fract))
		print_error(2, 0);
	init_struct(&fract);
	thread_create(&fract);
	mlx_loop(fract.mlx);
	return (0);
}
