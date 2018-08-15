/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_mix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:54:41 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/12 11:11:33 by cfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

t_colour	col_mix(t_colour c1, t_colour c2, double a)
{
	t_colour ret;

	ret.r = c1.r * (1 - a) + c2.r * a;
	ret.g = c1.g * (1 - a) + c2.g * a;
	ret.b = c1.b * (1 - a) + c2.b * a;
	return (ret);
}
