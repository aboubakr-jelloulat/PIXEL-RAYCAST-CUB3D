/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krai <ael-krai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:03:49 by ael-krai          #+#    #+#             */
/*   Updated: 2025/08/29 20:51:34 by ael-krai         ###   ########.fr       */
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
	int	i;
	int	j;

	i = 0;
	while (cub->map.map[i])
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == '1')
				draw_square(cub, j * 64, i * 64, 64, 64, 0x0000FFFF);
			if (cub->map.map[i][j] == 'E' || cub->map.map[i][j] == 'W'
				|| cub->map.map[i][j] == 'S' || cub->map.map[i][j] == 'N')
				{
					cub->player.x = j;
					cub->player.y = i;
					draw_player(cub);
				}
			j++;
		}
		i++;
	}
}
