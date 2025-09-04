/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krai <ael-krai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:55:08 by ael-krai          #+#    #+#             */
/*   Updated: 2025/09/01 20:50:41 by ael-krai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    key_press(t_cub *cub, mlx_key_data_t key)
{
	if (key.key == MLX_KEY_W)
		cub->player.walk_direction = 1;
	else if (key.key == MLX_KEY_A)
		cub->player.walk_direction = -2;
	else if (key.key == MLX_KEY_S)
		cub->player.walk_direction = -1;
	else if (key.key == MLX_KEY_D)
		cub->player.walk_direction = 2;
	else if (key.key == MLX_KEY_LEFT)
		cub->player.turn_direction = -1;
	else if (key.key == MLX_KEY_RIGHT)
		cub->player.turn_direction = 1;
}

void    key_release(t_cub *cub, mlx_key_data_t key)
{
	if (key.key == MLX_KEY_W)
		cub->player.walk_direction = 0;
	else if (key.key == MLX_KEY_A)
		cub->player.walk_direction = 0;
	else if (key.key == MLX_KEY_S)
		cub->player.walk_direction = 0;
	else if (key.key == MLX_KEY_D)
		cub->player.walk_direction = 0;
	else if (key.key == MLX_KEY_LEFT)
		cub->player.turn_direction = 0;
	else if (key.key == MLX_KEY_RIGHT)
		cub->player.turn_direction = 0;
}

void    key_handler(mlx_key_data_t key, void *param)
{
    t_cub	*cub;

	cub = (t_cub *)param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(cub->mlx);
    else if (key.action == MLX_PRESS)
		key_press(cub, key);
    else if (key.action == MLX_RELEASE)
    	key_release(cub, key);
}

void	render_player(void *param)
{
	int		x;
	int		y;
	int		old_x = 0;
	int		old_y = 0;
	t_cub	*cub;

	cub = (t_cub *)param;
	// old_x = cub->player.x;
	// old_y = cub->player.y;
	x = (int)cub->player.x / tile_w;
	y = (int)cub->player.y / tile_h;
	draw_square(cub, cub->player.x, cub->player.y, 2, 2, 0x00000000);
	if (cub->player.walk_direction == 1 && cub->map.map[y][x] != '1')
	{
		old_y = cub->player.y;
		cub->player.y -= 3;
	}
	else if (cub->player.walk_direction == -1 && cub->map.map[y][x] != '1')
	{
		old_y = cub->player.y;
		cub->player.y += 3;
	}
	else if (cub->player.walk_direction == 2 && cub->map.map[y][x] != '1')
	{
		old_x = cub->player.x;
		cub->player.x += 3;		
	}
	else if (cub->player.walk_direction == -2 && cub->map.map[y][x] != '1')
	{
		old_x = cub->player.x;
		cub->player.x -= 3;
	}
	// cub->player.x =  old_x;
	// cub->player.y =  old_y;
	draw_square(cub, cub->player.x, cub->player.y, 2, 2, 0xFFFFFF);
}
