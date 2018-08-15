/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_tex_to_look.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 10:44:56 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 13:36:04 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

t_shape_look	col_tex_to_look(t_texture tex)
{
	t_shape_look ret;

	ret.diffuse_colour = tex.diffuse_colour;
	ret.albedo = tex.albedo;
	ret.diffuse_comp = tex.diffuse_comp;
	ret.specular_tint = tex.specular_tint;
	ret.hardness = tex.hardness;
	ret.specular_comp = tex.specular_comp;
	ret.reflect_comp = tex.reflect_comp;
	ret.ior = tex.ior;
	ret.transparent_comp = tex.transparent_comp;
	return (ret);
}
