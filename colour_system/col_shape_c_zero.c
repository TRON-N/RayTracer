/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_shape_c_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:04:11 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/30 17:06:44 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

void	col_shape_c_zero(t_shape_colours *shape_col)
{
	col_set_zero(&(shape_col->diffuse));
	col_set_zero(&(shape_col->specular));
	col_set_zero(&(shape_col->reflect));
	col_set_zero(&(shape_col->transparent));
}
