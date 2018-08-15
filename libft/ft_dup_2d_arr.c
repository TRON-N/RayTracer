/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_2d_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 15:05:20 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/07/10 08:46:52 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_dup_2d_arr(const void **arr, size_t width, size_t hight)
{
	size_t	h_iter;
	void	**new_arr;

	h_iter = 0;
	new_arr = (void **)ft_memalloc(sizeof(void *) * hight);
	while (h_iter < hight && new_arr != NULL)
	{
		if ((new_arr[h_iter] = ft_memalloc(width)) == NULL)
			return (NULL);
		ft_memmove(new_arr[h_iter], arr[h_iter], width);
		h_iter++;
	}
	return (new_arr);
}
