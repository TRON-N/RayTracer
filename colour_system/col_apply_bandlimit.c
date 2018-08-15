/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_apply_bandlimit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:45:02 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/04 16:46:06 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

static double	gaussian_step(double d, double aaf)
{
	if (d < 0)
		return (0);
	d = (d / aaf) - 1;
	if (d < 0)
		return (exp(-d * d * 4) * cos(d * M_PI / 2));
	return (1);
}

static double	gaussian(double d, double size, double aaf)
{
	return (gaussian_step(d + size, aaf) *
			gaussian_step(size - d, aaf));
}

static double	dist(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

void			col_apply_bandlimit(t_options opts,
		t_colour **buff, t_colour **buff2, t_point2d rast, double size)
{
	const int		sx = (int)(rast.x / opts.aa - size);
	const int		sy = (int)(rast.y / opts.aa - size);
	int				cx;
	int				cy;
	t_colour		c;

	c = buff[(int) rast.y][(int) rast.x];
	cy = sy;
	while (cy < ceil(size) + (int)rast.y / opts.aa)
	{
		cx = sx;
		while (cx < ceil(size) + (int)rast.x / opts.aa)
		{
			if (0 <= cx && cx < opts.pix_width
					&& 0 <= cy && cy < opts.pix_height)
				buff2[cy][cx] = col_mix(buff2[cy][cx], c,
				gaussian(dist(cx + 0.5, cy + 0.5, rast.x / opts.aa, rast.y / opts.aa), size, size)
					/ size);
			cx++;
		}
		cy++;
	}
}
