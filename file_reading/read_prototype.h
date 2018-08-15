/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_prototype.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <lvan-gen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:11:54 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 16:40:03 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_PROTOTYPE_H
# define READ_PROTOTYPE_H
# include "libft.h"
# include "librt.h"
# include "col_prototype.h"
# include "read_struct.h"
# include "core_rt_prototype.h"
# include "core_rt_struct.h"

int					read_file(int fd, t_scene_info *info);
int					read_shape(int fd, char *line, t_scene_info *info);
int					read_options(int fd, t_scene_info *info);
int					option_checks(int fd, t_option_info *options);
int					scene_checks(int fd, t_option_info *options);
int					read_create_shape(t_shape_c_info sh_i, t_scene_info *info);
int					read_str_t_pnt3d(char *line, t_point3d *point);
int					read_look(int fd, char *line, t_scene_info *info);
int					read_str_t_colour(char *line, t_colour *colour);
void				read_c_obj_t_wrld_m(t_point3d pos, t_point3d rot,
					t_matrix4_4 ret);
int					read_light(int fd, char *line, t_scene_info *info);
int					read_create_light(t_c_light_info *light,
		t_scene_info *info);
int					fov_chk(int fd, t_option_info *options);
int					pix_h_chk(int fd, t_option_info *options);
int					pix_w_chk(int fd, t_option_info *options);
int					aa_chk(int fd, t_option_info *options);
int					reflect_limit_chk(int fd, t_option_info *options);
int					cam_pos_chk(int fd, t_option_info *options);
int					cam_rot_chk(int fd, t_option_info *options);
int					am_light_chk(int fd, t_option_info *options);
int					background_chk(int fd, t_option_info *options);
int					greyscale_chk(int fd, t_option_info *options);
int					diffuse_colour_chk(int fd, t_look_info *look);
int					albedo_chk(int fd, t_look_info *look);
int					diffuse_comp_chk(int fd, t_look_info *look);
int					specular_tint_chk(int fd, t_look_info *look);
int					hardness_chk(int fd, t_look_info *look);
int					specular_comp_chk(int fd, t_look_info *look);
int					reflect_comp_chk(int fd, t_look_info *look);
int					ior_chk(int fd, t_look_info *look);
int					transparent_comp_chk(int fd, t_look_info *look);
int					tex_id_chk(int fd, t_look_info *look);
int					tex_size_chk(int fd, t_look_info *look);
int					tex_rot_chk(int fd, t_look_info *look);

typedef t_object	*(*t_c_shape)(t_matrix4_4 mtrx, double siz, t_shape_look l);
#endif
