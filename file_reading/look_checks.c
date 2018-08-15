/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 21:45:31 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/09/29 22:19:58 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_prototype.h"

int	diffuse_colour_chk(int fd, t_look_info *look)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "diffuse_colour:"))
	{
		if (read_str_t_colour(line + 15, &look->diffuse_colour) == 1)
		{
			free(line);
			return (1);
		}
	}
	free(line);
	return (-1);
}

int	albedo_chk(int fd, t_look_info *look)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "albedo:"))
	{
		look->albedo = ft_atof(line + 7);
		free(line);
		return (1);
	}
	free(line);
	return (-1);
}

int	diffuse_comp_chk(int fd, t_look_info *look)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "diffuse_comp:"))
	{
		look->diffuse_comp = ft_atof(line + 13);
		free(line);
		return (1);
	}
	free(line);
	return (-1);
}

int	specular_tint_chk(int fd, t_look_info *look)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "specular_tint:"))
	{
		if (read_str_t_colour(line + 14, &look->specular_tint) == 1)
		{
			free(line);
			return (1);
		}
	}
	free(line);
	return (-1);
}

int	hardness_chk(int fd, t_look_info *look)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "hardness:"))
	{
		look->hardness = ft_atof(line + 9);
		free(line);
		return (1);
	}
	free(line);
	return (-1);
}
