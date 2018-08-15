/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_is_shadow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:27:34 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/28 11:00:31 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

int	col_is_shadow(t_object *obj_list, t_light_info *l_info,
	t_intsect_info *info)
{
	t_ray shadow_ray;

	shadow_ray.dir = l_info->rev_dir;
	shadow_ray.orig = col_point_bias_shift(info->hit_point, info->normal, 0.1);
	shadow_ray.t = l_info->l_to_p_dist;
	trace_ray(&shadow_ray, obj_list);
	if (shadow_ray.t == l_info->l_to_p_dist || shadow_ray.t < 0)
		return (0);
	else
		return (1);
}
