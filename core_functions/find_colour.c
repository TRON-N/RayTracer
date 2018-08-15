/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colour.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:38:18 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 16:15:36 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_rt_prototype.h"

static void	init_arr(t_s_info_fnc s_info[5])
{
	s_info[0] = &sphere_info;
	s_info[1] = &plane_info;
	s_info[2] = &cone_info;
	s_info[3] = &cylinder_info;
	s_info[4] = &cube_info;
}

static void	init_mask_arr(t_grey_mask_fnc mask[4])
{
	mask[1] = &col_r_mask;
	mask[2] = &col_g_mask;
	mask[3] = &col_b_mask;
}

t_colour	find_colour(t_ray ray, t_scene_info info)
{
	t_s_info_fnc	s_info[5];
	t_intsect_info	intsct_info;
	t_colour		ret;
	t_grey_mask_fnc	mask[4];

	init_arr(s_info);
	init_mask_arr(mask);
	ray.t = INFINITY;
	intsct_info = trace_ray(&ray, info.obj_list[0]);
	if (intsct_info.ptr != NULL)
	{
		s_info[intsct_info.obj_id](&ray, &intsct_info);
		col_sphere_texture(&intsct_info);
		col_rev_norm_and_ndoti(&intsct_info, &ray);
		ret = col_find_diffuse_and_specular(info, intsct_info, ray);
		ret = col_find_transp_and_reflect(info, intsct_info, ray, ret);
		if (info.opts.greyscale > 0)
			return (mask[info.opts.greyscale]((ret)));
		return ((ret));
	}
	return (info.opts.background);
}
