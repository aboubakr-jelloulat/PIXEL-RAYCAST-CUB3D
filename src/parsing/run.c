/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:21:30 by ajelloul          #+#    #+#             */
/*   Updated: 2025/08/28 11:40:58 by ael-krai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	debug(t_cub *cub)
{
	int	i;

	printf("Map height: %d\n", cub->map.height);
	printf("Map width: %d\n", cub->map.width);
	i = -1;
	while (++i < cub->map.height)
		printf("[%s]\n", cub->map.map[i]);
	printf("NO: %s\n", cub->no_texture_path);
	printf("SO: %s\n", cub->so_texture_path);
	printf("WE: %s\n", cub->we_texture_path);
	printf("EA: %s\n", cub->ea_texture_path);
	printf("F: %d, in rgb r: %d, g: %d, b: %d\n", cub->list_status.floor_color,
		(cub->list_status.floor_color >> 16) & 0xFF,
		(cub->list_status.floor_color >> 8) & 0xFF,
		cub->list_status.floor_color & 0xFF);
	printf("C: %d, in rgb r: %d, g: %d, b: %d\n", cub->list_status.ceiling_color,
		(cub->list_status.ceiling_color >> 16) & 0xFF,
		(cub->list_status.ceiling_color >> 8) & 0xFF,
		cub->list_status.ceiling_color & 0xFF);
	printf("Player position: x=%d, y=%d, angle=%.2f\n", 
		cub->player.x, cub->player.y, cub->player.radius);
}

int	shutdown_cub(t_cub *cub)
{
	if (cub->mlx)
		mlx_close_window(cub->mlx);
	if (cub->image)
		mlx_delete_image(cub->mlx, cub->image);
	gc_collect(cub);
	ft_bzero(cub, sizeof(t_cub));
	return (0);
}

// void	run_cub(t_cub *cub)
// {
// 	mlx_loop(cub->mlx);
// }

int	load_map_data(t_cub *cub, int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		display_errors("Invalid arguments Usage: ./cub3D maps/[map.cub]\n");
		return (1);
	}
	if (valid_file_extension(av[1]) == 1)
		return (1);
	fd = open_map_file(av[1]);
	if (fd == -1)
		return (1);
	if (parse_game_settings(cub, fd) == 1)
		return (1);
	if (parse_map(cub, fd) == 1)
		return (1);
	close(fd);
	if (validate_and_set_player(cub) == 1)
		return (1);
	return (0);
}
