/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 09:57:26 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/26 14:12:30 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

t_object	*create_cylinder(t_matrix4_4 mtrx, double radius, t_shape_look look)
{
	t_object	*link;
	t_cylinder	*cylinder;

	link = (t_object *)malloc(sizeof(t_object));
	if ((cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))) == NULL)
		return (NULL);
	cylinder->pos = point3d_mult_matrix4_4(point3d_create(0, 0, 0), mtrx);
	cylinder->radius = radius;
	cylinder->dir = vect3d_mult_matrix4_4(vect3d_create(0, 1, 0), mtrx);
	vect3d_normalize(&(cylinder->dir));
	link->id = CYLINDER;
	link->look = look;
	link->ptr = (void *)cylinder;
	link->next = 0;
	return (link);
}
