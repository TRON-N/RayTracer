/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_point_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 08:23:56 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/11 16:28:13 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

t_light_info	light_point_info(t_intsect_info *info, void *ptr)
{
	t_light_info		light_info;
	t_vect3d			l_to_p_v;
	const t_light_point	*light = (t_light_point *)ptr;
	double				area;

	l_to_p_v = vect3d_new(light->pos, info->hit_point);
	light_info.l_to_p_dist = vect3d_len(l_to_p_v);
	area = 4 * M_PI * light_info.l_to_p_dist * light_info.l_to_p_dist;
	light_info.energy.r = (light->colour.r * light->intensity) / area;
	light_info.energy.g = (light->colour.g * light->intensity) / area;
	light_info.energy.b = (light->colour.b * light->intensity) / area;
	vect3d_normalize(&l_to_p_v);
	light_info.dir = l_to_p_v;
	light_info.rev_dir = vect3d_rev(l_to_p_v);
	return (light_info);
}
