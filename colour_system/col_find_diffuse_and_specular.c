/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_find_diffuse_and_specular.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 16:43:16 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 13:32:35 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

static void		init_arr(t_l_info_fnc l_info_f[2])
{
	l_info_f[0] = &light_distant_info;
	l_info_f[1] = &light_point_info;
}

static t_colour	calc_diffuse_and_spec(t_shape_colours shape_col,
		t_intsect_info *info, double amb)
{
	t_colour	colour;

	colour.r = (info->look.diffuse_colour.r * (amb +
				(shape_col.diffuse.r * info->look.diffuse_comp * (1 - amb)))) +
		(info->look.specular_tint.r * shape_col.specular.r *
			info->look.specular_comp);
	colour.g = (info->look.diffuse_colour.g * (amb +
				(shape_col.diffuse.g * info->look.diffuse_comp * (1 - amb)))) +
		(info->look.specular_tint.g * shape_col.specular.g *
			info->look.specular_comp);
	colour.b = (info->look.diffuse_colour.b * (amb +
				(shape_col.diffuse.b * info->look.diffuse_comp * (1 - amb)))) +
		(info->look.specular_tint.b * shape_col.specular.b *
			info->look.specular_comp);
	return (colour);
}

t_colour		col_find_diffuse_and_specular(t_scene_info info,
		t_intsect_info i_info, t_ray ray)
{
	t_object		*l_list;
	t_light_info	l_info;
	t_shape_colours	shape_col;
	t_l_info_fnc	l_info_f[2];

	init_arr(l_info_f);
	l_list = info.obj_list[1];
	col_shape_c_zero(&shape_col);
	while (l_list)
	{
		l_info = l_info_f[l_list->id](&i_info, l_list->ptr);
		if (col_is_shadow(info.obj_list[0], &l_info, &i_info) != 1)
		{
			col_diffuse(&i_info, &l_info, &shape_col);
			col_specular(&i_info, &l_info, &shape_col, &ray);
		}
		l_list = l_list->next;
	}
	return (calc_diffuse_and_spec(shape_col, &i_info,
				info.opts.ambient_light));
}
