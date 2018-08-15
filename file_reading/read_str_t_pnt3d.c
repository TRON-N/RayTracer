/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_str_t_pnt3d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <lvan-gen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:46:47 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/25 18:16:48 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_prototype.h"

int	read_str_t_pnt3d(char *line, t_point3d *point)
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
			point->x = ft_atof(str[0]);
			point->y = ft_atof(str[1]);
			point->z = ft_atof(str[2]);
			return (1);
		}
		ft_free_2d_arr((void ***)&(str), indx);
	}
	return (-1);
}
