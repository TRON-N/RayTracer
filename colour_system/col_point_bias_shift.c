/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_point_bias_shift.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <lvan-gen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:05:12 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/27 15:08:50 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

t_point3d	col_point_bias_shift(t_point3d pnt, t_vect3d normal, double bias)
{
	return (point3d_add_vect(pnt, vect3d_mult_const(normal, bias)));
}
