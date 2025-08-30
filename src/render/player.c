/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krai <ael-krai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:59:25 by ael-krai          #+#    #+#             */
/*   Updated: 2025/08/29 20:53:47 by ael-krai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    clear_player(t_cub *cub)
{
	draw_square(cub, cub->player.x * 64 + 16,
        cub->player.y * 64 + 16, 32, 32, 0x00000000);
}

void	draw_player(t_cub *cub)
{
	draw_square(cub, cub->player.x * 64 + 16,
        cub->player.y * 64 + 16, 32, 32, 0xFFFFFFFF);
}

void    key_handler(mlx_key_data_t key, void *param)
{
    t_cub *cub;
    char    **map;
    int     x;
    int     y;

    cub = (t_cub *)param;
    map = cub->map.map;
    x = cub->player.x;
    y = cub->player.y;
	if (y > 0 && map[y - 1][x] != '1' && key.key == MLX_KEY_W && key.action == MLX_PRESS)
    {
        clear_player(cub);
        cub->player.y -= 1;
        draw_player(cub);
    }
	else if (map[y + 1][x] != '1' && key.key == MLX_KEY_S && key.action == MLX_PRESS)
    {
        clear_player(cub);
        cub->player.y += 1;
        draw_player(cub);
    }
    else if ( x > 0 && map[y][x - 1] != '1' && key.key == MLX_KEY_A && key.action == MLX_PRESS)
    {
        clear_player(cub);
        cub->player.x -= 1;
        draw_player(cub);
    }
	else if (map[y][x + 1] != '1' && key.key == MLX_KEY_D && key.action == MLX_PRESS)
    {
        clear_player(cub);
        cub->player.x += 1;
        draw_player(cub);
    }
	else if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(cub->mlx);
}
