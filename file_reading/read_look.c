/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_look.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 23:39:53 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/10/01 13:11:48 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_prototype.h"

/*
**	look: NUMBER
**	diffuse_colour: 	t_colour
**	albedo:			double
**	diffuse_comp:		double
**	specular_tint		t_colour
**	hardness:		double
**	specular_comp:		double
**	reflect_comp:		double
**	ior:			double
**	transparent_comp:	double
**	texture_id: int
**	texture_size: double (positive)
**	texture_rot: double (radians)
*/

int		check_look_values(int fd, t_look_info *l_info)
{
	int	i;

	i = 0;
	i += diffuse_colour_chk(fd, l_info);
	i += albedo_chk(fd, l_info);
	i += diffuse_comp_chk(fd, l_info);
	i += specular_tint_chk(fd, l_info);
	i += hardness_chk(fd, l_info);
	i += specular_comp_chk(fd, l_info);
	i += reflect_comp_chk(fd, l_info);
	i += ior_chk(fd, l_info);
	i += transparent_comp_chk(fd, l_info);
	i += tex_id_chk(fd, l_info);
	i += tex_size_chk(fd, l_info);
	i += tex_rot_chk(fd, l_info);
	if (i == 12)
		return (1);
	return (-1);
}

void	create_look(t_look_info *l_info, t_scene_info *info)
{
	info->look[l_info->id].diffuse_colour = l_info->diffuse_colour;
	info->look[l_info->id].albedo = l_info->albedo;
	info->look[l_info->id].diffuse_comp = l_info->diffuse_comp;
	info->look[l_info->id].specular_tint = l_info->specular_tint;
	info->look[l_info->id].hardness = l_info->hardness;
	info->look[l_info->id].specular_comp = l_info->specular_comp;
	info->look[l_info->id].reflect_comp = l_info->reflect_comp;
	info->look[l_info->id].ior = l_info->ior;
	info->look[l_info->id].transparent_comp = l_info->transparent_comp;
	info->look[l_info->id].tex = col_look_to_tex(info->look[l_info->tex_id]);
	info->look[l_info->id].tex_size = l_info->tex_size;
	info->look[l_info->id].tex_rot = DEG_TO_RAD(l_info->tex_rot);
}

int		read_look(int fd, char *line, t_scene_info *info)
{
	t_look_info	l_info;

	l_info.id = ft_atoi(line + 6);
	if (l_info.id < 0 || l_info.id >= LOOK_NUM)
	{
		ft_putendl("ERROR: INVALID LOOK ID");
		return (-1);
	}
	if (check_look_values(fd, &l_info) == 1)
	{
		create_look(&l_info, info);
		return (1);
	}
	return (-1);
}
