/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:59:43 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/04 16:28:28 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

unsigned int	col_to_int(t_colour col)
{
	return ((unsigned int)ft_clamp(0, 255, col.r) * 256 * 256 +
			(unsigned int)ft_clamp(0, 255, col.g) * 256 +
			(unsigned int)ft_clamp(0, 255, col.b));
}
