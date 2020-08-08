/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:48:44 by plettie           #+#    #+#             */
/*   Updated: 2020/03/01 22:05:08 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <mlx.h>

# define WIDTH 1000
# define HEIGHT 700
# define ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define RED_COLOR 0x0A0505
# define GREEN_COLOR 0x050A05
# define BLUE_COLOR 0x05050A

# define NUM_THREADS 16

typedef struct s_data	t_data;

enum					e_err
{
	MALLOC_ERR = 0,
	ERROR_CREATE_THREAD,
	ERROR_JOIN_THREAD
};

enum					e_type
{
	JUL = 0,
	MAND,
	HEART,
	BURN,
	MBAR,
	CELTIC,
	MAND5,
	BURN5,
	ELEMENTS
};

typedef struct			s_comp
{
	double				re;
	double				im;
}						t_comp;

typedef struct			s_view
{
	double				xmin;
	double				xmax;
	double				ymin;
	double				ymax;
	double				zoom;
	double				offx;
	double				offy;
	long				iters;
	t_comp				mouse;
	int					stop_mouse;
	int					def_color;
}						t_view;

typedef struct			s_img
{
	void				*img;
	int					*adr;
	int					bits;
	int					size_line;
	int					endian;
}						t_img;

typedef	struct			s_threads
{
	int					id;
	int					hight;
	t_data				*data;
}						t_threads;

typedef struct			s_put
{
	pthread_t			thread[NUM_THREADS];
	t_threads			args[NUM_THREADS];
}						t_put;

struct					s_data
{
	void				*mlx;
	void				*win;
	t_img				image;
	int					type[ELEMENTS];
	t_view				view;
	t_put				thr;
};

void					init_struct(t_data *data);
void					*put_img(void *t);
t_comp					to_complex(int x, int y, t_view v);
void					*on_crash(int err);

int						mouse_move_hook(int x, int y, t_data *fract);
int						key_hook(int key, t_data *data);
int						mouse_click_hook(int num_but, int x, int y,
							t_data *data);

void					change_zoom(int x, int y, t_view *view, double d);
void					ft_menu(t_data *data);

void					change_fract_left(t_data *data);
void					change_fract_right(t_data *data);
void					change_color_up(t_data *data);
void					change_color_down(t_data *data);

void					do_jul(t_threads *thr);
void					init_julia(t_data *data);

void					do_mand(t_threads *thr);
void					init_mand(t_data *data);

void					do_heart(t_threads *thr);
void					init_heart(t_data *data);

void					do_burn(t_threads *thr);
void					init_burn(t_data *data);

void					do_mbar(t_threads *thr);
void					init_mbar(t_data *data);

void			        do_celtic(t_threads *thr);
void			        init_celtic(t_data *data);

void			        do_mand5(t_threads *thr);
void			        init_mand5(t_data *data);

void			        do_burn5(t_threads *thr);
void			        init_burn5(t_data *data);

void					thread_create(t_data *data);

size_t		            ft_strlen(const char *str);
void	                ft_putstr_fd(char const *s, int fd);
void	                *ft_memalloc(size_t size);
int                     ft_strcmp(const char *s1, const char *s2);
int                     ft_tolower(int item);
void	                ft_putchar_fd(char c, int fd);
void	                ft_bzero(void *s, size_t n);
char					**ft_strsplit(char const *s, char c);

#endif
