/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 08:47:08 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/07/10 08:47:10 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned int hex)
{
	if (hex >= 16)
	{
		ft_puthex(hex / 16);
		ft_puthex(hex % 16);
	}
	else if (hex > 9)
		ft_putchar('A' + (hex - 10));
	else
		ft_putchar('0' + hex);
}
