/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextmain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:11:54 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/10 15:15:37 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf fdf;
	int fd;

	if (argc != 2 && argc != 4)
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		return (1);
	}
	// INIT
	fdf.name = argv[1];

	// fd = open(argv[1], O_RDONLY);
	fd = open("./test_maps/simple.fdf", O_RDONLY);
	// if (fd == 0)
	// 	return (fdf_clean(&fdf, 1));
	get_next_line(fd);
	// parse_data(fd, &fdf);
	close(fd);
	// data = get_next_line(fd);
	// while (data)
	// {
	// 	parse_data(data, &fdf);
	// 	data = get_next_line(fd);
	// }
}