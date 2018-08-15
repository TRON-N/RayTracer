/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 23:38:40 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/10/01 16:26:14 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_prototype.h"

/*
**	EXAMPLE:
**	options:
**	fov: 45.55
**	pix_height: 600
**	pix_width: 800
**	aa: 4
**	reflect_limit: 3
**	camera_pos: 0 1 0
**	camera_rot: 1 0 1
**	ambient_light 0.7
**	background: 255 255 255
**	greyscale: 0
*/

void	init_options(t_option_info *options, t_scene_info *info)
{
	info->opts.fov = DEG_TO_RAD(options->fov);
	info->opts.pix_height = options->pix_height;
	info->opts.pix_width = options->pix_width;
	info->opts.aa = options->aa;
	info->opts.reflect_limit = options->reflect_limit;
	read_c_obj_t_wrld_m(options->camera_pos, options->camera_rot,
			info->opts.camera_to_world);
	info->opts.ambient_light = options->ambient_light;
	info->opts.background = options->background;
	info->opts.greyscale = options->greyscale;
}

int		find_option_values(int fd, t_option_info *options)
{
	int	i;

	i = 0;
	i += fov_chk(fd, options);
	i += pix_h_chk(fd, options);
	i += pix_w_chk(fd, options);
	i += aa_chk(fd, options);
	i += reflect_limit_chk(fd, options);
	i += cam_pos_chk(fd, options);
	i += cam_rot_chk(fd, options);
	i += am_light_chk(fd, options);
	i += background_chk(fd, options);
	i += greyscale_chk(fd, options);
	if (i == 10)
		return (1);
	return (-1);
}

int		read_options(int fd, t_scene_info *info)
{
	t_option_info *opt_info;

	opt_info = (t_option_info *)ft_memalloc(sizeof(t_option_info));
	if (find_option_values(fd, opt_info) == 1)
	{
		init_options(opt_info, info);
		return (1);
	}
	return (-1);
}
