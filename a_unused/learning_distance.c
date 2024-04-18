#include "./include/fdf.h"

double	map_learn(double unscaled_num, double new_min, double new_max,
		double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min)
		+ new_min);
}

// int	main(void)
// {
// 	int height;
// 	int width;
// 	t_point obj_pos;
// 	int perspective;
// 	int fl;
// 	fl = 300;

// 	width = 1000;
// 	height = 1000;
// 	obj_pos.x = 500;
// 	obj_pos.y = 300;
// 	obj_pos.z = 300;
// 	perspective = fl / (fl + obj_pos.z);
// 	// translate aka map position
// 	// map_learn(height, 0, 1000, -500, 500);
// }