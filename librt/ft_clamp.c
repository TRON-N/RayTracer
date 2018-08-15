/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 09:15:45 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/15 09:16:45 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

double	ft_clamp(double minimum, double maximum, double value)
{
	return (ft_max(minimum, ft_min(maximum, value)));
}
