/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_sphere_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 10:31:49 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 13:35:14 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

int	col_sphere_texture(t_intsect_info *i_info)
{
	if (i_info->obj_id == SPHERE && i_info->look.tex_size > 0)
	{
		if ((fmod(fabs(i_info->uv.x * i_info->look.tex_size), 1) >
			0.5 ^ fmod(fabs(i_info->uv.y *
				i_info->look.tex_size), 1) > 0.5))
			i_info->look = col_tex_to_look(i_info->look.tex);
		return (1);
	}
	return (0);
}
