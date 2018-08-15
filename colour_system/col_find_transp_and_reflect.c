/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_find_transp_and_reflect.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:00:24 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 03:32:23 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

t_ray		reflect_ray(t_intsect_info i_info, t_ray ray, double bias)
{
	t_ray ret;

	ret.dir = vect3d_reflect(ray.dir, i_info.normal);
	vect3d_normalize(&ret.dir);
	ret.orig = col_point_bias_shift(i_info.hit_point, i_info.normal, bias);
	ray.t = INFINITY;
	return (ret);
}

t_colour	col_find_transp_and_reflect(t_scene_info info,
		t_intsect_info i_info, t_ray ray, t_colour prev)
{
	t_colour	ret[2];
	double		fres;

	col_set_zero(&ret[0]);
	col_set_zero(&ret[1]);
	if (info.opts.reflect_limit > 0 && (i_info.look.reflect_comp > 0 ||
		i_info.look.transparent_comp > 0))
	{
		info.opts.reflect_limit--;
		fres = col_fresnel(i_info);
		if (i_info.look.reflect_comp > 0)
			ret[0] = col_mult_const(find_colour(reflect_ray(i_info,
				ray, 0.0005), info), i_info.look.reflect_comp +
			(1 - i_info.look.reflect_comp) * fres);
		if (i_info.look.transparent_comp > 0)
		{
			ret[1] = col_mult_const(find_colour(col_refract(&ray,
			&i_info, -0.25), info), i_info.look.transparent_comp);
			return (col_add(prev, col_mix(ret[1], ret[0], fres)));
		}
		return (col_add(prev, ret[0]));
	}
	return (prev);
}
