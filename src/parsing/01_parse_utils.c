/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:45:31 by ajelloul          #+#    #+#             */
/*   Updated: 2025/08/25 17:00:27 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int get_path(char *line, int i)
{
	int	*sub_path;
	int	*path;
	int	cp;

	cp = 0;
	while (line[cp + 1] && line[cp + 1] != '\n')
	{
		cp++;
	}
	sub_path = ft_substr(line, i, cp);
	path = ft_strtrim(sub_path, " ");
	free (sub_path);
	return (path);
}

int save_image_path(t_cub *cub, char **path, char *line)
{
	int	len;
	int i;

	i = 0;
	if (!line || !line[0])
		return (0);
	i = skip_spaces(&line);
	if (line[i] == 0 || line[i] == '\n')
		return (0);
	*path = get_path(line, i);
	if (!*path)
		return (0);
	len = ft_strlen(*path);
	if (len < 4 || ft_strncmp(*path + len - 4, ".png", 4) != 0)
	{
		free(*path);
		*path = NULL;
		cub->list_status.is_wrong_txtr_extension = true;
		return (0);
	}
	return (1);
}
