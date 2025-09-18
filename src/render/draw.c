/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krai <ael-krai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:02:23 by ael-krai          #+#    #+#             */
/*   Updated: 2025/09/18 16:55:39 by ael-krai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void draw_slice(t_cub *cub, int screen_x, float perp_dist, float dist_proj_plane)
{
    float wall_height;
    int start_y;
    int end_y;
    int y;

    wall_height = ((float)BLOCK / perp_dist) * dist_proj_plane;
    start_y = (int)((HEIGHT - wall_height) / 2.0f);
    end_y = (int)((HEIGHT + wall_height) / 2.0f);
    if (start_y < 0)
        start_y = 0;
    if (end_y >= HEIGHT)
        end_y = HEIGHT - 1;
        
    // int     wall_color;
    // if (cub->dda->side == 0)
    //     wall_color = 0xFF0000;
    // else
    //     wall_color = 0x0000FF;
    y = start_y;
    while (y < end_y)
    {
        mlx_put_pixel(cub->image, screen_x, y, 0x87CEEB);
        y++;
    }
}

void draw_floor_ceiling(t_cub *cub)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT / 2)
    {
        x = 0;
        while (x < WIDTH)
        {
            mlx_put_pixel(cub->image, x, y, cub->list_status.ceiling_color);
            x++;
        }
        y++;
    }
    y = HEIGHT / 2;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            mlx_put_pixel(cub->image, x, y, cub->list_status.floor_color);
            x++;
        }
        y++;
    }
}

void draw_loop(void *param)
{
    t_cub  *cub;
    float  ray_angle;
    float  angle_step;
    int    i;
    float  hit_x; 
    float  hit_y;
    float  perp_dist;

    cub = (t_cub *)param;
    move_player(cub);
    // clear_image(cub);
    draw_floor_ceiling(cub);
    cub->player.dist_proj_plane = (WIDTH / 2.0f) / tanf(FOV / 2.0f);
    angle_step = FOV / (float)WIDTH;
    ray_angle = cub->player.angle - FOV / 2.0f;
    i = 0;
    while (i < WIDTH)
    {
        cast_ray(cub, ray_angle, &hit_x, &hit_y, &perp_dist);
        perp_dist = perp_dist * cosf(ray_angle - cub->player.angle);
        draw_slice(cub, i, perp_dist, cub->player.dist_proj_plane);
        ray_angle += angle_step;
        i++;
    }
}
