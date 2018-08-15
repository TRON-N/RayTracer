/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 08:22:33 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/09/30 00:17:51 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

t_vect3d	vect3d_scale(t_vect3d vect, double s)
{
	t_vect3d	new;

	new.x_dist = vect.x_dist * s;
	new.y_dist = vect.y_dist * s;
	new.z_dist = vect.z_dist * s;
	return (new);
}
