/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:09:08 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/23 18:25:03 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

static void	change_angle(t_fdf *fdf);

int	close_handler(t_fdf *fdf)
{
	fdf_clean(fdf, 0);
	exit(EXIT_SUCCESS);
}

void	reset(t_fdf *fdf)
{
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->zoom = 1;
	fdf->angle = atan(0.5);
	render_lines(&fdf->bres, fdf);
}

int	key_handler(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Escape)
		close_handler(fdf);
	else if (keysym == XK_r)
		reset(fdf);
	else if (keysym == XK_Left)
		fdf->shift_x += 10;
	else if (keysym == XK_Right)
		fdf->shift_x -= 10;
	else if (keysym == XK_Up)
		fdf->shift_y -= 10;
	else if (keysym == XK_Down)
		fdf->shift_y += 10;
	else if (keysym == XK_equal)
		fdf->zoom *= 1.1;
	else if (keysym == XK_minus)
		fdf->zoom *= 0.9;
	else if (keysym == XK_o)
		change_angle(fdf);
	render(&fdf->bres, fdf);
	return (0);
}

static void	change_angle(t_fdf *fdf)
{
	double	angle;
	double	change;

	change = 0.2;
	angle = fdf->angle;
	angle = angle + change;
	if (angle > 6.283)
		angle = angle - 6.283;
	fdf->angle = angle;
}

/*
// int
//        mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
//         mouse_hook(int button,int x,int y,void *param);

int	mouse_handler(int button, int x, int y, t_fdf *fdf)
{
	// up
	if (button == Button5)
	{
		fdf->zoom *= 1.1;
	}
	else if (button == Button4)
	{
		fdf->zoom *= 0.9;
	}
	printf("x = %i, y = %i \n", x, y);
	printf("fdf->shift_x = %f, fdf->shift_y = %f \n", fdf->shift_x,
		fdf->shift_y);
	// refresh
	render_lines(&fdf->bres, &fdf);
	return (0);
}

// MORE POTENTIAL EVENTS


	// else if (keysym == XK_p)
	// 	fdf->iter_definition += 10;
	// else if (keysym == XK_m)
	// 	fdf->iter_definition -= 10;
*/
