// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   x_change.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/04/21 13:22:33 by myakoven          #+#    #+#             */
// /*   Updated: 2024/04/21 14:09:15 by myakoven         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */




// #include "include/fdf.h"

// void	make_line(t_bres *bres, t_fdf *fdf)
// {
// 	int i;

// 	while (i < (fdf->x_len * fdf->y_len) - 1)
// 	{
// 		bres->x = points->iso_x[i];
// 		bres->y = points->iso_y[i];
// 		bres->color = points->color[i];
// 		if (points->x[i] < fdf->x_len - 2)
// 		{
// 			bres->x2 = points->iso_x[i + 1];
// 			bres->y2 = points->iso_y[i + 1];
// 			init_bres(bres);
// 			run_bres(bres, &fdf->img);
// 		}
// 		if (points->y[i] < fdf->y_len - 2)
// 		{
// 			bres->x2 = points->iso_x[i + 1];
// 			bres->y2 = points->iso_y[i + fdf->x_len];
// 			init_bres(bres);
// 			run_bres(bres, &fdf->img);
// 		}
// 		i++; 
// 	}
// }