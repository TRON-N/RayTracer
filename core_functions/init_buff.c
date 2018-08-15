/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 17:04:10 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/10/01 17:04:54 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_rt_prototype.h"

int	init_buff(t_options *opts, t_colour ***buff)
{
	int i;

	i = 0;
	opts->buff_height = opts->pix_height * opts->aa;
	opts->buff_width = opts->pix_width * opts->aa;
	*buff = (t_colour **)malloc(sizeof(t_colour *) * opts->buff_height);
	if (*buff == NULL)
		return (-1);
	while (i < opts->buff_height)
	{
		(*buff)[i] = (t_colour *)malloc(sizeof(t_colour) * opts->buff_width);
		if ((*buff)[i] == NULL)
			return (-1);
		i++;
	}
	return (0);
}
