/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_str_t_colour.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <lvan-gen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 09:33:41 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/27 09:40:22 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_prototype.h"

int	read_str_t_colour(char *line, t_colour *colour)
{
	char	**str;
	int		indx;

	indx = 0;
	str = ft_strsplit(line, ' ');
	if (str != NULL)
	{
		while (*(str + indx) != NULL)
			indx++;
		if (indx == 3)
		{
			colour->r = ft_atof(str[0]);
			colour->g = ft_atof(str[1]);
			colour->b = ft_atof(str[2]);
			return (1);
		}
		ft_free_2d_arr((void ***)&(str), indx);
	}
	return (-1);
}
