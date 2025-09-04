/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 22:46:27 by ajelloul          #+#    #+#             */
/*   Updated: 2025/09/04 17:53:27 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	deg_to_rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

void	set_player(t_cub *cub, int x, int y, int angle)
{
	cub->player.x = x * TILE_SIZE + TILE_SIZE / 2;
	cub->player.y = y * TILE_SIZE + TILE_SIZE / 2;
	cub->player.angle = deg_to_rad(angle);
}
