/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_render_progress.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 17:07:47 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/10/01 17:10:29 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_rt_prototype.h"

void	show_render_progress(t_thread_info thread_info[THREAD_NUM],
		t_options opts)
{
	int				indx;
	int				progress;
	int				prev_progress;
	const double	div = 1 / (opts.buff_height * THREAD_NUM);

	indx = 0;
	progress = 0;
	prev_progress = -1;
	while (progress < 100)
	{
		progress = 0;
		while (indx < THREAD_NUM)
		{
			progress += thread_info[indx].progress;
			indx++;
		}
		progress = (progress * 100) * div;
		if (prev_progress != progress)
			show_progress_bar(progress, "Rendering: ");
		prev_progress = progress;
		indx = 0;
	}
}
