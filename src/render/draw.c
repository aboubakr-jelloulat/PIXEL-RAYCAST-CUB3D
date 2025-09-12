/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krai <ael-krai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:02:23 by ael-krai          #+#    #+#             */
/*   Updated: 2025/09/12 15:31:15 by ael-krai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void cast_ray(t_cub *cub, float start_angle, float *ray_x, float *ray_y)
{
    float cos_angle;
    float sin_angle;

    cos_angle = cosf(start_angle);
    sin_angle = sinf(start_angle);
    *ray_x = cub->player.x;
    *ray_y = cub->player.y;
    while (!touch(cub, *ray_x, *ray_y))
    {
        *ray_x += cos_angle;
        *ray_y += sin_angle;
    }
}

void draw_slice(t_cub *cub, int screen_x, float ray_x, float ray_y)
{
    float   height;
    float   dist;
    int     start_y;
    int     end_y;
    int     y;

    dist = fixed_dist(cub, cub->player.x, cub->player.y, ray_x, ray_y);
    height = (BLOCK / dist) * (WIDTH);
    start_y = (int)((HEIGHT - height) / 2);
    end_y = (int)(start_y + height);
    if (start_y < 0)
        start_y = 0;
    if (end_y >= HEIGHT)
        end_y = HEIGHT - 1;
    y = start_y;
    while (y < end_y)
    {
        mlx_put_pixel(cub->image, screen_x, y, 0xFFFFFF);
        y++;
    }
}

void draw_line(t_cub *cub, float start_angle, int screen_x)
{
    float ray_x;
    float ray_y;

    cast_ray(cub, start_angle, &ray_x, &ray_y);
    draw_slice(cub, screen_x, ray_x, ray_y);
}

void    draw_loop(void *param)
{
    t_cub       *cub;
    float		fraction;
    float		start_x;
    int			i;

	cub = (t_cub *)param;
    move_player(cub);
    clear_image(cub);
	fraction = PI / 3 / WIDTH;
	start_x = cub->player.angle - PI / 6;
	i = 0;
    while(i < WIDTH)
    {
        draw_line(cub, start_x, i);
        start_x += fraction;
        i++;
    }
	mlx_image_to_window(cub->mlx, cub->image, 0, 0);
}
