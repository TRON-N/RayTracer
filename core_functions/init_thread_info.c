/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 17:05:52 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/10/01 17:34:54 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_rt_prototype.h"

static int	set_buff_w_limits(int thread_indx, t_thread_info *info)
{
	info->min_w = (info->opts.buff_width / (double)THREAD_NUM) *
	(double)thread_indx;
	info->max_w = (info->opts.buff_width / (double)THREAD_NUM) *
	((double)thread_indx + 1.0);
	return (0);
}

int			init_thread_info(t_thread_info thread_info[THREAD_NUM],
		t_thread_info main_info, char *str)
{
	int indx;

	indx = 0;
	while (indx < THREAD_NUM)
	{
		thread_info[indx] = main_info;
		if (init_scene_info(str, &thread_info[indx].scene_info) == -1)
			return (-1);
		thread_info[indx].opts = main_info.scene_info.opts;
		thread_info[indx].opts.buff_width = main_info.opts.buff_width;
		thread_info[indx].opts.buff_height = main_info.opts.buff_height;
		thread_info[indx].progress = 0;
		set_buff_w_limits(indx, &thread_info[indx]);
		indx++;
	}
	return (0);
}
