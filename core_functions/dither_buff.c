/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dither_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:53:43 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/04 16:28:03 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_rt_prototype.h"

static void	add_error(t_options opts, t_colour **buff, int x, int y, t_colour error, double factor)
{
	if (0 <= x && x < opts.pix_width &&
		0 <= y && y < opts.pix_height)
		buff[y][x] = col_add(buff[y][x], col_mult_const(error, factor));
}

void	dither_buff(t_options opts, t_colour **buff, t_colour (*quant)(t_colour))
{
	int			x;
	int			y;
	t_colour	error;

	y = -1;
	while (++y < opts.pix_height)
	{
		x = -1;
		while (++x < opts.pix_width)
		{
			error = col_add(quant(buff[y][x]), col_mult_const(col_limit(buff[y][x]), -1));
			buff[y][x] = quant(buff[y][x]);
			add_error(opts, buff, x + 1, y    , error, -7 / 16.0);
			add_error(opts, buff, x + 1, y + 1, error, -1 / 16.0);
			add_error(opts, buff, x    , y + 1, error, -5 / 16.0);
			add_error(opts, buff, x - 1, y + 1, error, -3 / 16.0);
		}
	}
}
