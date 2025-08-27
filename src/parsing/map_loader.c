/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:25:11 by ajelloul          #+#    #+#             */
/*   Updated: 2025/08/27 16:01:01 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	valid_file_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".cub", 4))
	{
		printf(RED "\nError: file must be a [.cub]\n\n" RESET);
		return (1);
	}
	return (0); 
}

int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(RED "\nError opening file ");
		printf("\n");
		return (-1);
	}
	return (fd);
}

void	delete_duplicate_list(t_duplicat_list *list)
{
	t_duplicat_list	*key;

	while (list)
	{
		key = list;
		list = list->next;
		free(key);
		key = NULL;
	}
}

int	parse_game_settings(t_cub *cub, int fd)
{
	char	*line;
	int		succes;
	int		i;

	succes = 0;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = skip_spaces(&line);
		if (!configuration_key(cub, line, i, &succes))
		{
			free(line);
			break ;
		}
		free(line);
		if (succes == 6)
			break ;
		line = get_next_line(fd);
	}
	delete_duplicate_list(cub->duplicate_list);
	cub->duplicate_list = NULL;
	return (validate_textures_and_colors(cub));
}
