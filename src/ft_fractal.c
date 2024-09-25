/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:19:38 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/02 17:23:12 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fractol.h"

void	ft_tricorn(t_fractal *f)
{
	double	temp;

	f->c.real = (f->x - WIDTH / 2.0) * f->zoom / WIDTH + f->xmv;
	f->c.imag = (f->y - HEIGHT / 2.0) * f->zoom / HEIGHT + f->ymv;
	f->z.real = 0;
	f->z.imag = 0;
	f->i = 0;
	f->depth = 0;
	while (f->z.real * f->z.real + f->z.imag * f->z.imag < (2)
		&& f->i < f->max_iteration)
	{
		temp = f->z.real * f->z.real - f->z.imag * f->z.imag + f->c.real;
		f->z.imag = -2.0 * f->z.real * f->z.imag + f->c.imag;
		if (f->z.real == temp && f->i == f->z.imag)
		{
			f->depth = f->i;
			f->i = f->max_iteration;
			break ;
		}
		f->z.real = temp;
		f->i += 1;
		f->depth = f->i;
	}
	ft_put_pixel(f);
}

void	ft_ship(t_fractal *f)
{
	double	temp;

	f->c.real = (f->x - WIDTH / 2.0) * f->zoom / WIDTH + f->xmv;
	f->c.imag = (f->y - HEIGHT / 2.0) * f->zoom / HEIGHT + f->ymv;
	f->z.real = 0;
	f->z.imag = 0;
	f->i = 0;
	f->depth = 0;
	while (f->z.real * f->z.real + f->z.imag * f->z.imag < (2)
		&& f->i < f->max_iteration)
	{
		temp = f->z.real * f->z.real - f->z.imag * f->z.imag + f->c.real;
		f->z.imag = (fabs(2.0 * f->z.real * f->z.imag)) + f->c.imag;
		if (f->z.real == temp && f->i == f->z.imag)
		{
			f->depth = f->i;
			f->i = f->max_iteration;
			break ;
		}
		f->z.real = temp;
		f->i += 1;
		f->depth = f->i;
	}
	ft_put_pixel(f);
}

void	ft_mandelbrot(t_fractal *f)
{
	double	temp;

	f->c.real = (f->x - WIDTH / 2.0) * f->zoom / WIDTH + f->xmv;
	f->c.imag = (f->y - HEIGHT / 2.0) * f->zoom / HEIGHT + f->ymv;
	f->z.real = 0;
	f->z.imag = 0;
	f->i = 0;
	f->depth = 0;
	while (f->z.real * f->z.real + f->z.imag * f->z.imag < (2)
		&& f->i < f->max_iteration)
	{
		temp = f->z.real * f->z.real - f->z.imag * f->z.imag + f->c.real;
		f->z.imag = 2.0 * f->z.real * f->z.imag + f->c.imag;
		if (f->z.real == temp && f->i == f->z.imag)
		{
			f->depth = f->i;
			f->i = f->max_iteration;
			break ;
		}
		f->z.real = temp;
		f->i += 1;
		f->depth = f->i;
	}
	ft_put_pixel(f);
}

void	ft_julia(t_fractal *f)
{
	double	temp;

	f->z.real = (f->x - WIDTH / 2.0) * f->zoom / WIDTH + f->xmv;
	f->z.imag = (f->y - HEIGHT / 2.0) * f->zoom / HEIGHT + f->ymv;
	f->c.real = f->julia_arguments.real;
	f->c.imag = f->julia_arguments.imag;
	f->i = 0;
	f->depth = 0;
	while (f->z.real * f->z.real + f->z.imag * f->z.imag < (2)
		&& f->i < f->max_iteration)
	{
		temp = f->z.real * f->z.real - f->z.imag * f->z.imag + f->c.real;
		f->z.imag = 2.0 * f->z.real * f->z.imag + f->c.imag;
		if (f->z.real == temp && f->i == f->z.imag)
		{
			f->depth = f->i;
			f->i = f->max_iteration;
			break ;
		}
		f->z.real = temp;
		f->i += 1;
		f->depth = f->i;
	}
	ft_put_pixel(f);
}
