/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_rev_norm_and_ndoti.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 23:32:05 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 13:34:23 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

static int	check_if_inside(double *ior0, double *ior1, t_vect3d *n,
		double *cosi)
{
	double tmp;

	if (*cosi < 0)
		*cosi *= -1;
	else
	{
		*n = vect3d_rev(*n);
		tmp = *ior0;
		*ior0 = *ior1;
		*ior1 = tmp;
		return (1);
	}
	return (0);
}

int			col_rev_norm_and_ndoti(t_intsect_info *info, t_ray *ray)
{
	info->n_dot_i = ft_clamp(-1, 1, product_dot(ray->dir, info->normal));
	info->ior[0] = 1;
	info->ior[1] = info->look.ior;
	return (check_if_inside(&(info->ior[0]), &(info->ior[1]), &info->normal,
		&info->n_dot_i));
}
