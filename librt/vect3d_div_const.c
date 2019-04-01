/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_div_const.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 09:08:45 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/18 09:08:49 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

t_vect3d	vect3d_div_const(const t_vect3d vect, const double r)
{
	t_vect3d	neww;

	neww.x_dist = vect.x_dist / r;
	neww.y_dist = vect.y_dist / r;
	neww.z_dist = vect.z_dist / r;
	return (neww);
}
