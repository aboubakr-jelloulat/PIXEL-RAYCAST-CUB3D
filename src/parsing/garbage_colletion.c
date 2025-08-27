/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_colletion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:43:05 by ajelloul          #+#    #+#             */
/*   Updated: 2025/08/27 16:00:24 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	delete_textures_paths(t_cub *cub)
{
	free(cub->no_texture_path);
	free(cub->ea_texture_path);
	free(cub->so_texture_path);
	free(cub->we_texture_path);
	cub->no_texture_path = NULL;
	cub->ea_texture_path = NULL;
	cub->so_texture_path = NULL;
	cub->we_texture_path = NULL;
}

static void	destroy_one_textr(mlx_texture_t **texture)
{
	if (*texture)
	{
		mlx_delete_texture((*texture));
		*texture = NULL;
	}
}

static void	delete_mlx_images(t_cub *cub)
{
	destroy_one_textr(&cub->textures.mlx_east);
	destroy_one_textr(&cub->textures.mlx_north);
	destroy_one_textr(&cub->textures.mlx_south);
	destroy_one_textr(&cub->textures.mlx_west);
}

static void	delete_map(t_cub *cub)
{
	int	i;

	if (!cub || !cub->map.addr)
		return ;
	i = 0;
	while (i < cub->map.height)
	{
		free(cub->map.addr[i]);
		cub->map.addr[i] = NULL;
		i++;
	}
	free(cub->map.addr);
	cub->map.addr = NULL;
}

void	gc_collect(t_cub *cub)
{
	delete_textures_paths(cub);
	delete_mlx_images(cub);
	delete_map(cub);
}
