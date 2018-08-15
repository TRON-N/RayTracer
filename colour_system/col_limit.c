/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_limit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:53:18 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/04 16:28:45 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "col_prototype.h"

t_colour	col_limit(t_colour col)
{
	t_colour	ret;

	ret.r = ft_clamp(0, 256, col.r);
	ret.g = ft_clamp(0, 256, col.g);
	ret.b = ft_clamp(0, 256, col.b);
	return (ret);
}
