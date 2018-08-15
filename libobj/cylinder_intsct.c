/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intsct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 08:52:40 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/19 12:14:28 by lvan-gen         ###   ########.fr       */
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

int			cylinder_intsct(t_ray *ray, void *ptr)
{
	const t_cylinder	*cylinder = (t_cylinder *)ptr;
	const t_vect3d		v = vect3d_new(cylinder->pos, ray->orig);
	double				a;
	double				b;
	double				c;

	a = product_dot(ray->dir, ray->dir) -
		pow(product_dot(ray->dir, cylinder->dir), 2);
	b = (product_dot(ray->dir, v) - product_dot(ray->dir, cylinder->dir) *
		product_dot(v, cylinder->dir)) * 2;
	c = product_dot(v, v) - pow(product_dot(v, cylinder->dir), 2) -
		cylinder->radius * cylinder->radius;
	return (solve_quadratic(a, b, c, ray));
}
