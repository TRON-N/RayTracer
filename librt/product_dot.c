/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:38:31 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/08/31 13:38:52 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

double		product_dot(t_vect3d a, t_vect3d b)
{
	return (a.x_dist * b.x_dist + a.y_dist * b.y_dist
			+ a.z_dist * b.z_dist);
}
