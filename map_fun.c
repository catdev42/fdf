#include "include/fdf.h"

double	map(double unscaled_num, t_points *points)
{
	double original_min;
	double original_max;
	double target_min;
	double target_max;

	original_min = points->orig_min;
	return ((unscaled_num - original_min) / (original_max - original_min)
		* (target_max - target_min) + target_min);
}