//
// Created by lox on 13.06.2020.
//

#ifndef INC_2_FRACT_H
#define INC_2_FRACT_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <mlx.h>
# include "libft.h"

# define WIDTH 1000
# define HEIGHT 700
# define ESC 0xff1b
# define KEY_UP 0xff52
# define KEY_DOWN 0xff54
# define KEY_LEFT 0xff51
# define KEY_RIGHT 0xff53
# define RED_COLOR 0x0A0505
# define GREEN_COLOR 0x050A05
# define BLUE_COLOR 0x05050A
# define NUM_THREADS 16

enum				e_err
{
	MALLOC_ERR = 0,
	ERROR_CREATE_THREAD,
	ERROR_JOIN_THREAD
};

enum				e_type
{
	JUL = 0,
	MAND,
	HEART,
	ELEMENTS
};

typedef struct		s_comp
{
	double			re;
	double			im;
}					t_comp;

typedef struct		s_view
{
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	double			zoom;
	double			offx;
	double			offy;
	long			iters;
	t_comp			mouse;
	int 			stop_mouse;
	int 			def_color;
}					t_view;

typedef struct		s_img
{
	void			*img;
	int				*adr;
	int				bits;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_main
{
	void			*mlx;
	void			*win;
	t_img			image;
	int 			type[ELEMENTS];
	t_view			view;
}					t_main;

typedef	struct		s_threads
{
	int 			id;
	t_main			*data;
}					t_threads;

void				init_struct(t_main *data);
void				*put_img(void *t);
t_comp				to_complex(int x, int y, t_view v);
void				*on_crash(int err);

int					mouse_move_hook(int x, int y, t_main *fract);
int					key_hook(int key, t_main *data);
int 				mouse_click_hook(int num_but, int x, int y, t_main *data);

void				change_zoom(int x, int y, t_view *view, double d);

void				change_fract_left(t_main *data);
void				change_fract_right(t_main *data);
void				change_color_up(t_main *data);
void				change_color_down(t_main *data);

void				do_jul(t_main *fract);
void				do_mand(t_main *data);
void				do_heart(t_main *data);

void				thread_create(t_main *data);

#endif
