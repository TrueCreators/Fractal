/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:58:08 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/30 15:29:11 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <OpenCL/opencl.h>

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <time.h>
# define MAX_SOURCE_SIZE (0x400000)
# define RGB(r, g, b) (r << 16 | g << 8 | b)

enum		e_mkey
{
	MK_LEFT = 1,
	MK_RIGHT,
	MK_SCRLUP = 4,
	MK_SCRLDOWN
};
enum		e_nkey
{
	NK_PLUS = 69,
	NK_MINUS = 78,
	NK_N0 = 82,
	NK_N1,
	NK_N2,
	NK_N3,
	NK_N4,
	NK_N5,
	NK_N6,
	NK_N7,
	NK_N8 = 91,
	NK_N9
};
enum		e_key
{
	K_A = 0,
	K_S,
	K_D,
	K_W = 13,
	K_ESC = 53,
	K_LEFT = 123,
	K_RIGHT,
	K_DOWN,
	K_UP,
	K_PLUS = 24,
	K_MINUS = 27,
	K_BACKSPACE = 51,
	K_H = 4
};

typedef struct			s_win
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					x_win;
	int					y_win;
	char				*n_win;
}						t_win;

typedef struct			s_mov
{
	double				ju_cre;
	double				ju_cim;
	double				zoom;
	double				move_x;
	double				move_y;
	int					maxiter;
}						t_mov;

typedef struct			s_img
{
	void				*img_ptr;
	int					*data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_img;

typedef struct			s_rgb
{
	int					r;
	int					g;
	int					b;
}						t_rgb;

typedef struct			s_ker
{
	cl_mem				memobj;
	cl_kernel			kernel;
	cl_context			context;
	cl_program			program;
	cl_device_id		device;
	cl_command_queue	command;
}						t_ker;

typedef struct			s_imgbut
{
	void				*img_ptr;
	int					*data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_imgbut;

typedef	struct			s_butt
{
	int					size_x;
	int					size_y;
	int					pos_x;
	int					pos_y;
	char				*text;
	int					color_button;
	int					color_text;
}						t_butt;

typedef struct			s_flag
{
	int					mouse;
	int					menu_glb;
	int					menu;
	int					move_menu;
	int					background;
	int					change_fractol;
	int					settings;
	int					controls;
	int					color;
	int					helpingame;
}						t_flag;

typedef struct			s_env
{
	char				*fractol;
	t_win				*win;
	t_mov				*mov;
	t_img				*img;
	t_rgb				*rgb;
	t_ker				*kernel;
	t_imgbut			img_butt;
	t_butt				*button;
	t_flag				flag;
}						t_env;

int						key_press(int keycode, t_env *e);
int						key_change_window(int keycode, t_env *e);
int						manipulate(int keycode, t_env *e);
int						move(int keycode, t_env *e);
int						changecolor(int keycode, t_env *e);
int						close_programm(void *param);
int						mouse_press(int	button, int x, int y, t_env *e);
int						mouse_move(int x, int y, t_env *e);
int						rgb2hex(int r, int g, int b);

int						animation_menu(t_env *e);
void					color_menu(t_env *e, int i);
void					init_menu(t_env *e, int x_win, int y_win);
void					init_menu_press(t_env *e, int x_win, int y_win);
void					main_menu(t_env *e);
void					menu_text(t_env *e);
void					help(t_env *e);

void					button_play_canvas(t_env *e);
void					button_change_fractol_canvas(t_env *e);
void					button_settings_e_canvas(t_env *e);

void					button_set_mandelbrot(t_env *e);
void					button_set_julia(t_env *e);
void					button_set_pyramide(t_env *e);
void					button_set_puddle(t_env *e);
void					button_set_time_machine(t_env *e);
void					button_set_bracelet(t_env *e);
void					button_set_butterfly(t_env *e);
void					button_set_spider(t_env *e);

void					create_button(t_env *e, t_butt *butt);
void					button_pressed(int button, int x, int y, t_env *e);

void					create_kernel(t_ker *kernel, t_env *e);
void					start_kernel(t_ker *kernel, t_env *e);
void					set_kernel_arg(t_ker *kernel, t_env *e, int i);
void					init_kernel(t_ker *kernel, t_env *e);

void					draw(t_env *e);
void					fractol_selection(t_env *e);
void					init_win_img(t_env *e);
void					pyramide(t_win *win, t_mov *mov,
						t_img *img, t_rgb *rgb);
void					julia(t_win *win, t_mov *mov,
						t_img *img, t_rgb *rgb);
void					mandelbrot(t_win *win, t_mov *mov,
						t_img *img, t_rgb *rgb);
void					puddle(t_win *win, t_mov *mov, t_img *img, t_rgb *rgb);
void					error_exit(char *str);
void					fractol(char *fractol);
void					faq_message(void);
#endif
