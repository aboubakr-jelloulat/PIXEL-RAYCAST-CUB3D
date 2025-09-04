/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:06:57 by ajelloul          #+#    #+#             */
/*   Updated: 2025/09/03 22:25:15 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*

	 Cases:
	
	 1) (!is_wall_or_space(row->row[i]) && row->row[i + 1] == '\0')
	    Current is an open tile, and the next is end of string.
	    Example: "11110"
	                    ^ last '0' touches the void.
	
	 2) (!is_wall_or_space(row->row[i]) && is_whitespace(row->row[i + 1]))
	    Current is an open tile, and the right side is a space.
	    Example: "1100 1"
	                      ^ this '0' touches a space.
	
	 3) (is_whitespace(row->row[i]) && !is_wall_or_space(row->row[i + 1]))
	    Current is a space, and the right side is an open tile.
	    Example: "11 011"
	                       ^ this '0' touches a space on the left.
	
	 4) (!is_wall_or_space(row->row[i]) && !up_valid(up, i))
	    Current is an open tile, and the row above has a space/void.
	    Example:
	       Up:  "111 11"
	       Row: "110011"
	                 ^ this '0' touches a void above.
	
	 5) (!is_wall_or_space(row->row[i]) && !down_valid(down, i))
	    Current is an open tile, and the row below has a space/void.
	    Example:
	       Row:  "110011"
	       Down: "111 11"
	                 ^ this '0' touches a void below.
*/

int	is_tile_enclosed(t_map_row *row, int i, t_map_row *up, t_map_row *down)
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
		display_errors("validate_map_position : Invalid Map Found ");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

bool	is_player_spawn_safe(t_map_row *crow, int i)
{
	return (up_valid(crow->up_row, i) && down_valid(crow->down_row, i)
		&& !is_whitespace(crow->row[i + 1])
		&& (i > 0 && !is_whitespace(crow->row[i - 1])));
}

int	player_validator(t_map_row *map_row)
{
	t_map_row	*cur_row;
	int			i;
	int			plyr_count;

	cur_row = map_row;
	plyr_count = 0;
	while (cur_row)
	{
		i = 0;
		while (cur_row->row[i])
		{
			if (cur_row->row[i] == 'N' || cur_row->row[i] == 'E'
				|| cur_row->row[i] == 'S' || cur_row->row[i] == 'W')
			{
				plyr_count++;
				if (plyr_count > 1 || !is_player_spawn_safe(cur_row, i))
					return (display_errors("Player point is invalid"), 1);
			}
			i++;
		}
		cur_row = cur_row->down_row;
	}
	if (!plyr_count)
		return (display_errors("No player spawn point defined in map"), 1);
	return (EXIT_SUCCESS);
}

int	is_valid_map(t_map_row *map_row)
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
			display_errors("Invalid Map Found ");
			return (1);
		}
		while (cur_row->row[i])
		{
			if (validate_map_position(cur_row, i) == 1)
				return (EXIT_FAILURE);
			i++;
		}
		cur_row = cur_row->down_row;
	}
	return (player_validator(map_row));
}
