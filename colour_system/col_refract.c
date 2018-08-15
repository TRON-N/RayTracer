/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_refract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:39:53 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 13:38:17 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

static t_vect3d	zero_dir(void)
{
	t_vect3d dir;

	dir.x_dist = 0;
	dir.y_dist = 0;
	dir.z_dist = 0;
	return (dir);
}

t_vect3d		calc_dir(double ior[2], double dot_n_i, t_vect3d n, t_vect3d i)
{
	t_vect3d		dir;
	const double	ior0_o_ior1 = ior[0] / ior[1];
	const double	k = 1 - ior0_o_ior1 * ior0_o_ior1 * (1 - dot_n_i * dot_n_i);
	double			j;
	t_vect3d		n_mult_val;

	if (k < 0.0 && ior[0] > ior[1])
		return (zero_dir());
	j = ior0_o_ior1 * dot_n_i - sqrtf(k);
	n_mult_val = vect3d_mult_const(n, j);
	dir = vect3d_mult_const(i, ior0_o_ior1);
	dir = vect3d_add(dir, n_mult_val);
	vect3d_normalize(&dir);
	return (dir);
}

t_ray			col_refract(t_ray *ray, t_intsect_info *i_info,
		double bias)
{
	t_vect3d	n;
	double		ior[2];
	t_ray		ret;

	ior[0] = i_info->ior[0];
	ior[1] = i_info->ior[1];
	n = i_info->normal;
	ret.dir = calc_dir(ior, i_info->n_dot_i, n, ray->dir);
	ret.orig = col_point_bias_shift(i_info->hit_point, n, bias);
	return (ret);
}
