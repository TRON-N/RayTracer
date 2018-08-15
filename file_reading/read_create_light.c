/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_create_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 23:33:44 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/09/29 23:37:34 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_prototype.h"

int		read_create_light(t_c_light_info *light, t_scene_info *info)
{
	t_vect3d	dist;
	t_object	*link;

	if (light->id == 0)
	{
		dist.x_dist = light->area.x;
		dist.y_dist = light->area.y;
		dist.z_dist = light->area.z;
		link = create_light_distant(dist, light->intensity, light->colour);
	}
	else if (light->id == 1)
		link = create_light_point(light->intensity, light->colour, light->area);
	else
		return (-1);
	if (link == NULL)
		return (-1);
	if (info->obj_list[1] == NULL)
		info->obj_list[1] = link;
	else
	{
		link->next = info->obj_list[1];
		info->obj_list[1] = link;
	}
	return (1);
}
