/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:28:52 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/09/30 13:21:37 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

t_object	*create_sphere(t_matrix4_4 mtrx, double radius, t_shape_look look)
{
	t_object	*link;
	t_sphere	*sphere;

	link = (t_object *)malloc(sizeof(t_object));
	if ((sphere = (t_sphere *)malloc(sizeof(t_sphere))) == NULL)
		return (NULL);
	sphere->pos = point3d_mult_matrix4_4(point3d_create(0, 0, 0), mtrx);
	sphere->radius = radius;
	link->id = SPHERE;
	link->look = look;
	link->ptr = (void *)sphere;
	link->next = 0;
	return (link);
}
