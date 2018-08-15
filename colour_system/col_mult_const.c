/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_mult_const.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:16:44 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 13:34:43 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

t_colour	col_mult_const(t_colour c1, double c)
{
	t_colour ret;

	ret.r = c1.r * c;
	ret.g = c1.g * c;
	ret.b = c1.b * c;
	return (ret);
}
