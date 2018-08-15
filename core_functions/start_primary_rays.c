/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_primary_rays.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:36:21 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 17:10:53 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_rt_prototype.h"

static void		set_zero(t_point3d *point)
{
	point->x = 0;
	point->y = 0;
	point->z = 0;
}

static t_ray	set_ray(t_point3d canv_pnt, t_options opts)
{
	t_ray		ret;
	t_point3d	orig;

	set_zero(&orig);
	canv_pnt.z = -1;
	ret.orig = point3d_mult_matrix4_4(orig, opts.camera_to_world);
	canv_pnt = point3d_mult_matrix4_4(canv_pnt, opts.camera_to_world);
	ret.dir = vect3d_new(ret.orig, canv_pnt);
	vect3d_normalize(&(ret.dir));
	return (ret);
}

static void		set_fov_and_aspect_scale(double scale[2], t_options opts)
{
	scale[0] = tan(opts.fov * 0.5);
	scale[1] = scale[0] * 1 / (opts.pix_width / opts.pix_height);
}

void			*start_primary_rays(void *info)
{
	t_point2d		rast;
	t_point3d		pnt3d;
	t_ray			ray;
	double			scale_f_a[2];
	t_thread_info	*th_info;

	rast.y = -1;
	th_info = (t_thread_info *)info;
	set_fov_and_aspect_scale(scale_f_a, th_info->opts);
	while (++rast.y < th_info->opts.buff_height)
	{
		rast.x = th_info->min_w - 1.0;
		while (++rast.x < th_info->max_w)
		{
			pnt3d.x = (2 * (rast.x + 0.5) /
				(th_info->opts.buff_width) - 1) * scale_f_a[0];
			pnt3d.y = (1 - 2 * ((rast.y + 0.5) /
				(th_info->opts.buff_height))) * scale_f_a[1];
			ray = set_ray(pnt3d, th_info->opts);
			th_info->buff[(int)rast.y][(int)rast.x] =
			find_colour(ray, (th_info->scene_info));
		}
		(th_info->progress)++;
	}
	return (NULL);
}
