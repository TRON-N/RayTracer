/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:00:58 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/01 17:36:23 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_rt_prototype.h"

int	init_scene_info(char *file, t_scene_info *scene_info)
{
	int				fd;

	fd = open(file, O_RDONLY);
	scene_info->obj_list[0] = NULL;
	scene_info->obj_list[1] = NULL;
	if (read_file(fd, scene_info) == -1)
	{
		ft_putstr("Error on file read\n");
		return (-1);
	}
	if (fd < 0)
	{
		ft_putendl("Cannot read file.");
		return (-1);
	}
	close(fd);
	return (1);
}
