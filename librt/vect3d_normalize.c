/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_normalzie.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 14:20:51 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/08/17 14:21:29 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

void	vect3d_normalize(t_vect3d *vec)
{
	double	magnitude;

	magnitude = sqrt(vec->x_dist * vec->x_dist + vec->y_dist
				* vec->y_dist + vec->z_dist * vec->z_dist);
	vec->x_dist /= magnitude;
	vec->y_dist /= magnitude;
	vec->z_dist /= magnitude;
}
