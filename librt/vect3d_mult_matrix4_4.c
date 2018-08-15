/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_mult_matrix4_4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 12:43:06 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/30 00:17:41 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

t_vect3d	vect3d_mult_matrix4_4(t_vect3d v, t_matrix4_4 mtrx)
{
	t_vect3d	ret;

	ret.x_dist = v.x_dist * mtrx[0][0] + v.y_dist * mtrx[1][0] +
		v.z_dist * mtrx[2][0];
	ret.y_dist = v.x_dist * mtrx[0][1] + v.y_dist * mtrx[1][1] +
		v.z_dist * mtrx[2][1];
	ret.z_dist = v.x_dist * mtrx[0][2] + v.y_dist * mtrx[1][2] +
		v.z_dist * mtrx[2][2];
	return (ret);
}
