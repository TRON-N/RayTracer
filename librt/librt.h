/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   librt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:44:47 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/09/28 07:53:04 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRT_H
# define LIBRT_H
# include <math.h>
# define DEG_TO_RAD(deg) M_PI / 180.0 * (double)deg

typedef double	t_matrix4_4[4][4];

typedef	struct	s_point2d
{
	double	x;
	double	y;
}				t_point2d;

typedef struct	s_point3d
{
	double	x;
	double	y;
	double	z;
}				t_point3d;

typedef	struct	s_vect3d
{
	double	x_dist;
	double	y_dist;
	double	z_dist;
}				t_vect3d;

double			product_dot(t_vect3d a, t_vect3d b);
double			ft_max(double max, double value);
double			ft_min(double min, double value);
double			ft_clamp(double min, double max, double value);
double			vect3d_len(t_vect3d vect);
t_vect3d		product_cross(t_vect3d a, t_vect3d b);
t_vect3d		vect3d_new(const t_point3d start, const t_point3d end);
t_vect3d		vect3d_sub(const t_vect3d a, const t_vect3d b);
t_vect3d		vect3d_add(const t_vect3d a, const t_vect3d b);
t_vect3d		vect3d_rev(const t_vect3d vect);
t_vect3d		vect3d_div_const(const t_vect3d vect, const double r);
t_vect3d		vect3d_mult_const(const t_vect3d vect, const double value);
t_vect3d		vect3d_reflect(const t_vect3d incident, const t_vect3d normal);
t_vect3d		vect3d_scale(t_vect3d vect, double s);
t_vect3d		vect3d_create(double x_dist, double y_dist, double z_dist);
t_vect3d		vect3d_mult_matrix4_4(t_vect3d vec, t_matrix4_4 mtrx);
t_point3d		point3d_mult_matrix4_4(t_point3d p, t_matrix4_4 mtrx);
t_point3d		point3d_create(double x, double y, double z);
t_point3d		point3d_add_vect(t_point3d pnt, t_vect3d vect);
void			vect3d_normalize(t_vect3d *vec);
void			rot_x_matrix4_4(t_matrix4_4 matrix, double deg);
void			rot_y_matrix4_4(t_matrix4_4 matrix, double deg);
void			rot_z_matrix4_4(t_matrix4_4 matrix, double deg);
void			trans_matrix4_4(t_matrix4_4 matrix, t_point3d pnt);
void			ident_matrix4_4(t_matrix4_4 matrix);
void			matrix4_4_mult_matrix(t_matrix4_4 m1, t_matrix4_4 m2,
					t_matrix4_4 r);

#endif
