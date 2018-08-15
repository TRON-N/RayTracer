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
	t_vect3d	new;

	new.x_dist = vect.x_dist / r;
	new.y_dist = vect.y_dist / r;
	new.z_dist = vect.z_dist / r;
	return (new);
}
