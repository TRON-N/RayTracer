/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_create_shape.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <lvan-gen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:35:29 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/29 23:34:49 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_prototype.h"

void	init_func_arr(t_c_shape func[5])
{
	func[0] = create_sphere;
	func[1] = create_plane;
	func[2] = create_cone;
	func[3] = create_cylinder;
	func[4] = create_cube;
}

int		read_create_shape(t_shape_c_info sh_info, t_scene_info *info)
{
	t_matrix4_4	obj_to_world;
	t_c_shape	c_shape[5];
	t_object	*link;

	init_func_arr(c_shape);
	if (info == NULL)
		return (-1);
	read_c_obj_t_wrld_m(sh_info.pos, sh_info.rot, obj_to_world);
	link = c_shape[sh_info.id](obj_to_world, sh_info.size, sh_info.look);
	if (link == NULL)
		return (-1);
	if (info->obj_list[0] == NULL)
		info->obj_list[0] = link;
	else
	{
		link->next = info->obj_list[0];
		info->obj_list[0] = link;
	}
	return (1);
}
