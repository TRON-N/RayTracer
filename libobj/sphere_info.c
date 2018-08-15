/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 14:45:54 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 11:41:50 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

void	sphere_info(t_ray *ray, t_intsect_info *info)
{
	t_vect3d		normal;
	const t_sphere	*sphere = (t_sphere *)info->ptr;

	info->hit_point = point3d_on_ray(*ray);
	normal = vect3d_new(sphere->pos, info->hit_point);
	vect3d_normalize(&normal);
	info->uv.x = (1 + (atan2(normal.z_dist, normal.x_dist) / M_PI) * 0.5);
	info->uv.y = acosf(normal.y_dist) / M_PI;
	if (info->look.tex_rot > 0)
	{
		info->uv.x = info->uv.x * cos(info->look.tex_rot) - info->uv.y *
			cos(info->look.tex_rot);
		info->uv.y = info->uv.y * cos(info->look.tex_rot) + info->uv.x *
			cos(info->look.tex_rot);
	}
	info->normal = normal;
}
