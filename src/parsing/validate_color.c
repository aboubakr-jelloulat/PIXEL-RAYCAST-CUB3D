#include "../../includes/cub3d.h"


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
