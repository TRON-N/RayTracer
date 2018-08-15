/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_prototype.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:18:42 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/04 15:12:52 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COL_PROTOTYPE_H
# define COL_PROTOTYPE_H
# include "core_rt_prototype.h"
# include "core_rt_struct.h"
# include <SDL.h>
# include "libobj.h"
# include "librt.h"
# include <math.h>
# include "col.h"

void			col_apply_bandlimit(t_options opts, t_colour **buff, t_colour **buff2,
		t_point2d rast, double size);
void			col_apply_aa_blend(t_colour **buff, t_options opts,
		t_colour **buff2);
int				col_sdl_fill_surface(SDL_Surface *surface, t_colour **buff);
t_ray			col_refract(t_ray *ray, t_intsect_info *info, double bias);
t_colour		col_mix(t_colour c1, t_colour c2, double a);
t_colour		col_add(t_colour c1, t_colour c2);
t_colour		col_split_int(int i);
t_colour		col_mult(t_colour c1, t_colour c2);
t_colour		col_mult_const(t_colour c1, double c);
t_colour		col_limit(t_colour col);
t_colour		col_r_mask(t_colour col);
t_colour		col_g_mask(t_colour col);
t_colour		col_b_mask(t_colour col);
t_colour		col_find_diffuse_and_specular(t_scene_info info,
		t_intsect_info i_info, t_ray ray);
t_colour		col_find_transp_and_reflect(t_scene_info info,
		t_intsect_info i_info, t_ray ray, t_colour prev);
t_point3d		col_point_bias_shift(t_point3d pnt, t_vect3d normal,
		double bias);
t_texture		col_look_to_tex(t_shape_look look);
t_shape_look	col_tex_to_look(t_texture tex);
double			col_fresnel(t_intsect_info i_info);
void			col_diffuse(t_intsect_info *info, t_light_info *light_info,
		t_shape_colours *shape_col);
void			col_shape_c_zero(t_shape_colours *shape_col);
void			col_set_zero(t_colour *col);
void			col_specular(t_intsect_info *i_info, t_light_info *l_info,
		t_shape_colours *shape_col, t_ray *ray);
int				col_is_shadow(t_object *obj_list, t_light_info *l_info,
		t_intsect_info *info);
int				col_rev_norm_and_ndoti(t_intsect_info *i_info, t_ray *ray);
unsigned int	col_to_int(t_colour col);
int				col_sphere_texture(t_intsect_info *i_info);
#endif
