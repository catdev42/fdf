/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:19:40 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/08 22:49:48 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	events_init(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_window,
			KeyPress,
			KeyPressMask,
			key_handler,
			fdf);
	mlx_hook(fdf->mlx_window,
			ButtonPress,
			ButtonPressMask,
			mouse_handler,
			fdf);
	mlx_hook(fdf->mlx_window,
			DestroyNotify,
			StructureNotifyMask,
			close_handler,
			fdf);
	// mlx_hook(fdf->mlx_window,
	// 		MotionNotify,
	// 		PointerMotionMask,
	// 		julia_track,
	// 		fdf);
}

int	fdf_init(t_fdf *fdf)
{
	fdf->mlx_connection = mlx_init();
	if (!fdf->mlx_connection)
		fdf_clean(fdf, 1);
	fdf->mlx_window = mlx_new_image(fdf->mlx_connection, WIDTH, HEIGHT);
	if (!fdf->mlx_window)
		fdf_clean(fdf, 1);
	fdf->img.img_ptr = mlx_new_image(fdf->mlx_connection, WIDTH, HEIGHT);
    if (!fdf->img.img_ptr)
		fdf_clean(fdf, 1);
	fdf->img.pixels_ptr = mlx_get_data_addr(fdf->mlx_connection, &fdf->img.bpp,
			&fdf->img.line_len, &fdf->img.endian);
            events_init(fdf);
}


/* 
    Reset to original isometric projection.
    Original view.
*/
void	reset(t_fdf *fdf)
{
	fdf->angle = sqrt(3) / 3;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->zoom = 0;
	render_pixels(fdf); // TODO
}
