/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:43:39 by ajelloul          #+#    #+#             */
/*   Updated: 2025/08/26 19:33:28 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"



int	parse_texture_line(t_cub *cub, char *line, char **path, char *name)
{
	int	len;

	len = ft_strlen(name);
	if (strncmp(name, line, len))
	{
		if (is_duplicate(&cub->duplicate_list, line))
		{
			cub->list_status.is_duplicate_key = true;
			return (1);
		}
		save_image_path(cub, path, line + len);
		return (1);
	}
	return (0);
}


void	parse_all_wall_textures(t_cub *cub, char *line, int i, int *succes)
{
	*succes += parse_texture_line(cub, line + i, &cub->no_texture_path, "NO");
	*succes += parse_texture_line(cub, line + i, &cub->so_texture_path, "SO");
	*succes += parse_texture_line(cub, line + i, &cub->we_texture_path, "WE");
	*succes += parse_texture_line(cub, line + i, &cub->ea_texture_path, "EA");
}
static bool	is_texture_or_color_key(char *str)
{
	if (ft_strncmp("NO ", str, 3) == 0
		|| ft_strncmp("SO ", str, 3) == 0
		|| ft_strncmp("WE ", str, 3) == 0
		|| ft_strncmp("EA ", str, 3) == 0
		|| ft_strncmp("F ", str, 2) == 0
		|| ft_strncmp("C ", str, 2) == 0)
		return (true);
	return (false);
}

int	configuration_key(t_cub *cub, char *line, int i, int *success)
{
	if (is_texture_or_color_key(line + i))
	{
		parse_all_wall_textures(cub, line, i, success);
		parse_colors(cub, line, i, success);
		return (true);
	}
	else if (line[i] == 0 || line[i] == '\n')
		return (true);
	cub->list_status.invalid_key = true;
	return (false);
}
