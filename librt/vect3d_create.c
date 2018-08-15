/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 09:00:28 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/30 00:17:07 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

t_vect3d	vect3d_create(double x_dist, double y_dist, double z_dist)
{
	const t_vect3d ret = {x_dist, y_dist, z_dist};

	return (ret);
}
