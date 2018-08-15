/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_look_to_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 11:00:38 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 13:33:28 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

t_texture	col_look_to_tex(t_shape_look look)
{
	t_texture tex;

	tex.diffuse_colour = look.diffuse_colour;
	tex.albedo = look.albedo;
	tex.diffuse_comp = look.diffuse_comp;
	tex.specular_tint = look.specular_tint;
	tex.hardness = look.hardness;
	tex.specular_comp = look.specular_comp;
	tex.reflect_comp = look.reflect_comp;
	tex.ior = look.ior;
	tex.transparent_comp = look.transparent_comp;
	return (tex);
}
