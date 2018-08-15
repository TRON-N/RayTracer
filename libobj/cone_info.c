/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:03:03 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/09/30 00:19:12 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

void				cone_info(t_ray *ray, t_intsect_info *info)
{
	double		m;
	double		x;
	t_cone		*cone;
	t_vect3d	vect;
	t_vect3d	normal;

	cone = (t_cone *)info->ptr;
	vect = vect3d_new(cone->pos, ray->orig);
	m = product_dot(ray->dir, cone->dir) *
		ray->t + product_dot(vect, cone->dir);
	info->hit_point = point3d_on_ray(*ray);
	x = (1 + cone->angle * cone->angle) * m;
	normal = vect3d_sub(vect3d_new(cone->pos, info->hit_point),
			vect3d_mult_const(cone->dir, x));
	vect3d_normalize(&normal);
	info->normal = normal;
}
