/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <lvan-gen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 13:04:55 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 12:56:21 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_STRUCT_H
# define READ_STRUCT_H
# include "librt.h"
# include "col.h"

typedef struct	s_shape_c_info
{
	t_point3d		pos;
	t_point3d		rot;
	double			size;
	t_shape_look	look;
	int				id;
}				t_shape_c_info;

typedef struct	s_option_info
{
	double			fov;
	double			pix_height;
	double			pix_width;
	double			aa;
	double			reflect_limit;
	t_point3d		camera_pos;
	t_point3d		camera_rot;
	double			ambient_light;
	t_colour		background;
	int				greyscale;
}				t_option_info;

typedef struct	s_look_info
{
	int				id;
	t_colour		diffuse_colour;
	double			albedo;
	double			diffuse_comp;
	t_colour		specular_tint;
	double			hardness;
	double			specular_comp;
	double			reflect_comp;
	double			ior;
	double			transparent_comp;
	int				tex_id;
	double			tex_size;
	double			tex_rot;
}				t_look_info;

typedef struct	s_c_light_info
{
	int				id;
	t_point3d		area;
	t_colour		colour;
	double			intensity;
}				t_c_light_info;

#endif
