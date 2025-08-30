/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_colletion_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 11:47:35 by ajelloul          #+#    #+#             */
/*   Updated: 2025/08/30 11:49:21 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	delete_map_rows(t_map_row *map_row)
{
	t_map_row	*tmp;

	while (map_row)
	{
		tmp = map_row;
		map_row = map_row->down_row;
		free(tmp->row);
		free(tmp);
		tmp = NULL;
	}
}
