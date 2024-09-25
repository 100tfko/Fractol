/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:14:31 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/02 17:23:05 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fractol.h"

void	ft_color_mode(t_fractal *f, t_rgb *rgb, double l)
{
	rgb->r = 255;
	rgb->g = 255;
	rgb->b = 255;
	if (f->color_mode > 0)
	{
		rgb->r *= (f->depth * 2);
		rgb->g *= (f->depth * 1);
		rgb->b *= (f->depth * 3);
	}
	if (f->color_mode > 1)
	{
		rgb->r *= l;
		rgb->g *= l;
		rgb->b *= l;
	}
}

t_rgb	ft_color(t_fractal *f, double l)
{
	t_rgb	palette;
	t_rgb	rgb;

	ft_color_mode(f, &rgb, l);
	if (f->max_iteration == 0)
		f->max_iteration = 1;
	if (f->i >= f->max_iteration)
	{
		palette = (t_rgb){
			(rgb.r),
			(rgb.g),
			(rgb.b)};
		return (palette);
	}
	else
	{
		palette = (t_rgb){
			(rgb.r) * f->z.imag,
			(rgb.g) * f->z.imag,
			(rgb.b) * f->z.imag};
		return (palette);
	}
}

uint32_t	rgb(t_rgb color)
{
	return (color.r << 24 | color.g << 16 | color.b << 8 | 255);
}
