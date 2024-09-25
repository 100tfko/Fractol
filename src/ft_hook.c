/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:14:39 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/03 15:46:00 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/fractol.h"

void	ft_scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;
	int32_t		mouse_x;
	int32_t		mouse_y;
	double		movex;
	double		movey;

	f = (t_fractal *)param;
	(void)xdelta;
	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	if (mouse_x < 0 || mouse_x >= WIDTH || mouse_y < 0 || mouse_y >= HEIGHT)
		return ;
	movex = (mouse_x - WIDTH / 2.0) * f->zoom / WIDTH;
	movey = (mouse_y - HEIGHT / 2.0) * f->zoom / HEIGHT;
	if (ydelta > 0)
		f->zoom *= 1.1;
	if (ydelta < 0)
		f->zoom /= 1.1;
	f->xmv += movex - (mouse_x - WIDTH / 2.0) * f->zoom / WIDTH;
	f->ymv += movey - (mouse_y - HEIGHT / 2.0) * f->zoom / HEIGHT;
}

void	ft_key_control(t_fractal *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_I))
		f->max_iteration += 1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_O))
		f->max_iteration -= 1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_X))
		f->zoom *= 1.1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_Z))
		f->zoom /= 1.1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_M))
		if (f->color_mode < 2)
			f->color_mode += 1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_N))
		if (f->color_mode > 0)
			f->color_mode -= 1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
		f->ymv -= (f->zoom / 10);
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
		f->ymv += (f->zoom / 10);
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
		f->xmv += f->zoom / 10;
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
		f->xmv -= f->zoom / 10;
}

void	ft_julia_param_mod(t_fractal *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_A))
		f->julia_arguments.real += 0.001;
	if (mlx_is_key_down(f->mlx, MLX_KEY_S))
		f->julia_arguments.real -= 0.001;
	if (mlx_is_key_down(f->mlx, MLX_KEY_D))
		f->julia_arguments.imag += 0.001;
	if (mlx_is_key_down(f->mlx, MLX_KEY_F))
		f->julia_arguments.imag -= 0.001;
	if (mlx_is_key_down(f->mlx, MLX_KEY_H))
	{
		if (f->f_slect < 4)
			f->f_slect += 1;
		else
			f->f_slect = 1;
	}
}

void	ft_hook(void *param)
{
	t_fractal	*f;

	f = param;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
	ft_key_control(f);
	ft_julia_param_mod(f);
	mlx_scroll_hook(f->mlx, &ft_scroll_hook, f);
	ft_fractol(f);
}
