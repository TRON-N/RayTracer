/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:47:27 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/01 14:49:51 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

t_vect3d	vect3d_rev(const t_vect3d vect)
{
	t_vect3d ret;

	ret.x_dist = -vect.x_dist;
	ret.y_dist = -vect.y_dist;
	ret.z_dist = -vect.z_dist;
	return (ret);
}
