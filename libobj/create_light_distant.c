/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_distant_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 16:36:33 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/04 08:13:00 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

t_object	*create_light_distant(t_vect3d dir, double intensity,
		t_colour colour)
{
	t_object		*link;
	t_light_distant	*light_distant;

	link = (t_object *)malloc(sizeof(t_object));
	light_distant = (t_light_distant *)malloc(sizeof(t_light_distant));
	light_distant->dir = dir;
	vect3d_normalize(&light_distant->dir);
	light_distant->intensity = intensity;
	light_distant->colour.r = ft_clamp(0, 1, colour.r / 255.0);
	light_distant->colour.g = ft_clamp(0, 1, colour.g / 255.0);
	light_distant->colour.b = ft_clamp(0, 1, colour.b / 255.0);
	link->id = LIGHT_DISTANT;
	link->ptr = (void *)light_distant;
	link->next = 0;
	return (link);
}
