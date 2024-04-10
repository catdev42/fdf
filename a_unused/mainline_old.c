/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 22:36:40 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/10 17:50:25 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf fdf;
	int fd;

	// if (argc != 2 && argc != 4)
	// {
	// 	ft_putstr_fd(ERROR_MESSAGE, 2);
	// 	return (1);
	// }

	// fdf.name = argv[1];

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	printf("line: %s \n", get_next_line(fd));
	printf("line: %s \n", get_next_line(fd));
	printf("line: %s \n", get_next_line(fd));
	printf("line: %s \n", get_next_line(fd));

	close(fd);
}