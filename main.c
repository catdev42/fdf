/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 22:36:40 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/22 20:32:08 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fd;

	if (argc != 2 && argc != 4)
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		return (1);
	}
	// INIT
	fdf.name = argv[1];
	fdf_init(&fdf);
	// fd = open(argv[1], O_RDONLY);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (fdf_clean(&fdf, 3));
	parse_data(fd, &fdf);
	render_lines(&fdf.bres, &fdf);
	close(fd);
	// data = get_next_line(fd);
	// while (data)
	// {
	// 	parse_data(data, &fdf);
	// 	data = get_next_line(fd);
	// }
	mlx_loop(fdf.mlx_connection);
}

/******CLEANING******/

static void	clean_points(t_fdf *fdf)
{
	if (fdf && fdf->points.x)
		free(fdf->points.x);
	if (*fdf->points.y)
		free(fdf->points.y);
	if (*fdf->points.z)
		free(fdf->points.z);
	if (*fdf->points.iso_x)
		free(fdf->points.iso_x);
	if (*fdf->points.iso_y)
		free(fdf->points.iso_y);
	if (*fdf->points.color)
		free(fdf->points.color);
}
// ADJUST EXTRA TO CLEAN FDF // TODO
int	fdf_clean(t_fdf *fdf, int err)
{
	if (fdf && fdf->img.img_ptr)
		mlx_destroy_image(fdf->mlx_connection, fdf->img.img_ptr);
	if (fdf && fdf->mlx_window)
		mlx_destroy_window(fdf->mlx_connection, fdf->mlx_window);
	if (fdf && fdf->mlx_connection)
	{
		mlx_destroy_display(fdf->mlx_connection);
		free(fdf->mlx_connection);
	}
	if (fdf->points.x)
		clean_points(fdf);
	if (err)
	{
		if (err == 1)
			perror("Problems with malloc");
		else if (err == 2)
			ft_putstr_fd(ERROR_MESSAGE, 2);
		else if (err == 3)
			perror("Problems with reading file or it is empty");
		else if (err == 4)
			ft_putstr_fd("Error: map format issue", 2);
		exit(1);
	}
	return (0);
}
void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
