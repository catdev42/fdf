/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 22:36:40 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/07 23:54:13 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	main(argc, argv)
{
	t_map	fdf;
	int		fd;
	char	*data;
	int		len;

	if (argc != 2 || argc != 4)
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		return (1);
	}
	// fd = open(argv[1], O_RDONLY);
	fd = open("./text_maps/simple.fdf", O_RDONLY);
	if (fd == 0)
		return (ft_clean(NULL, 1));
	data = get_next_line(fd);
	while (data)
	{
		parse_data(data);
		data = get_next_line(fd);
	}
}

int	fdf_clean(t_map *fdf, int err)
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
	if (err == 1)
	{
		perror("Problems with malloc");
		return (1);
	}
	if (err == 2)
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}