/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:06:57 by ajelloul          #+#    #+#             */
/*   Updated: 2025/08/30 11:07:11 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int is_tile_enclosed(t_map_row *row, int i, t_map_row *up, t_map_row *down)
{
	return (
		(!is_wall_or_space(row->row[i]) && row->row[i + 1] == '\0')
		|| (!is_wall_or_space(row->row[i]) && is_whitespace(row->row[i + 1]))
		|| (is_whitespace(row->row[i]) && !is_wall_or_space(row->row[i + 1]))
		|| (!is_wall_or_space(row->row[i]) && !up_valid(up, i))
		|| (!is_wall_or_space(row->row[i]) && !down_valid(down, i))
	);
}

static int	validate_map_position(t_map_row *row, int pos)
{
	t_map_row	*up;
	t_map_row	*down;

	up = row->up_row;
	down = row->down_row;
	
	if (!row || !row->row)
		return (display_errors("Invalid row data"), 1);
	if (!is_valid_map_char(row->row[pos]))
	{
		display_errors("Unknown character detected");
		return (1);
	}
	if (row->row[pos] == '1')
		return (EXIT_SUCCESS);
	if (is_tile_enclosed(row, pos, up, down))
	{
		display_errors("Error : Invalid Map Found ");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}



int is_valid_map(t_map_row *map_row)
{
	t_map_row	*cur_row;
	int			i;

	cur_row = map_row;
	while (cur_row)
	{
		i = 0;
		i = skip_spaces(&cur_row->row);
		if (cur_row->row[i] != '1')
		{
			display_errors("Error : Invalid Map Found ");
			return (1);
		}
		while (cur_row->row[i])
		{
			if (validate_map_position(cur_row, i))
			i++;
		}
		cur_row = cur_row->down_row;
	}
	return  
}
