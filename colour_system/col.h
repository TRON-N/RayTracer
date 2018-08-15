/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:19:46 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 13:28:49 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COL_H
# define COL_H

typedef struct	s_colour
{
	double		r;
	double		g;
	double		b;
}				t_colour;

typedef struct	s_texture
{
	t_colour	diffuse_colour;
	double		albedo;
	double		diffuse_comp;
	t_colour	specular_tint;
	double		hardness;
	double		specular_comp;
	double		reflect_comp;
	double		ior;
	double		transparent_comp;
}				t_texture;

typedef struct	s_shape_look
{
	t_colour	diffuse_colour;
	double		albedo;
	double		diffuse_comp;
	t_colour	specular_tint;
	double		hardness;
	double		specular_comp;
	double		reflect_comp;
	double		ior;
	double		transparent_comp;
	t_texture	tex;
	double		tex_size;
	double		tex_rot;
}				t_shape_look;

typedef struct	s_shape_colours
{
	t_colour	diffuse;
	t_colour	specular;
	t_colour	reflect;
	t_colour	transparent;
}				t_shape_colours;

#endif
