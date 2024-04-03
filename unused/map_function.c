double	scale(double unscaled_num, double n_min, double n_max, double o_min,
		double o_max)
{
	double	nnum;

	nnum = (n_max - n_min) * (unscaled_num - o_min) / (o_max - o_min) + n_min;
	return (nnum);
}