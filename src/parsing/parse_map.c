/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:20:55 by ajelloul          #+#    #+#             */
/*   Updated: 2025/08/30 12:52:50 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*skip_empty_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && *line == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

void	append_row_to_map(t_map_row **map_row, char *line)
{
	t_map_row	*new_node;
	t_map_row	*tmp;

	new_node = malloc(sizeof(t_map_row));
	new_node->row = line;
	new_node->size = ft_strlen(line);
	new_node->down_row = NULL;
	new_node->up_row = NULL;
	if (*map_row == NULL)
	{
		*map_row = new_node;
		return ;
	}
	tmp = *map_row;
	while (tmp->down_row)
		tmp = tmp->down_row;
	tmp->down_row = new_node;
	new_node->up_row = tmp;
}

int	allocate_map_rows(t_cub *cub, t_map_row *first_row, 
		int max_width, int total_rows)
{
	int			current_index;
	t_map_row	*current_row;

	current_index = 0;
	current_row = first_row;
	cub->map.height = total_rows;
	cub->map.width = max_width;
	cub->map.map = malloc(sizeof(char *) * total_rows);
	if (!cub->map.map)
		return (EXIT_FAILURE);
	while (current_row)
	{
		cub->map.map[current_index] = malloc(sizeof(char) * (max_width + 1));
		if (!cub->map.map[current_index])
			return (EXIT_FAILURE);
		ft_memset(cub->map.map[current_index], ' ', max_width);
		cub->map.map[current_index][max_width] = '\0';
		ft_memcpy(cub->map.map[current_index], current_row->row, 
			current_row->size);
		current_index++;
		current_row = current_row->down_row;
	}
	return (EXIT_SUCCESS);
}

int	init_map_from_rows(t_cub *cub, t_map_row *first_row)
{
	int			max_width;
	int			total_rows;
	t_map_row	*current_row;

	max_width = 0;
	total_rows = 0;
	current_row = first_row;
	while (current_row)
	{
		if (current_row->size > max_width)
			max_width = current_row->size;
		total_rows++;
		current_row = current_row->down_row;
	}
	return (allocate_map_rows(cub, first_row, max_width, total_rows));
}

int	parse_map(t_cub *cub, int fd)
{
	char		*line;
	t_map_row	*map_rows;

	map_rows = NULL;
	line = skip_empty_lines(fd);
	while (line)
	{
		trim_newline(line);
		append_row_to_map(&map_rows, line);
		line = get_next_line(fd);
	}
	if (is_valid_map(map_rows) == 1)
	{
		delete_map_rows(map_rows);
		return (EXIT_FAILURE);
	}
	if (init_map_from_rows(cub, map_rows) == 1)
	{
		delete_map_rows(map_rows);
		return (EXIT_FAILURE);
	}
	delete_map_rows(map_rows);
	return (EXIT_SUCCESS);
}
