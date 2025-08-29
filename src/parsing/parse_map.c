/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:20:55 by ajelloul          #+#    #+#             */
/*   Updated: 2025/08/29 17:10:34 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_map_row		*tmp;

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
	tmp = tmp->down_row = new_node;
	new_node->up_row = tmp;
}

int	parse_map(t_cub *cub, int fd)
{
	char	*line;
	t_map_row	*map_rows;

	map_rows = NULL;
	line = skip_empty_lines(fd);
	while (line)
	{
		trim_newline(line);
		append_row_to_map(&map_rows, line);
		line = get_next_line(fd);
	}
	if (is_valid_map() == 1)
	{
		
	}
	(void)cub;
	return 0;
}
