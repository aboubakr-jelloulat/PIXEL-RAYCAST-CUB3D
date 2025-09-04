/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:09:45 by ajelloul          #+#    #+#             */
/*   Updated: 2025/09/04 19:41:21 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
int	init_window(t_cub *cub)
{
	cub->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!(cub->mlx))
	{
		display_errors(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	cub->image = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!(cub->image))
	{
		mlx_close_window(cub->mlx);
		display_errors(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(cub->mlx, cub->image, 0, 0) == -1)
	{
		mlx_close_window(cub->mlx);
		display_errors(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	mlx_key_hook(cub->mlx, close_window_esc, cub);
	return (0);
}

*/

int	load_textures(t_cub *cub)
{
	cub->textures.mlx_north = mlx_load_png(cub->no_texture_path);
	cub->textures.mlx_south = mlx_load_png(cub->so_texture_path);
	cub->textures.mlx_west = mlx_load_png(cub->we_texture_path);
	cub->textures.mlx_east = mlx_load_png(cub->ea_texture_path);
	return (0);
}

int	check_textures(t_cub *cub)
{
	if (!cub->textures.mlx_north || !cub->textures.mlx_south
		|| !cub->textures.mlx_west || !cub->textures.mlx_east)
	{
		display_errors("\nfailed to load textures\n");
		return (EXIT_FAILURE);
	}
	return (0);
}

int	init_cub(t_cub *cub)
{
	// if (init_window(cub) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	if (load_textures(cub) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_textures(cub) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (0);
}
