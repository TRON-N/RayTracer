/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_specular.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:24:54 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/12 07:51:58 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

void	col_specular(t_intsect_info *i_info, t_light_info *l_info,
		t_shape_colours *shape_col, t_ray *ray)
{
	t_vect3d	reflect_vect;
	double		specular;

	reflect_vect = vect3d_reflect(l_info->dir, i_info->normal);
	specular = pow(ft_max(0.0, product_dot(vect3d_rev(ray->dir), reflect_vect)),
			i_info->look.hardness);
	shape_col->specular.r += specular * l_info->energy.r;
	shape_col->specular.g += specular * l_info->energy.g;
	shape_col->specular.b += specular * l_info->energy.b;
}
