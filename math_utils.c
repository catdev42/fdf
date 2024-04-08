double	map(double unscaled_num, double new_min, double new_max, double old_min,
		double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min)
		+ new_min);
}