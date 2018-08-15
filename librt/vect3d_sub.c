/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:37:48 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/09/18 09:09:24 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

t_vect3d	vect3d_sub(const t_vect3d a, const t_vect3d b)
{
	t_vect3d res;

	res.x_dist = a.x_dist - b.x_dist;
	res.y_dist = a.y_dist - b.y_dist;
	res.z_dist = a.z_dist - b.z_dist;
	return (res);
}
