/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:28:36 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/09/30 00:42:35 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libobj.h"

void		delete_object(t_object **object_list, t_object *object)
{
	t_object	*tmp;
	t_object	*prev;

	prev = *object_list;
	while (prev->next != object && prev->next)
		prev = prev->next;
	if (*object_list == object)
		*object_list = object->next;
	else
	{
		tmp = object->next;
		prev->next = tmp;
		object->next = tmp->next;
	}
	free(object->ptr);
	free(object);
}
