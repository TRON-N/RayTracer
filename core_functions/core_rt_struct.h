/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_rt_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:12:32 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/03 11:21:12 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_RT_STRUCT_H
# define CORE_RT_STRUCT_H
# include "librt.h"
# include "libobj.h"
# define THREAD_NUM 6
# define LOOK_NUM 5

typedef struct	s_options
{
	double		fov;
	double		pix_height;
	double		pix_width;
	double		buff_height;
	double		buff_width;
	double		aa;
	int			reflect_limit;
	t_matrix4_4	camera_to_world;
	t_matrix4_4	world_to_camera;
	double		ambient_light;
	t_colour	background;
	int			greyscale;
}				t_options;

typedef	struct	s_scene_info
{
	t_options		opts;
	t_object		*obj_list[2];
	t_shape_look	look[LOOK_NUM];
}				t_scene_info;
typedef	struct	s_thread_info
{
	t_colour		**buff;
	t_options		opts;
	t_scene_info	scene_info;
	double			min_w;
	double			max_w;
	int				progress;
}				t_thread_info;
#endif
