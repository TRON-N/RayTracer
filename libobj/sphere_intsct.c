/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 13:31:41 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/15 09:18:43 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

static int	solve_quadratic(double a, double b, double c, t_ray *ray)
{
	const double	discriminant = b * b - 4 * a * c;
	double			q;
	double			t[2];

	if (discriminant == 0.0)
	{
		t[0] = -0.5 * b / a;
		t[1] = t[0];
		return (1);
	}
	if (discriminant > 0.0)
	{
		if (b < 0)
			q = -0.5 * (b - sqrt(discriminant));
		else
			q = -0.5 * (b + sqrt(discriminant));
		t[0] = q / a;
		t[1] = c / q;
		if (t[0] > t[1] && t[1] >= 0)
			ray->t = t[1];
		else if (t[0] >= 0)
			ray->t = t[0];
		return (1);
	}
	return (0);
}

int			sphere_intsct(t_ray *ray, void *ptr)
{
	const t_sphere	*sphere = (t_sphere *)ptr;
	const t_vect3d	v = vect3d_new(sphere->pos, ray->orig);
	const double	a = product_dot(ray->dir, ray->dir);
	const double	b = 2 * product_dot(ray->dir, v);
	const double	c = product_dot(v, v) - (sphere->radius * sphere->radius);

	return (solve_quadratic(a, b, c, ray));
}
