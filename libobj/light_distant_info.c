/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_distant_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 08:22:55 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/04 08:23:28 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

t_light_info	light_distant_info(t_intsect_info *info, void *ptr)
{
	t_light_info			light_info;
	const t_light_distant	*light = (t_light_distant *)ptr;

	light_info.l_to_p_dist = INFINITY;
	if (info->ptr != NULL)
	{
		light_info.energy.r = light->colour.r * light->intensity;
		light_info.energy.g = light->colour.g * light->intensity;
		light_info.energy.b = light->colour.b * light->intensity;
		light_info.rev_dir = vect3d_rev(light->dir);
		light_info.dir = light->dir;
	}
	else
	{
		light_info.energy.r = 1;
		light_info.energy.g = 0;
		light_info.energy.b = 0;
	}
	return (light_info);
}
