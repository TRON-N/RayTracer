/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 08:47:17 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/07/10 08:47:18 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_realloc(void **ptr, size_t old_size, size_t new_size)
{
	void	*tmp;

	tmp = NULL;
	if (new_size != 0 && ptr != NULL)
	{
		if (old_size == 0 || *ptr == NULL)
		{
			if (*ptr != NULL)
				free(*ptr);
			*ptr = ft_memalloc(new_size);
		}
		else if ((tmp = ft_memalloc(old_size)) != NULL)
		{
			ft_memcpy(tmp, *ptr, old_size);
			free(*ptr);
			if ((*ptr = ft_memalloc(new_size)) == NULL)
				return (-1);
			ft_memcpy(*ptr, tmp, old_size);
			free(tmp);
		}
		if (*ptr != NULL)
			return (1);
	}
	return (-1);
}
