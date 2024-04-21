/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:19:40 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/21 17:10:47 by myakoven         ###   ########.fr       */
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
static void	init_points(t_points *points);

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
	fdf->img.pixels_ptr = mlx_get_data_addr(fdf->img.img_ptr, &fdf->img.bpp,
			&fdf->img.line_len, &fdf->img.endian);
	events_init(fdf);
	data_init(fdf);
	return (1);
}

static void	events_init(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_window, KeyPress, KeyPressMask, key_handler, fdf);
	// mlx_hook(fdf->mlx_window, ButtonPress, ButtonPressMask, mouse_handler,
	// fdf);
	mlx_hook(fdf->mlx_window, DestroyNotify, StructureNotifyMask, close_handler,
		fdf);
	// mlx_hook(fdf->mlx_window,
	// 		MotionNotify,
	// 		PointerMotionMask,
	// 		julia_track,
	// 		fdf);
}
/*
TODO
INIT POINTS NEEDS MAP DATA??? CHECK MAP DATA FUNCTION...
 need ORIGINAL MIN AND ORIGINAL MAX WHICH IS LEN_X OR LENY,
	WHICHEVER IS BIGGER
*/
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
	fdf->shift_x = 0.0;
	fdf->shift_y = 0.0;
	fdf->zoom = 1.0;
	// fdf->angle = 30;
	init_points(&fdf->points);
	fdf->angle = atan(0.5);
	// map sizes
	fd = open(fdf->name, O_RDONLY);
	if (fd == -1)
		fdf_clean(fdf, 3);
	get_map_size(fd, fdf);
	close(fd);
}

static void	init_points(t_points *points)
{
	points->x = NULL;
	points->y = NULL;
	points->z = NULL;
	points->color = NULL;
	points->iso_x = NULL;
	points->iso_y = NULL;
	points->orig_min = 0;
	points->orig_max = 0;
	points->target_min = WIDTH / 10;
	points->target_max = WIDTH - WIDTH / 10;
	points->map_x = NULL;
	points->map_y = NULL;
}
/*Need to get sizes to know how much to malloc*/
static int	get_map_size(int fd, t_fdf *fdf)
{
	char	**alpha_dataline_split;
	char	*nextline;

	if (!fd || fd == -1)
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
	if (!fdf->x_len || !fdf->y_len)
		fdf_clean(fdf, 3);
	fdf->points.orig_max = fdf->x_len;
	if (fdf->y_len > fdf->x_len)
		fdf->points.orig_max = fdf->y_len;
	return (1);
}
