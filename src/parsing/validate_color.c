/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:04:12 by ajelloul          #+#    #+#             */
/*   Updated: 2025/08/30 12:29:46 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_rbg_values(char **value)
{
	int	i;

	i = 0;
	while (value[i])
	{
		free(value[i]);
		i++;
	}
	free(value);
}

static int	validate_all_textures(t_cub *cub)
{
	if (cub->list_status.invalid_key)
	{
		display_errors("\exture Configuration Error: Invalid key detected\n");
		return (0);
	}
	if (cub->no_texture_path && cub->so_texture_path
		&& cub->we_texture_path && cub->ea_texture_path)
		return (1);
	display_errors("Texture Loading Error: Missing required texture paths\n");
	return (0);
}

int	validate_textures_and_colors(t_cub *cub)
{
	if (cub->list_status.is_duplicate_key)
	{
		display_errors("Configuration Error: Duplicate components detected\n");
		return (1);
	}
	if (cub->list_status.is_wrong_txtr_extension)
	{
		display_errors("Color Error: Floor color is missing or invalid\n");
		return (1);
	}
	if (!validate_all_textures(cub))
		return (1);
	if (!cub->list_status.floor_color)
	{
		display_errors("Missing or invalid floor color");
		return (1);
	}
	if (!cub->list_status.ceiling_color)
	{
		display_errors("Color Error: Ceiling color is missing or invalid\n");
		return (1);
	}
	return (0);
}
