/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:14:14 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/02 17:27:53 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fractol.h"

void	ft_select_fractal(t_fractal *f)
{
	if (f->f_slect == 1)
		ft_julia(f);
	else if (f->f_slect == 2)
		ft_mandelbrot(f);
	else if (f->f_slect == 3)
		ft_tricorn(f);
	else if (f->f_slect == 4)
		ft_ship(f);
}

void	ft_initiate_f(t_fractal *f)
{
	f->color_mode = 0;
	f->zoom = 3.5;
	f ->max_iteration = 50;
	f->xmv = -0.0;
	f->ymv = 0.0;
	if (f->f_slect == 1)
		f->name = "Julia";
	else if (f->f_slect == 2)
		f->name = "Mandelbrot";
	else if (f->f_slect == 3)
		f->name = "Tricorn";
	else if (f->f_slect == 4)
		f->name = "Ship";
}

int_fast32_t	ft_check_double(const char *nb)
{
	int		decimal_flag;
	int		i;

	decimal_flag = 0;
	i = 0;
	if (!nb)
		ft_error_manual();
	while (nb[i])
	{
		if ((!(nb[i] >= '0' && nb[i] <= '9')) && nb[i] != '-' && nb[i] != '.')
			ft_error_manual();
		if (nb[i] == '.')
			decimal_flag += 1;
		i += 1;
	}
	if (decimal_flag > 1)
		ft_error_manual();
	return (1);
}

void	ft_check_arg(int argc, char **argv, t_fractal *f)
{
	if (argc != 2 && argc != 4)
		ft_error_manual();
	if (argc == 2)
	{
		if (argv[1][0] < '1' || argv[1][0] > '4')
			ft_error_manual();
		if (argv[1][0] == '1')
			f->julia_arguments = (t_complexnb){0.274, -0.008};
	}
	if (argc == 4)
	{
		if (argv[1][0] != '1')
			ft_error_manual();
		ft_check_double(argv[2]);
		ft_check_double(argv[3]);
		f->julia_arguments = (t_complexnb){ft_atof(argv[2]), ft_atof(argv[3])};
	}
	ft_control();
	f->f_slect = ft_atoi(argv[1]);
}
