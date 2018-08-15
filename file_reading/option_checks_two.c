/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_checks_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 23:36:05 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/10/01 12:29:17 by hcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_prototype.h"

int	cam_pos_chk(int fd, t_option_info *options)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "camera_pos:"))
	{
		if (read_str_t_pnt3d(line + 12, &(options->camera_pos)) == 1)
		{
			free(line);
			return (1);
		}
		else
			ft_putendl("ERROR: CAMERA_POS FORMAT INCORRECT.");
	}
	free(line);
	ft_putendl("ERROR: CAMERA_POS NOT FOUND.");
	return (-1);
}

int	cam_rot_chk(int fd, t_option_info *options)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "camera_rot:"))
	{
		if (read_str_t_pnt3d(line + 12, &(options->camera_rot)) == 1)
		{
			free(line);
			return (1);
		}
		else
			ft_putendl("ERROR: CAMERA_POS FORMAT INCORRECT.");
	}
	free(line);
	ft_putendl("ERROR: CAMERA_ROT NOT FOUND.");
	return (-1);
}

int	am_light_chk(int fd, t_option_info *options)
{
	char *line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "ambient_light:"))
	{
		options->ambient_light = ft_atof(line + 15);
		if (0 > options->ambient_light && options->ambient_light > 1)
		{
			ft_putendl("ERROR: AMBIENT_LIGHT NOT IN RANGE (0 - 1).");
			free(line);
			return (-1);
		}
		free(line);
		return (1);
	}
	free(line);
	ft_putendl("ERROR: AMBIENT_LIGHT NOT FOUND.");
	return (-1);
}

int	background_chk(int fd, t_option_info *options)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "background:"))
	{
		if (read_str_t_colour(line + 12, &(options->background)) == 1)
		{
			free(line);
			return (1);
		}
		else
			ft_putendl("ERROR: BACKGROUND FORMAT INCORRECT.");
	}
	free(line);
	ft_putendl("ERROR: BACKGROUND NOT FOUND.");
	return (-1);
}

int	greyscale_chk(int fd, t_option_info *options)
{
	char *line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "greyscale:"))
	{
		options->greyscale = ft_atoi(line + 11);
		if (0 > options->greyscale && options->greyscale > 3)
		{
			ft_putendl("ERROR: GREYSCALE NOT IN RANGE. (0 - 3)");
			free(line);
			return (-1);
		}
		free(line);
		return (1);
	}
	free(line);
	ft_putendl("ERROR: GREYSCALE NOT FOUND.");
	return (-1);
}
