/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_apply_aa_blend.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 11:45:09 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/04 15:50:38 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

void	col_apply_aa_blend(t_colour **buff, t_options opts, t_colour **buff2)
{
	t_point2d		rast;
	const double	div = 1 / (opts.buff_height);
	int				progress;
	int				prev_progress;
	t_colour		**buffers[2];

	rast.y = -1;
	prev_progress = -1;
	progress = 0;
	buffers[0] = buff;
	buffers[1] = buff2;
	while (++rast.y < opts.buff_height)
	{
		progress = (int)((rast.y * 100) * div);
		rast.x = -1;
		while (++rast.x < opts.buff_width)
			col_apply_bandlimit(opts, buff, buff2, rast, 1.2);
		if (prev_progress != progress)
			show_progress_bar(progress, "Applying AA: ");
		prev_progress = progress;
	}
}
