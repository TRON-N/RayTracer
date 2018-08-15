/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 08:31:10 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/15 09:13:42 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

double	vect3d_len(t_vect3d vect)
{
	return (sqrt(vect.x_dist * vect.x_dist + vect.y_dist * vect.y_dist +
				vect.z_dist * vect.z_dist));
}
