/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intsct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:29:08 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/09/27 14:34:53 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

int	plane_intsct(t_ray *ray, void *ptr)
{
	t_plane			*plane;
	double			denom;
	t_vect3d		rti;

	plane = (t_plane *)ptr;
	denom = product_dot(ray->dir, plane->normal);
	if (fabs(denom) > 1e-6)
	{
		rti = vect3d_new(ray->orig, plane->pos);
		ray->t = product_dot(plane->normal, rti) / denom;
		if (denom > 0)
			plane->normal = vect3d_rev(plane->normal);
		return (ray->t >= 0.0);
	}
	return (0);
}
