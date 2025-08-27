/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:21:30 by ajelloul          #+#    #+#             */
/*   Updated: 2025/08/27 16:14:21 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	run_cub(t_cub *cub)
{
	mlx_loop(cub->mlx);
}

int	load_map_data(t_cub *cub, int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		printf(RED "\nInvalid arguments => Usage: ./cub3D/maps[map.cub]\n" RESET);
		return (1);
	}
	fd = open_map_file(av[1]);
	if (valid_file_extension(av[1]) || fd == -1)
		return (1);
	if (parse_game_settings(cub, fd) == 1)
		return (1);
	return (0);
}

int	load_game_engine(int ac, char **av)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(t_cub));
	if (load_map_data(&cub, ac, av) == 1)
	{
		shutdown_cub(&cub);
		return (1);
	}
	if (init_cub(&cub) == 1)
	{
		shutdown_cub(&cub);
		return (1);
	}
	run_cub(&cub);
	shutdown_cub(&cub);
	return (0);
}
