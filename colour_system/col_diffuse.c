/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_diffuse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:21:19 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/27 12:36:40 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

void	col_diffuse(t_intsect_info *info, t_light_info *light_info,
		t_shape_colours *shape_col)
{
	double	shading;

	shading = (info->look.albedo / M_PI) * ft_max(0.0,
			product_dot(info->normal, light_info->rev_dir));
	shape_col->diffuse.r += shading * light_info->energy.r;
	shape_col->diffuse.g += shading * light_info->energy.g;
	shape_col->diffuse.b += shading * light_info->energy.b;
}
