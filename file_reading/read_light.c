/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 22:24:44 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/09/29 23:41:27 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_prototype.h"

/*
**	light: point/distant
**	area: x y z
**	colour: r g b
**	intensity: 2.0
*/

int	chk_area(int fd, t_c_light_info *light)
{
	char *line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "area:"))
	{
		if (read_str_t_pnt3d(line + 6, &(light->area)) == 1)
		{
			free(line);
			return (1);
		}
	}
	free(line);
	return (-1);
}

int	chk_colour(int fd, t_c_light_info *light)
{
	char *line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "colour:"))
	{
		if (read_str_t_colour(line + 8, &(light->colour)) == 1)
		{
			free(line);
			return (1);
		}
	}
	free(line);
	return (-1);
}

int	chk_intensity(int fd, t_c_light_info *light)
{
	char *line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "intensity:"))
	{
		light->intensity = ft_atof(line + 11);
		free(line);
		return (1);
	}
	free(line);
	return (-1);
}

int	check_light_info(int fd, t_c_light_info *light)
{
	int	i;

	i = 0;
	i += chk_area(fd, light);
	i += chk_colour(fd, light);
	i += chk_intensity(fd, light);
	if (i == 3)
		return (1);
	return (-1);
}

int	read_light(int fd, char *line, t_scene_info *info)
{
	t_c_light_info	*light;

	light = (t_c_light_info *)ft_memalloc(sizeof(t_c_light_info));
	light->id = -1;
	if (ft_strstr(line, "point"))
		light->id = LIGHT_POINT;
	else if (ft_strstr(line, "distant"))
		light->id = LIGHT_DISTANT;
	else
		return (-1);
	if (check_light_info(fd, light) == 1)
	{
		return (read_create_light(light, info) == 1);
	}
	return (-1);
}
