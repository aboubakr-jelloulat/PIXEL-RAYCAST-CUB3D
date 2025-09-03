/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_set_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 22:28:04 by ajelloul          #+#    #+#             */
/*   Updated: 2025/09/03 22:53:33 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_player_angle(char c)
{
	if (c == 'N')
		return (270);
	if (c == 'S')
		return (90);
	if (c == 'E')
		return (0);
	if (c == 'W')
		return (180);
	return (-1);
}

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	process_player_position(t_cub *cub, int x, int y)
{
	char	current_char;
	int		angle;

	current_char = cub->map.map[y][x];
	if (is_player_char(current_char))
	{
		angle = get_player_angle(current_char);
		set_player(cub, x, y, angle);
		return (1);
	}
	return (0);
}

int	find_player_start(t_cub *cub)
{
	int	x;
	int	y;

	if (!cub || !cub->map.map)
		return (EXIT_FAILURE);
	y = 0;
	while (y < cub->map.height)
	{
		x = 0;
		while (x < cub->map.width)
		{
			if (process_player_position(cub, x, y))
				return (EXIT_SUCCESS);
			x++;
		}
		y++;
	}
	return (EXIT_FAILURE);
	
}

int validate_and_set_player(t_cub *cub)
{
	if (find_player_start(cub) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
