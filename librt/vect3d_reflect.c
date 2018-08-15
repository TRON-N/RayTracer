/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3d_reflect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 08:39:29 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/15 09:12:34 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

t_vect3d	vect3d_reflect(const t_vect3d incident, const t_vect3d normal)
{
	t_vect3d	n_mult_dot;
	t_vect3d	ret;
	double		dot_p;

	dot_p = product_dot(incident, normal);
	n_mult_dot = vect3d_mult_const(normal, dot_p * 2);
	ret = vect3d_sub(incident, n_mult_dot);
	return (ret);
}
