/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product_cross.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:37:17 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/08/31 13:38:13 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

t_vect3d	product_cross(t_vect3d a, t_vect3d b)
{
	t_vect3d	c;

	c.x_dist = a.y_dist * b.z_dist - a.z_dist * b.y_dist;
	c.y_dist = a.z_dist * b.x_dist - a.x_dist * b.z_dist;
	c.z_dist = a.x_dist * b.y_dist - a.y_dist * b.x_dist;
	return (c);
}
