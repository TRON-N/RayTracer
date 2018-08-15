/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libobj.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:29:07 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/10/01 13:24:25 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBOBJ_H
# define LIBOBJ_H
# include "librt.h"
# include "col.h"
# include <stdlib.h>

# define LIGHT			-1
# define SPHERE			0
# define PLANE			1
# define CONE			2
# define CYLINDER		3
# define CUBE			4

# define LIGHT_DISTANT	0
# define LIGHT_POINT	1

# define MIN 			0
# define MAX			1

typedef struct	s_intsect_info
{
	int				obj_id;
	int				tri_indx;
	t_vect3d		normal;
	void			*ptr;
	t_point2d		uv;
	double			albedo;
	t_point3d		hit_point;
	t_shape_look	look;
	double			ior[2];
	double			n_dot_i;
}				t_intsect_info;
typedef	struct	s_ray
{
	t_point3d		orig;
	t_vect3d		dir;
	double			t;
}				t_ray;
typedef struct	s_mx
{
	double			min;
	double			max;
}				t_mx;
/*
**	SHAPES:
*/
typedef struct	s_sphere
{
	t_point3d		pos;
	double			radius;
}				t_sphere;
typedef struct	s_plane
{
	t_point3d		pos;
	t_vect3d		normal;
}				t_plane;
typedef struct	s_cone
{
	t_point3d		pos;
	t_vect3d		dir;
	double			angle;
}				t_cone;
typedef struct	s_cylinder
{
	t_point3d		pos;
	t_vect3d		dir;
	double			len;
	double			radius;
}				t_cylinder;
typedef struct	s_cube
{
	t_point3d		bounds[2];
	t_point3d		centre;
}				t_cube;

/*
**	LIGHTS:
*/
typedef struct	s_light_info
{
	t_colour		energy;
	t_vect3d		rev_dir;
	t_vect3d		dir;
	double			l_to_p_dist;
}				t_light_info;
typedef struct	s_light_distant
{
	t_vect3d		dir;
	t_colour		colour;
	double			intensity;
}				t_light_distant;
typedef struct	s_light_point
{
	t_point3d		pos;
	t_colour		colour;
	double			intensity;
}				t_light_point;
/*
**	t_shape's id variable holds an int that represents an object
**	represented by the definitions SPHERE, PLANE, etc.
*/
typedef struct	s_object
{
	int				id;
	int				color;
	t_shape_look	look;
	void			*ptr;
	struct s_object	*next;
}				t_object;
t_point3d		point3d_on_ray(const t_ray ray);
void			add_object(t_object **object_list, t_object *new_object);
void			delete_object(t_object **object_list, t_object *object);
void			sphere_info(t_ray *ray, t_intsect_info *info);
void			plane_info(t_ray *ray, t_intsect_info *info);
void			cone_info(t_ray *ray, t_intsect_info *info);
void			cube_info(t_ray *ray, t_intsect_info *info);
void			cylinder_info(t_ray *ray, t_intsect_info *info);
t_object		*create_sphere(t_matrix4_4 pos, double radius,
		t_shape_look look);
t_object		*create_plane(t_matrix4_4 pos, double size, t_shape_look look);
t_object		*create_cone(t_matrix4_4 pos, double angle, t_shape_look look);
t_object		*create_cube(t_matrix4_4 pos, double size, t_shape_look look);
t_object		*create_cylinder(t_matrix4_4 pos, double radius,
		t_shape_look look);
void			assign_sphere(t_object *obj, t_sphere *sphere);
int				sphere_intsct(t_ray *ray, void *ptr);
int				plane_intsct(t_ray *ray, void *ptr);
int				cone_intsct(t_ray *ray, void *ptr);
int				cylinder_intsct(t_ray *ray, void *ptr);
int				cube_intsct(t_ray *ray, void *ptr);
t_object		*create_light_distant(t_vect3d dir, double intsy,
		t_colour colour);
t_object		*create_light_point(double intsy, t_colour colour,
		t_point3d pos);
t_light_info	light_distant_info(t_intsect_info *info, void *ptr);
t_light_info	light_point_info(t_intsect_info *info, void *ptr);
#endif
