/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intsct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 12:00:56 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/10/06 11:48:29 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

static int	solve_quadratic(double a, double b, double c, t_ray *ray)
{
	const double	discriminant = b * b - 4 * a * c;
	double			t[2];

	if (discriminant == 0.0)
	{
		ray->t = -b / 2 * a;
		return (1);
	}
	if (discriminant > 0.0)
	{
		t[0] = (-b - sqrt(discriminant)) / (2 * a);
		t[1] = (-b + sqrt(discriminant)) / (2 * a);
		if (t[0] < t[1])
		{
			ray->t = t[0];
			return (1);
		}
		else
		{
			ray->t = t[1];
			return (1);
		}
	}
	return (0);
}

int			cone_intsct(t_ray *ray, void *ptr)
{
	double		a;
	double		b;
	double		c;
	t_cone		*cone;
	t_vect3d	v;

	cone = (t_cone *)ptr;
	v = vect3d_new(cone->pos, ray->orig);
	a = product_dot(ray->dir, cone->dir) * product_dot(ray->dir, cone->dir)
		- (0.5 + (0.5 * cos(2 * cone->angle)));
	b = 2 * ((product_dot(ray->dir, cone->dir) * product_dot(v, cone->dir))
		- (product_dot(ray->dir, v)
		* (0.5 + (0.5 * cos(2 * cone->angle)))));
	c = (product_dot(v, cone->dir) * product_dot(v, cone->dir))
		- (product_dot(v, v) * (0.5 + (0.5 * cos(2 * cone->angle))));
	return (solve_quadratic(a, b, c, ray));
}
