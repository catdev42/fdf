/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:09:08 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/21 16:39:34 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

int	close_handler(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_connection, fdf->img.img_ptr);
	mlx_destroy_window(fdf->mlx_connection, fdf->mlx_window);
	mlx_destroy_display(fdf->mlx_connection);
	free(fdf->mlx_connection);
	exit(EXIT_SUCCESS);
}

void	reset(t_fdf *fdf)
{
	// fdf->angle = sqrt(3) / 3;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->zoom = 1;
	render_lines(&fdf->bres, fdf);
}
int	key_handler(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Escape)
		close_handler(fdf); // TODO
	else if (keysym == XK_r)
		reset(fdf);
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

//track the mouse to change julia dynamically

// int	julia_track(int x, int y, t_fdf *fdf)
// {
// 	if (!ft_strncmp(fdf->name, "julia", 5))
// 	{
// 		fdf->julia_x = (map((double)x, -2, 2, 0, WIDTH - 1) * fdf->zoom)
// 			+ (fdf->shift_x) * fdf->zoom;
// 		fdf->julia_y = (map((double)y, 2, -2, 0, HEIGHT - 1)
// 				* fdf->zoom) + (fdf->shift_x) * fdf->zoom;

// 		fdf_render(fdf);
// 	}
// 	return (0);
// }
*/
