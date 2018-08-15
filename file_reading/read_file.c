/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <lvan-gen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:14:27 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/29 23:44:52 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_prototype.h"

static void	set_ret_zero(int ret[5])
{
	ret[0] = 0;
	ret[1] = 0;
	ret[2] = 0;
	ret[3] = 0;
	ret[4] = 0;
}

int			read_file(int fd, t_scene_info *info)
{
	int		option_count;
	char	*line;
	int		ret[5];

	option_count = 0;
	set_ret_zero(ret);
	while ((ret[0] = get_next_line(fd, &line)))
	{
		if (ft_strstr(line, "shape:"))
			ret[1] = read_shape(fd, line, info);
		if (ft_strstr(line, "light"))
			ret[2] = read_light(fd, line, info);
		if (ft_strstr(line, "options:"))
		{
			ret[3] = read_options(fd, info);
			option_count++;
		}
		if (ft_strstr(line, "look:"))
			ret[4] = read_look(fd, line, info);
	}
	free(line);
	if (ret[0] != -1 && ret[1] != -1 && ret[2] != -1 &&
			ret[3] != -1 && ret[4] != -1)
		return (1);
	return (-1);
}
