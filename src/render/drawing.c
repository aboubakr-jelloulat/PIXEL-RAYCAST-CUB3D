/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krai <ael-krai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:03:49 by ael-krai          #+#    #+#             */
/*   Updated: 2025/09/01 19:17:52 by ael-krai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void draw_square(t_cub *cub, int x, int y, int w, int h, int color)
{
    int i;
    int j;

	i = 0;
	while (i++ < w)
	{
		j = 0;
		while (j++ < h)
		{
			if ((x + i) >= 0 && (x + i) < WIDTH && (y + j) >= 0 && (y + j) < HEIGHT)
                mlx_put_pixel(cub->image, x + i, y + j, color);
		}
	}
}

void    draw_celling_and_ground(t_cub *cub)
{
	draw_square(cub, 0, 0, WIDTH, HEIGHT / 2, 0x00FFFFFF);
	draw_square(cub, 0, HEIGHT / 2, WIDTH, HEIGHT / 2, 0xFF00FFFF);
}

void	draw_map(t_cub *cub)
{
	char	**map;
	int	i;
	int	j;

	i = 0;
	map = cub->map.map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				draw_square(cub, j * tile_w, i * tile_h, tile_w, tile_h, 0x0000FFFF);
			if (map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S' || map[i][j] == 'N')
			{
				cub->player.x = j * tile_w + 48;
				cub->player.y = i * tile_h + 48;
			}
			j++;
		}
		i++;
	}
}
