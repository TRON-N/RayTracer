/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:24:26 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/11 15:24:47 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

t_vect3d	vect3d_add(const t_vect3d a, const t_vect3d b)
{
	t_vect3d res;

	res.x_dist = a.x_dist + b.x_dist;
	res.y_dist = a.y_dist + b.y_dist;
	res.z_dist = a.z_dist + b.z_dist;
	return (res);
}
