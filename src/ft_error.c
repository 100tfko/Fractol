/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:14:22 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/03 15:47:12 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fractol.h"

void	ft_control(void)
{
	ft_printf("╒══════════╡ FRACTOL CONTROLS╞═════════╕\n");
	ft_printf("│                                      │\n");
	ft_printf("│     I -> Increase ITERARIONS         │\n");
	ft_printf("│     O -> Decrease ITERARIONS         │\n");
	ft_printf("│ ------------------------------------ │\n");
	ft_printf("│       ZOOM can be changed            │\n");
	ft_printf("│           UP    ――> UP               │\n");
	ft_printf("│           DOWN  ――> DOWN             │\n");
	ft_printf("│           LEFT  ――> LEFT             │\n");
	ft_printf("│           RIGHT ――> RUGHT            │\n");
	ft_printf("│ ------------------------------------ │\n");
	ft_printf("│     Fractal can be MOVED with:       │\n");
	ft_printf("│           Z  ――> ZOOM IN             │\n");
	ft_printf("│           X  ――> ZOOM OUT            │\n");
	ft_printf("│                                      │\n");
	ft_printf("│ Aditionally mouse scroll can be used │\n");
	ft_printf("│ -----------------------------------  │\n");
	ft_printf("│                 COLORS               │\n");
	ft_printf("│ Colors may be tied to fractal depth. │\n");
	ft_printf("│ WARNING: May cause FLASHING LIGHTS   │\n");
	ft_printf("│                                      │\n");
	ft_printf("│           M  ――> MORE COLOR          │\n");
	ft_printf("│           N  ――> LESS COLOR          │\n");
	ft_printf("│ TIP: Change iterations and colors    │\n");
	ft_control_2();
}

void	ft_control_2(void)
{
	ft_printf("│ ------------------------------------ │\n");
	ft_printf("│                                      │\n");
	ft_printf("│     If using JULIA, Julia parameters │\n");
	ft_printf("│     can be changed:                  │\n");
	ft_printf("│ A  ――> Will increase real component  │\n");
	ft_printf("│ S  ――> Will decrease real component  │\n");
	ft_printf("│ D  ――> Will increase imag component  │\n");
	ft_printf("│ F  ――> Will decrease imag component  │\n");
	ft_printf("│                                      │\n");
	ft_printf("│ ------------------------------------ │\n");
	ft_printf("│                                      │\n");
	ft_printf("│   You can change fractals with H     │\n");
	ft_printf("╘══════════════════════════════════════╛\n");
}

void	ft_error_manual(void)
{
	ft_printf("╒════════╡ FRACTOL USER MANUAL╞════════╕\n");
	ft_printf("│                                      │\n");
	ft_printf("│ USAGE : ./fractol [INDEX] [JULIA-ARG]│\n");
	ft_printf("│                                      │\n");
	ft_printf("│ ------------------------------------ │\n");
	ft_printf("│    INDEX correspond to fractal       │\n");
	ft_printf("│           1 ――> JULIA                │\n");
	ft_printf("│           2 ――> MANDELBROT           │\n");
	ft_printf("│           3 ――> TRIPEAK              │\n");
	ft_printf("│           4 ――> BURNING SHIP         │\n");
	ft_printf("│ -----------------------------------  │\n");
	ft_printf("│                                      │\n");
	ft_printf("│ JULIA can accept two more arguments. │\n");
	ft_printf("│ Two numbers that compone the fractal.│\n");
	ft_printf("│                                      │\n");
	ft_printf("│ EXAMPLE ./Fractol 1 0.274 -0.008     │\n");
	ft_printf("│                                      │\n");
	ft_printf("│ Small numbers give better results    │\n");
	ft_printf("╘══════════════════════════════════════╛\n");
	exit(0);
}

void	ft_error(int error, t_fractal *f)
{
	if (error == MLX_ERROR)
		mlx_terminate(f->mlx);
	if (error == IMG_ERROR)
	{
		mlx_delete_image(f->mlx, f->img);
		mlx_terminate(f->mlx);
	}
	perror(mlx_strerror(mlx_errno));
}
