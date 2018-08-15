/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 08:47:33 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/04 11:12:23 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

void	plane_info(t_ray *ray, t_intsect_info *info)
{
	const t_plane *plane = (t_plane *)info->ptr;

	info->hit_point = point3d_on_ray(*ray);
	info->normal = plane->normal;
}
