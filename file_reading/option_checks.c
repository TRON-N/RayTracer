/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 21:33:05 by hcoetzee          #+#    #+#             */
/*   Updated: 2017/10/01 16:24:03 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_prototype.h"

int	fov_chk(int fd, t_option_info *options)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "fov:"))
	{
		options->fov = ft_atof(line + 5);
		if (10 > options->fov && options->fov > 100)
		{
			ft_putendl("ERROR: FOV OUT OF ACCEPTABLE RANGE (10 - 100)");
			free(line);
			return (-1);
		}
		free(line);
		return (1);
	}
	free(line);
	ft_putendl("ERROR: FOV NOT FOUND.");
	return (-1);
}

int	pix_h_chk(int fd, t_option_info *options)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "pix_height:"))
	{
		options->pix_height = ft_atof(line + 12);
		if (options->pix_height <= 0)
		{
			ft_putendl("ERROR: PIX_HEIGHT IS TOO SMALL.");
			free(line);
			return (-1);
		}
		free(line);
		return (1);
	}
	free(line);
	ft_putendl("ERROR: PIX_HEIGHT NOT FOUND.");
	return (-1);
}

int	pix_w_chk(int fd, t_option_info *options)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "pix_width:"))
	{
		options->pix_width = ft_atof(line + 11);
		if (options->pix_width <= 0)
		{
			ft_putendl("ERROR: PIX_WIDTH IS TOO SMALL.");
			free(line);
			return (-1);
		}
		free(line);
		return (1);
	}
	free(line);
	ft_putendl("ERROR: PIX_WIDTH NOT FOUND.");
	return (-1);
}

int	aa_chk(int fd, t_option_info *options)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "aa:"))
	{
		options->aa = ft_atof(line + 4);
		if (options->aa <= 0)
		{
			ft_putendl("ERROR: AA IS TOO SMALL. (Minimum: 1)");
			free(line);
			return (-1);
		}
		free(line);
		return (1);
	}
	free(line);
	ft_putendl("ERROR: AA NOT FOUND.");
	return (-1);
}

int	reflect_limit_chk(int fd, t_option_info *options)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strstr(line, "reflect_limit:"))
	{
		options->reflect_limit = ft_atof(line + 15);
		if (options->reflect_limit <= 0)
		{
			ft_putendl("ERROR: REFLECT_LIMIT IS TOO SMALL. (Minimum: 1)");
			free(line);
			return (-1);
		}
		free(line);
		return (1);
	}
	free(line);
	ft_putendl("ERROR: REFLECT_LIMIT NOT FOUND.");
	return (-1);
}
