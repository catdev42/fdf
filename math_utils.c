double	map(double unscaled_num,  double original_min,
		double original_max,double target_min, double target_max)
{
	return ((unscaled_num - original_min) / (original_max - original_min) * (target_max - target_min) 
		+ target_min);
}

/*take the value that starts with original min, divide by original range to get a percentage, multiply by target range, add target min
*/