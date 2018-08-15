/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 14:38:39 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/28 10:56:48 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

t_object	*create_plane(t_matrix4_4 mtrx, double size, t_shape_look look)
{
	t_object	*link;
	t_plane		*plane;

	link = (t_object *)malloc(sizeof(t_object));
	if ((plane = (t_plane *)malloc(sizeof(t_plane))) == NULL || size == 0.0)
		return (NULL);
	plane->pos = point3d_mult_matrix4_4(point3d_create(0, 0, 0), mtrx);
	plane->normal = vect3d_mult_matrix4_4(vect3d_create(0, 1, 0), mtrx);
	vect3d_normalize(&(plane->normal));
	link->id = PLANE;
	link->look = look;
	link->ptr = (void *)plane;
	link->next = 0;
	return (link);
}
