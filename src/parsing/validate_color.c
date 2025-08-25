#include "../../includes/cub3d.h"

void	display_errors(char *error_msg)
{
	printf("\033[31mError: %s\033[0m\n", error_msg);
}

static bool	validate_all_textures(t_cub *cub)
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


static bool	validate_floor_color(t_cub *cub)
{
	if (cub->list_status.floor_color < 0)
	{
		display_errors("\nColor Configuration Error: Floor color is missing or invalid\n");
		return (false);
	}
	return (true);
}


static bool	validate_ceiling_color(t_cub *cub)
{
	if (cub->list_status.ceiling_color < 0)
	{
		display_errors("\nColor Configuration Error: Ceiling color is missing or invalid\n");
		return (false);
	}
	return (true);
}

static bool	validate_no_duplicates(t_cub *cub)
{
	if (cub->list_status.is_duplicate_key)
	{
		display_errors("\nConfiguration Validation Error: Duplicate components detected\n");
		return (false);
	}
	return (true);
}

static bool	validate_texture_extensions(t_cub *cub)
{
	if (cub->list_status.is_wrong_txtr_extension)
	{
		print_error_red("Invalid texture extension - ensure paths end with .png");
		return (false);
	}
	return (true);
}


int	validate_textures_and_colors(t_cub *cub)
{
	if (!validate_no_duplicates(cub))
		return (1);
	if (!validate_texture_extensions(cub))
		return (1);
	if (!validate_all_textures(cub))
		return (1);
	if (!validate_floor_color(cub))
		return (1);
	if (!validate_ceiling_color(cub))
		return (1);
	
	return (0);
}
