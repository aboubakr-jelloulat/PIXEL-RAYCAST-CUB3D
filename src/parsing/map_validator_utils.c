/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:09:42 by ajelloul          #+#    #+#             */
/*   Updated: 2025/09/03 21:51:09 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

int	is_wall_or_space(char c)
{
	return (c == '1' || is_whitespace(c));
}

int	is_valid_map_char(char c)
{
	return (c == '1' || c == '0'
		|| c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| is_whitespace(c));
}

int	up_valid(t_map_row *up, int pos)
{
	if (up == NULL)
		return (0);
	if (up->size <= pos)
		return (0);
	if (up->row[pos] == ' ')
		return (0);
	return (1);
}

int	down_valid(t_map_row *down, int pos)
{
	if (down == NULL)
		return (0);
	if (down->size <= pos)
		return (0);
	if (down->row[pos] == ' ')
		return (0);
	return (1);
}
