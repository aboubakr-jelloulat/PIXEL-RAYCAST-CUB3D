/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krai <ael-krai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:20:30 by ael-krai          #+#    #+#             */
/*   Updated: 2025/09/12 15:33:32 by ael-krai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	update_direction(t_player *player, float dx, float dy)
{
	player->x += dx;
	player->y += dy;
}

void	rotate_player(t_player *player)
{
    float angle_speed;

    angle_speed = 0.03;
    if (player->left_rotate)
        player->angle -= angle_speed;
    if (player->right_rotate)
        player->angle += angle_speed;
    if (player->angle > 2 * PI)
        player->angle = 0;
    if (player->angle < 0)
        player->angle = 2 * PI;
}

void	redirect_player(t_player *player)
{
	float	cos_angle;
	float	sin_angle;
	int		speed;

	speed = 3;
	cos_angle = cosf(player->angle);
	sin_angle = sinf(player->angle);
	if (player->key_up == true)
		update_direction(player, cos_angle * speed, sin_angle * speed);
	else if (player->key_down == true)
		update_direction(player, -cos_angle * speed, -sin_angle * speed);
	else if (player->key_left == true)
		update_direction(player, sin_angle * speed, -cos_angle * speed);
	else if (player->key_right == true)
		update_direction(player, -sin_angle * speed, cos_angle * speed);
}


void move_player(void *param)
{
    t_cub *cub = (t_cub *)param;

    rotate_player(&cub->player);
    redirect_player(&cub->player);
}
