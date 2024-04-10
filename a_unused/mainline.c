#include "include/fdf.h"
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("./test_maps/simple.fdf", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
