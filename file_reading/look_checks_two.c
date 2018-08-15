/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_checks_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 22:10:23 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/09/29 22:20:12 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_prototype.h"

int	specular_comp_chk(int fd, t_look_info *look)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "specular_comp:"))
	{
		look->specular_comp = ft_atof(line + 14);
		free(line);
		return (1);
	}
	free(line);
	return (-1);
}

int	reflect_comp_chk(int fd, t_look_info *look)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "reflect_comp:"))
	{
		look->reflect_comp = ft_atof(line + 13);
		free(line);
		return (1);
	}
	free(line);
	return (-1);
}

int	ior_chk(int fd, t_look_info *look)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "ior:"))
	{
		look->ior = ft_atof(line + 4);
		free(line);
		return (1);
	}
	free(line);
	return (-1);
}

int	transparent_comp_chk(int fd, t_look_info *look)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "transparent_comp:"))
	{
		look->transparent_comp = ft_atof(line + 17);
		free(line);
		return (1);
	}
	free(line);
	return (-1);
}
