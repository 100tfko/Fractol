/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:49:46 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/03 15:24:34 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*---------------------------------   LIBS   ---------------------------------*/
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <memory.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*--------------------------------   MACROS   --------------------------------*/
/*SIZE*/
# define HEIGHT 900
# define WIDTH 900
//ERORS
# define MLX_ERROR 1
# define IMG_ERROR 2

/*--------------------------------   STRUCTS   -------------------------------*/

typedef struct s_rgb
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_rgb;

typedef struct s_complexnb
{
	double	real;
	double	imag;
}	t_complexnb;

typedef struct s_fractal
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	char				*name;
	int					color_mode;
	double				zoom;
	double				xmv;
	double				ymv;
	int					max_iteration;
	int					x;
	int					y;
	int					f_slect;
	int					i;
	int					depth;
	t_complexnb			z;
	t_complexnb			c;
	t_complexnb			julia_arguments;
}	t_fractal;

/*-------------------------------   FUNCTIONS   ------------------------------*/

// main file
int				main(int argc, char **argv);
void			ft_fractol(t_fractal *f);
void			ft_openwindow(t_fractal *f);
void			ft_put_pixel(t_fractal *f);

// aux file
void			ft_check_arg(int argc, char **argv, t_fractal *f);
int_fast32_t	ft_check_double(const char *nb);
void			ft_initiate_f(t_fractal *f);
void			ft_select_fractal(t_fractal *f);

// error file
void			ft_control(void);
void			ft_control_2(void);
void			ft_error_manual(void);
void			ft_error(int error, t_fractal *f);

// fractals file

void			ft_julia(t_fractal *f);
void			ft_mandelbrot(t_fractal *f);
void			ft_tricorn(t_fractal *f);
void			ft_ship(t_fractal *f);

// color file
uint32_t		rgb(t_rgb color);
t_rgb			ft_color(t_fractal *f, double l);
void			ft_color_mode(t_fractal *f, t_rgb *rgb, double l);

//hook file
void			ft_hook(void *param);
void			ft_key_control(t_fractal *f);
void			ft_key_hook(mlx_key_data_t keydata, void *param);
void			ft_julia_param_mod(t_fractal *f);
void			ft_scroll_hook(double xdelta, double ydelta, void *param);

#endif
