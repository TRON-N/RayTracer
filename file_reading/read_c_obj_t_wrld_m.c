/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_c_obj_t_wrld_m.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 11:55:04 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/29 23:33:36 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_prototype.h"

void	read_c_obj_t_wrld_m(t_point3d pos, t_point3d rot, t_matrix4_4 ret)
{
	t_matrix4_4	rot_x;
	t_matrix4_4 rot_y;
	t_matrix4_4	rot_z;
	t_matrix4_4 trans;
	t_matrix4_4 tmp;

	rot_x_matrix4_4(rot_x, rot.x);
	rot_y_matrix4_4(rot_y, rot.y);
	rot_z_matrix4_4(rot_z, rot.z);
	trans_matrix4_4(trans, pos);
	matrix4_4_mult_matrix(rot_x, rot_y, ret);
	matrix4_4_mult_matrix(ret, rot_z, tmp);
	matrix4_4_mult_matrix(tmp, trans, ret);
}
