/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_fresnel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 09:31:15 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 03:27:33 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

double		col_fresnel(t_intsect_info i_info)
{
	double			cosr;
	double			ior0_o_ior1;
	double			ior[2];
	double			ro;
	double			num;

	ior[0] = i_info.ior[0];
	ior[1] = i_info.ior[1];
	ro = (ior[0] - ior[1]) / (ior[0] + ior[1]);
	ro *= ro;
	if (ior[0] <= ior[1])
		num = 1 - i_info.n_dot_i;
	else
	{
		ior0_o_ior1 = ior[0] / ior[1];
		cosr = ior0_o_ior1 * ior0_o_ior1 * (1 - i_info.n_dot_i *
			i_info.n_dot_i);
		if (cosr > 1)
			return (1);
		num = 1 - sqrt(1 - cosr);
	}
	return (ro + (1 - ro) * num * num * num * num * num);
}
