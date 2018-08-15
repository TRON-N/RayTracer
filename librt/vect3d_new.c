/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 14:20:26 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/08/17 16:41:51 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

t_vect3d	vect3d_new(const t_point3d start, const t_point3d end)
{
	t_vect3d	ret;

	ret.x_dist = end.x - start.x;
	ret.y_dist = end.y - start.y;
	ret.z_dist = end.z - start.z;
	return (ret);
}
