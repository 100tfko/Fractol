/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:52:53 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/02 17:28:38 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fractol.h"

void	ft_put_pixel(t_fractal *f)
{
	int		color;
	double	l;

	if (f->i >= f->max_iteration)
	{
		l = ((double)(f->z.imag));
		color = rgb(ft_color(f, l));
		mlx_put_pixel(f->img, f->x, f->y, color);
	}
	else
	{
		l = f->i * f->z.imag * f->z.real;
		color = rgb(ft_color(f, l));
		mlx_put_pixel(f->img, f->x, f->y, color);
	}
}

void	ft_fractol(t_fractal *f)
{
	f->y = 0;
	while (f->y < HEIGHT)
	{
		f->x = 0;
		while (f->x < WIDTH)
		{
			ft_select_fractal(f);
			f->x += 1;
		}
		f->y += 1;
	}
}

void	ft_openwindow(t_fractal *f)
{
	ft_initiate_f(f);
	f->mlx = mlx_init(WIDTH, HEIGHT, f->name, false);
	if (!f->mlx)
		ft_error(MLX_ERROR, f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img || (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0))
		ft_error(IMG_ERROR, f);
	ft_fractol(f);
	mlx_loop_hook(f->mlx, &ft_hook, f);
	mlx_loop(f->mlx);
	mlx_delete_image(f->mlx, f->img);
	mlx_terminate(f->mlx);
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	ft_check_arg(argc, argv, &f);
	ft_openwindow(&f);
	return (0);
}
