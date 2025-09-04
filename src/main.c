/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:09:43 by ajelloul          #+#    #+#             */
/*   Updated: 2025/09/01 20:52:04 by ael-krai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char **get_map(t_cub *cub)
{
	cub->map.height = 10;
	cub->map.width = 16;
    char **map = malloc(sizeof(char *) * 11);
    map[0] = "1111111111111111";
    map[1] = "1000000000000001";
    map[2] = "1000000000000001";
    map[3] = "100E001000000001";
    map[4] = "1000000000000001";
    map[5] = "1000000100000001";
    map[6] = "1000010000111001";
    map[7] = "1000000010000001";
    map[8] = "1000000010000001";
    map[9] = "1111111111111111";
    return (map[10] = NULL, map);
}

int	init_game(t_cub *cub)
{
	cub->player.move_speed = 3.0;
	cub->player.rotation_speed = 3 * (PI / 180);
	cub->player.turn_direction = 0;
	cub->player.walk_direction = 0;
	cub->map.map = get_map(cub);
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	cub->image = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub		cub;

	ft_bzero(&cub, sizeof(t_cub));

	if (load_map_data(&cub, ac, av) == 1 || init_cub(&cub) == 1)
		return (shutdown_cub(&cub), 1);
	init_game(&cub);
	draw_map(&cub);
	mlx_image_to_window(cub.mlx, cub.image, 0, 0);
	mlx_key_hook(cub.mlx, key_handler, &cub);
	mlx_loop_hook(cub.mlx, render_player, &cub);
	mlx_loop(cub.mlx);
	shutdown_cub(&cub);
	return (0);
}
