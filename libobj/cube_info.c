/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 00:43:07 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/09/30 00:43:07 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

void	cube_info(t_ray *ray, t_intsect_info *info)
{
	t_vect3d		normal;
	t_vect3d		scale_div;
	const t_cube	*cube = (t_cube *)info->ptr;

	scale_div.x_dist = (cube->bounds[0].x - cube->bounds[1].x) * 0.5;
	scale_div.y_dist = (cube->bounds[0].y - cube->bounds[1].y) * 0.5;
	scale_div.z_dist = (cube->bounds[0].z - cube->bounds[1].z) * 0.5;
	info->hit_point = point3d_on_ray(*ray);
	normal = vect3d_new(cube->centre, info->hit_point);
	normal.x_dist = (int)(normal.x_dist / fabs(scale_div.x_dist) * 1.000001);
	normal.y_dist = (int)(normal.y_dist / fabs(scale_div.y_dist) * 1.000001);
	normal.z_dist = (int)(normal.z_dist / fabs(scale_div.z_dist) * 1.000001);
	vect3d_normalize(&normal);
	info->hit_point.x += normal.x_dist * 0.001;
	info->hit_point.y += normal.y_dist * 0.001;
	info->hit_point.z += normal.z_dist * 0.001;
	info->normal = normal;
}
