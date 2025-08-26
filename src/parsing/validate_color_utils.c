/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_color_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:57:14 by ajelloul          #+#    #+#             */
/*   Updated: 2025/08/26 17:32:26 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	validate_all_textures(t_cub *cub)
{
	if (cub->list_status.invalid_key)
	{
		display_errors("\nTexture Configuration Error: Invalid key detected\n");
		return (false);
	}
	
	if (cub->no_texture_path && cub->so_texture_path && 
		cub->we_texture_path && cub->ea_texture_path)
		return (true);
	
	display_errors("\nTexture Loading Error: Missing required texture paths\n");
	return (false);
}


bool	validate_floor_color(t_cub *cub)
{
	if (cub->list_status.floor_color < 0)
	{
		display_errors("\nColor Configuration Error: Floor color is missing or invalid\n");
		return (false);
	}
	return (true);
}


bool	validate_ceiling_color(t_cub *cub)
{
	if (cub->list_status.ceiling_color < 0)
	{
		display_errors("\nColor Configuration Error: Ceiling color is missing or invalid\n");
		return (false);
	}
	return (true);
}

bool	validate_no_duplicates(t_cub *cub)
{
	if (cub->list_status.is_duplicate_key)
	{
		display_errors("\nConfiguration Validation Error: Duplicate components detected\n");
		return (false);
	}
	return (true);
}

bool	validate_texture_extensions(t_cub *cub)
{
	if (cub->list_status.is_wrong_txtr_extension)
	{
		display_errors("Invalid texture extension - ensure paths end with .png");
		return (false);
	}
	return (true);
}

