/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 09:52:47 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/30 00:02:40 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

void	cylinder_info(t_ray *ray, t_intsect_info *info)
{
	t_vect3d			normal;
	const t_cylinder	*cylinder = (t_cylinder *)info->ptr;
	const t_vect3d		v = vect3d_new(cylinder->pos, ray->orig);
	double				m;

	m = product_dot(ray->dir, cylinder->dir) * ray->t
		+ product_dot(v, cylinder->dir);
	info->hit_point = point3d_on_ray(*ray);
	normal = vect3d_sub(vect3d_new(cylinder->pos, info->hit_point),
			vect3d_mult_const(cylinder->dir, m));
	vect3d_normalize(&normal);
	info->normal = normal;
}
