/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krai <ael-krai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:09:43 by ajelloul          #+#    #+#             */
/*   Updated: 2025/09/12 11:55:55 by ael-krai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_game(t_cub *cub)
{
	cub->player.x = WIDTH / 2;
    cub->player.y = HEIGHT / 2;
    cub->player.angle = PI / 2;
    cub->player.key_up = false;
    cub->player.key_down = false;
    cub->player.key_right = false;
    cub->player.key_left = false;
    cub->player.left_rotate = false;
    cub->player.right_rotate = false;
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	cub->image = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
}

int	main(int ac, char **av)
{
	t_cub		cub;

	ft_bzero(&cub, sizeof(t_cub));
	if (load_map_data(&cub, ac, av) == 1 || init_cub(&cub) == 1)
		return (shutdown_cub(&cub), 1);
	init_game(&cub);
	mlx_key_hook(cub.mlx, key_handler, &cub);
	mlx_loop_hook(cub.mlx, draw_loop, &cub);
	mlx_image_to_window(cub.mlx, cub.image, 0, 0);
	mlx_loop(cub.mlx);
	return (shutdown_cub(&cub), 0);
}
