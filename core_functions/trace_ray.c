/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 14:31:13 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 13:45:36 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_rt_prototype.h"

static void		init_func(t_intsct_fnc intsct[5])
{
	intsct[0] = &sphere_intsct;
	intsct[1] = &plane_intsct;
	intsct[2] = &cone_intsct;
	intsct[3] = &cylinder_intsct;
	intsct[4] = &cube_intsct;
}

t_intsect_info	trace_ray(t_ray *ray, t_object *obj_list)
{
	t_intsect_info		info;
	t_intsct_fnc		intsct[5];
	double				t;

	t = ray->t;
	info.ptr = NULL;
	init_func(intsct);
	while (obj_list)
	{
		if (intsct[obj_list->id](ray, obj_list->ptr))
		{
			if (ray->t < t && ray->t > 0)
			{
				info.ptr = obj_list->ptr;
				info.obj_id = obj_list->id;
				info.look = obj_list->look;
				t = ray->t;
			}
		}
		obj_list = obj_list->next;
	}
	ray->t = t;
	return (info);
}
