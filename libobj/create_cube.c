/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 00:41:21 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/09/30 00:41:32 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

t_object	*create_cube(t_matrix4_4 mtrx, double size, t_shape_look look)
{
	t_object	*link;
	t_cube		*cube;

	link = (t_object *)malloc(sizeof(t_object));
	if ((cube = (t_cube *)malloc(sizeof(t_cube))) == NULL)
		return (NULL);
	cube->centre = point3d_mult_matrix4_4(point3d_create(0, 0, 0), mtrx);
	cube->bounds[0].x = cube->centre.x - size * 0.5;
	cube->bounds[0].y = cube->centre.y - size * 0.5;
	cube->bounds[0].z = cube->centre.z - size * 0.5;
	cube->bounds[1].x = cube->centre.x + size * 0.5;
	cube->bounds[1].y = cube->centre.y + size * 0.5;
	cube->bounds[1].z = cube->centre.z + size * 0.5;
	link->id = CUBE;
	link->look = look;
	link->ptr = (void *)cube;
	link->next = 0;
	return (link);
}
