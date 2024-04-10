/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:19:40 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/10 21:13:06 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
	Reset to original isometric projection.
	Original view.
*/
static int	get_map_size(int fd, t_fdf *fdf);
static void	data_init(t_fdf *fdf);
static void	events_init(t_fdf *fdf);

int	fdf_init(t_fdf *fdf)
{
	fdf->mlx_connection = mlx_init();
	if (!fdf->mlx_connection)
		fdf_clean(fdf, 1);
	fdf->mlx_window = mlx_new_window(fdf->mlx_connection, WIDTH, HEIGHT,
			fdf->name);
	if (!fdf->mlx_window)
		fdf_clean(fdf, 1);
	fdf->img.img_ptr = mlx_new_image(fdf->mlx_connection, WIDTH, HEIGHT);
	if (!fdf->img.img_ptr)
		fdf_clean(fdf, 1);
	fdf->img.pixels_ptr = mlx_get_data_addr(fdf->mlx_connection, &fdf->img.bpp,
			&fdf->img.line_len, &fdf->img.endian);
	events_init(fdf);
	data_init(fdf);
	return (1);
}

static void	events_init(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_window, KeyPress, KeyPressMask, key_handler, fdf);
	mlx_hook(fdf->mlx_window, ButtonPress, ButtonPressMask, mouse_handler, fdf);
	mlx_hook(fdf->mlx_window, DestroyNotify, StructureNotifyMask, close_handler,
		fdf);
	// mlx_hook(fdf->mlx_window,
	// 		MotionNotify,
	// 		PointerMotionMask,
	// 		julia_track,
	// 		fdf);
}

static void	data_init(t_fdf *fdf)
{
	int	fd;

	// int
	fdf->x_len = 0;
	fdf->y_len = 0;
	fdf->total_points = 0;
	fdf->z_min = INT_MAX;
	fdf->z_max = INT_MIN;
	fdf->z_range = 0;
	// double
	fdf->shift_x = 0.0;
	fdf->shift_y = 0.0;
	// zoom factor
	fdf->zoom = 1.0;
	fdf->angle = 30;
	fdf->points.x = NULL;
	fdf->points.y = NULL;
	fdf->points.z = NULL;
	fdf->points.color = NULL;
	fdf->points.iso_x = NULL;
	fdf->points.iso_y = NULL;
	fdf->angle = atan(1 /2);
	// map sizes
	fd = open(fdf->name, O_RDONLY);
	if (fd == -1)
		fdf_clean(fdf, 3);
	get_map_size(fd, fdf);
	close(fd);
}
/*Need to get sizes to know how much to malloc*/
static int	get_map_size(int fd, t_fdf *fdf)
{
	char	**alpha_dataline_split;
	char	*nextline;

	if (!fd)
		fdf_clean(fdf, 3);
	while (fd)
	{
		nextline = get_next_line(fd);
		if (!nextline)
			break ;
		if (ft_strlen(nextline) && nextline[ft_strlen(nextline) - 1] == '\n')
			nextline[ft_strlen(nextline) - 1] = 0;
		if (!fdf->x_len)
		{
			alpha_dataline_split = ft_split(nextline, ' ');
			while (alpha_dataline_split[fdf->x_len])
				fdf->x_len++;
			free(alpha_dataline_split);
		}
		free(nextline);
		fdf->y_len++;
	}
	if (!fd || !fdf->x_len || !fdf->y_len)
		fdf_clean(fdf, 3);
	return (1);
}
