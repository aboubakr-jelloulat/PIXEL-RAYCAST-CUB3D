/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krai <ael-krai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:02:23 by ael-krai          #+#    #+#             */
/*   Updated: 2025/09/13 16:19:09 by ael-krai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void draw_slice(t_cub *cub, int screen_x, float perp_dist)
{
	float	wall_height;
	float	dist_proj_plane;
	int		start_y;
	int		end_y;

	if (perp_dist <= 0.0f)
		perp_dist = 0.0001f;
	dist_proj_plane = (WIDTH / 2.0f) / tanf((PI / 3.0f) / 2.0f);
	wall_height = ((float)BLOCK / perp_dist) * dist_proj_plane;
	start_y = (int)((HEIGHT - wall_height) / 2.0f);
	end_y = (int)((HEIGHT + wall_height) / 2.0f);
	if (start_y < 0)
		start_y = 0;
	if (end_y >= HEIGHT)
		end_y = HEIGHT - 1;
	while (start_y < end_y)
	{
		mlx_put_pixel(cub->image, screen_x, start_y, 0xFFFFFF);
		start_y++;
	}
}


void    draw_line(t_cub *cub, float start_angle, int screen_x)
{
    float   hit_x;
    float   hit_y;
    float   perp_dist;
    float   angle_diff;

    cast_ray(cub, start_angle, &hit_x, &hit_y, &perp_dist);
    angle_diff = start_angle - cub->player.angle;
    perp_dist = perp_dist * cosf(angle_diff);
    draw_slice(cub, screen_x, perp_dist);
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

void    draw_loop(void *param)
{
    t_cub   *cub;
    float   fraction;
    float   start_x;
    int     i;

    cub = (t_cub *)param;
    move_player(cub);
    clear_image(cub);
    draw_floor_ceiling(cub);
    fraction = (PI / 3.0f) / (float)WIDTH;
    start_x = cub->player.angle - (PI / 3.0f) / 2.0f;
    i = 0;
    while (i < WIDTH)
    {
        draw_line(cub, start_x, i);
        start_x += fraction;
        i++;
    }
    mlx_image_to_window(cub->mlx, cub->image, 0, 0);
}
