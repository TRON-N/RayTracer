/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <lvan-gen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:05:37 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/26 16:42:37 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_prototype.h"

static void	set_zero(int ret[4])
{
	ret[0] = 0;
	ret[1] = 0;
	ret[2] = 0;
	ret[3] = 0;
}

static void	init_key_words(char *key_words[6])
{
	key_words[0] = "sphere";
	key_words[1] = "plane";
	key_words[2] = "cone";
	key_words[3] = "cylinder";
	key_words[4] = "cube";
	key_words[5] = "over";
}

static int	set_look(int look_id, t_scene_info *info, t_shape_look *look)
{
	if (look_id >= 0 && look_id < LOOK_NUM)
	{
		*look = info->look[look_id];
		return (1);
	}
	return (-1);
}

static int	shape_info_loop(int fd, t_scene_info *info, t_shape_c_info *sh_info)
{
	char	*line;
	int		ret[4];

	set_zero(ret);
	while ((ret[0] = get_next_line(fd, &line)) == 1 && ret[3] == 0 &&
			ret[2] >= 0 && ret[1] >= 0)
	{
		if (line == NULL)
			return (-1);
		if (ft_strstr(line, "position:"))
			ret[1] = read_str_t_pnt3d(line + 10, &(sh_info->pos));
		else if (ft_strstr(line, "rotation:") && ret[1] == 1)
			ret[2] = read_str_t_pnt3d(line + 10, &(sh_info->rot));
		else if (ft_strstr(line, "size:") && ret[2] == 1)
			sh_info->size = atof(line + 6);
		else if (ft_strstr(line, "look_id:") && sh_info->size
				!= 0 && ret[2] == 1)
			ret[3] = set_look(ft_atoi(line + 9), info, &(sh_info->look));
		free(line);
	}
	free(line);
	if (ret[1] != -1 && ret[2] == 1 && ret[3] == 1 &&
			sh_info->size != 0)
		return (1);
	return (-1);
}

int			read_shape(int fd, char *line, t_scene_info *info)
{
	char			*shapes[6];
	int				id;
	int				ret[4];
	t_shape_c_info	sh_info;

	id = 0;
	ret[1] = 1;
	init_key_words(shapes);
	while (id < 6)
	{
		if (ft_strstr(line, shapes[id]))
			break ;
		id++;
	}
	if (id >= 5)
		return (-1);
	sh_info.id = id;
	free(line);
	if (shape_info_loop(fd, info, &sh_info) == 1)
		return (read_create_shape(sh_info, info));
	return (-1);
}
