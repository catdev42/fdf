/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:19:40 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/23 16:43:48 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	get_map_size(int fd, t_fdf *fdf);
static void	data_init(t_fdf *fdf);
static void	events_init(t_fdf *fdf);
static void	init_points(t_fdf *fdf);

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
	mlx_hook(fdf->mlx_window, DestroyNotify, StructureNotifyMask, close_handler,
		fdf);
}

static void	data_init(t_fdf *fdf)
{
	int	fd;

	fdf->x_len = 0;
	fdf->y_len = 0;
	fdf->total_points = 0;
	fdf->z_min = INT_MAX;
	fdf->z_max = INT_MIN;
	fdf->z_range = 0;
	fdf->shift_x = 0.0;
	fdf->shift_y = 0.0;
	fdf->zoom = 1.0;
	fdf->col = 0xffffff;
	init_points(fdf);
	fdf->angle = -atan(0.5); //changed
	fd = open(fdf->name, O_RDONLY);
	if (fd == -1)
		fdf_clean(fdf, 3);
	get_map_size(fd, fdf);
	close(fd);
}

static void	init_points(t_fdf *fdf)
{
	int			min_side;
	int			largest;
	t_points	*points;

	points = &fdf->points;
	largest = fdf->x_len - 1;
	if (fdf->y_len > fdf->x_len)
		largest = fdf->y_len - 1;
	min_side = WIDTH;
	if (HEIGHT < WIDTH)
		min_side = HEIGHT;
	points->x = NULL;
	points->y = NULL;
	points->z = NULL;
	points->color = NULL;
	points->iso_x = NULL;
	points->iso_y = NULL;
	points->orig_min = 0;
	points->orig_max = largest;
	points->target_min = 80;
	points->target_max = 720;
	points->map_x = NULL;
	points->map_y = NULL;
}

/* GET SIZES to know how much to malloc */
static void	get_map_size(int fd, t_fdf *fdf)
{
	char	**alpha_dataline_split;
	char	*nextline;

	while (fd != -1)
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
			free_split(alpha_dataline_split);
		}
		free(nextline);
		fdf->y_len++;
	}
	if (fd == -1 || !fdf->x_len || !fdf->y_len)
		fdf_clean(fdf, 3);
	fdf->points.orig_max = fdf->x_len;
	if (fdf->y_len > fdf->x_len)
		fdf->points.orig_max = fdf->y_len;
}

/*
// mlx_hook(fdf->mlx_window, ButtonPress, ButtonPressMask, mouse_handler, fdf);

// mlx_hook(fdf->mlx_window,
	// 		MotionNotify,
	// 		PointerMotionMask,
	// 		julia_track,
	// 		fdf);
*/