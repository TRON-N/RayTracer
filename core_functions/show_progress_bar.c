/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_progress_bar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 17:06:08 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/10/01 17:09:55 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_rt_prototype.h"

static void	init_bar(char bar[108])
{
	ft_memset(bar, ' ', 106);
	bar[0] = '[';
	bar[101] = ']';
	bar[103] = '%';
	bar[107] = '\0';
}

int			show_progress_bar(int progress, char *title)
{
	static char	bar[108];
	char		*prcent;

	if (progress == 0)
	{
		ft_putendl(title);
		init_bar(bar);
	}
	if (progress > 99)
	{
		ft_putchar('\n');
		return (0);
	}
	ft_putchar('\r');
	bar[progress + 1] = '#';
	prcent = ft_itoa(progress + 1);
	if (prcent == NULL)
		return (-1);
	ft_strcpy(bar + 104, prcent);
	free(prcent);
	ft_putstr(bar);
	return (0);
}
