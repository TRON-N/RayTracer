/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_r_mask.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 11:55:51 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 12:03:50 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

t_colour	col_r_mask(t_colour col)
{
	col.g = col.r;
	col.b = col.r;
	return (col);
}
