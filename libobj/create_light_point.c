/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 08:08:43 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/04 09:23:02 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

t_object	*create_light_point(double intensity,
		t_colour colour, t_point3d pos)
{
	t_object		*link;
	t_light_point	*light_point;

	link = (t_object *)malloc(sizeof(t_object));
	light_point = (t_light_point *)malloc(sizeof(t_light_point));
	light_point->intensity = intensity;
	light_point->colour.r = ft_clamp(0, 1, colour.r / 255.0);
	light_point->colour.g = ft_clamp(0, 1, colour.g / 255.0);
	light_point->colour.b = ft_clamp(0, 1, colour.b / 255.0);
	light_point->pos = pos;
	link->id = LIGHT_POINT;
	link->ptr = (void *)light_point;
	link->next = 0;
	return (link);
}
