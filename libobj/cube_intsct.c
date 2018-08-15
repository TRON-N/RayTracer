/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_intsct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:18:36 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/30 01:37:23 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

static void	precompute(t_vect3d d, int sign[3], double inv_dir[3])
{
	inv_dir[0] = 1.0 / d.x_dist;
	inv_dir[1] = 1.0 / d.y_dist;
	inv_dir[2] = 1.0 / d.z_dist;
	sign[0] = (inv_dir[0] < 0.0);
	sign[1] = (inv_dir[1] < 0.0);
	sign[2] = (inv_dir[2] < 0.0);
}

void		norm_if_one(t_point3d t_vals[2])
{
	if (t_vals[MIN].y > t_vals[MIN].x)
		t_vals[MIN].x = t_vals[MIN].y;
	if (t_vals[MAX].y < t_vals[MAX].x)
		t_vals[MAX].x = t_vals[MAX].y;
}

void		norm_if_two(t_point3d t_vals[2])
{
	if (t_vals[MIN].z > t_vals[MIN].x)
		t_vals[MIN].x = t_vals[MIN].z;
	if (t_vals[MAX].z < t_vals[MAX].x)
		t_vals[MAX].x = t_vals[MAX].z;
}

int			cube_intsct(t_ray *ray, void *ptr)
{
	const t_cube	*cube = (t_cube *)ptr;
	t_point3d		t_vals[2];
	double			inv_dir[3];
	int				sign[3];

	precompute(ray->dir, sign, inv_dir);
	t_vals[MIN].x = (cube->bounds[sign[0]].x - ray->orig.x) * inv_dir[0];
	t_vals[MAX].x = (cube->bounds[1 - sign[0]].x - ray->orig.x) * inv_dir[0];
	t_vals[MIN].y = (cube->bounds[sign[1]].y - ray->orig.y) * inv_dir[1];
	t_vals[MAX].y = (cube->bounds[1 - sign[1]].y - ray->orig.y) * inv_dir[1];
	if ((t_vals[MIN].x > t_vals[MAX].y) || (t_vals[MIN].y > t_vals[MAX].x))
		return (0);
	norm_if_one(t_vals);
	t_vals[MIN].z = (cube->bounds[sign[2]].z - ray->orig.z) * inv_dir[2];
	t_vals[MAX].z = (cube->bounds[1 - sign[2]].z - ray->orig.z) * inv_dir[2];
	if ((t_vals[MIN].x > t_vals[MAX].z) || (t_vals[MIN].z > t_vals[MAX].x))
		return (0);
	norm_if_two(t_vals);
	if ((ray->t = t_vals[MIN].x) < 0)
		if ((ray->t = t_vals[MAX].x) < 0)
			return (0);
	return (1);
}
