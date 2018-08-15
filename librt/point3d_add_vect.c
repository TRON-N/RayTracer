/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3d_add_vect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <lvan-gen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:50:55 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/30 00:15:56 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

t_point3d	point3d_add_vect(t_point3d pnt, t_vect3d vect)
{
	t_point3d	ret;

	ret.x = pnt.x + vect.x_dist;
	ret.y = pnt.y + vect.y_dist;
	ret.z = pnt.z + vect.z_dist;
	return (ret);
}
