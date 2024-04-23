/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:09:08 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/23 16:12:32 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

int	close_handler(t_fdf *fdf)
{
	// mlx_destroy_image(fdf->mlx_connection, fdf->img.img_ptr);
	// mlx_destroy_window(fdf->mlx_connection, fdf->mlx_window);
	// mlx_destroy_display(fdf->mlx_connection);
	// free(fdf->mlx_connection);
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
	render_lines(&fdf->bres, fdf);
	return (0);
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

	// else if (keysym == XK_Left)
	// 	fdf->shift_x += 0.5;
	// else if (keysym == XK_Right)
	// 	fdf->shift_x -= 0.5;
	// else if (keysym == XK_Up)
	// 	fdf->shift_y -= 0.5;
	// else if (keysym == XK_Down)
	// 	fdf->shift_y += 0.5;
	// else if (keysym == XK_p)
	// 	fdf->iter_definition += 10;
	// else if (keysym == XK_m)
	// 	fdf->iter_definition -= 10;
*/
