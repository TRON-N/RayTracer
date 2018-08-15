/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_mult_const.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 08:43:54 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/15 09:13:12 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

t_vect3d	vect3d_mult_const(const t_vect3d vect, const double value)
{
	t_vect3d ret;

	ret.x_dist = vect.x_dist * value;
	ret.y_dist = vect.y_dist * value;
	ret.z_dist = vect.z_dist * value;
	return (ret);
}
