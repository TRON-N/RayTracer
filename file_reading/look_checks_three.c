/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_checks_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 12:36:44 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/10/01 12:57:04 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_prototype.h"

int	tex_id_chk(int fd, t_look_info *look)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "texture_id:"))
	{
		look->tex_id = ft_atoi(line + 12);
		free(line);
		return (1);
	}
	free(line);
	return (-1);
}

int	tex_size_chk(int fd, t_look_info *look)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "texture_size:"))
	{
		look->tex_size = ft_atof(line + 14);
		free(line);
		return (1);
	}
	free(line);
	return (-1);
}

int	tex_rot_chk(int fd, t_look_info *look)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "texture_rot:"))
	{
		look->tex_rot = ft_atof(line + 13);
		free(line);
		return (1);
	}
	free(line);
	return (-1);
}
