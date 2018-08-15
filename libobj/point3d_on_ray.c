/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3d_on_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 14:52:12 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/08/29 15:06:50 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

t_point3d	point3d_on_ray(const t_ray ray)
{
	t_point3d	new_point;

	new_point.x = ray.orig.x + (ray.dir.x_dist * ray.t);
	new_point.y = ray.orig.y + (ray.dir.y_dist * ray.t);
	new_point.z = ray.orig.z + (ray.dir.z_dist * ray.t);
	return (new_point);
}
