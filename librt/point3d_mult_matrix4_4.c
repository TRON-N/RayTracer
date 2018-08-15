/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3d_mult_matrix4_4.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:43:21 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/09/26 09:23:03 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

t_point3d	point3d_mult_matrix4_4(t_point3d p, t_matrix4_4 mtrx)
{
	t_point3d	ret;
	double		w;

	ret.x = p.x * mtrx[0][0] + p.y * mtrx[1][0] + p.z * mtrx[2][0]
		+ mtrx[3][0];
	ret.y = p.x * mtrx[0][1] + p.y * mtrx[1][1] + p.z * mtrx[2][1]
		+ mtrx[3][1];
	ret.z = p.x * mtrx[0][2] + p.y * mtrx[1][2] + p.z * mtrx[2][2]
		+ mtrx[3][2];
	w = p.x * mtrx[0][3] + p.y * mtrx[1][3] + p.z * mtrx[2][3] + mtrx[3][3];
	if (w != 1 && w != 0)
	{
		ret.x /= w;
		ret.y /= w;
		ret.z /= w;
	}
	return (ret);
}
