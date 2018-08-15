/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:50:32 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/10/01 10:52:14 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

t_object	*create_cone(t_matrix4_4 mtrx, double angle, t_shape_look look)
{
	t_object	*link;
	t_cone		*cone;

	link = (t_object *)malloc(sizeof(t_object));
	if ((cone = (t_cone *)malloc(sizeof(t_cone))) == NULL)
		return (NULL);
	cone->pos = point3d_mult_matrix4_4(point3d_create(0, 0, 0), mtrx);
	cone->dir = vect3d_mult_matrix4_4(vect3d_create(0, 1, 0), mtrx);
	vect3d_normalize(&cone->dir);
	cone->angle = DEG_TO_RAD(angle);
	link->id = CONE;
	link->look = look;
	link->ptr = (void *)cone;
	link->next = 0;
	return (link);
}
