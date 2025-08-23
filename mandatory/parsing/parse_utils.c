#include "../../includes/cub3d.h"

int	skip_spaces(char **line)
{
	int	i;

	i = 0;
	while ((*line)[i] == ' ' || (*line)[i] == '\t')
	{
		i++;
	}
	return (i);
}

int	parse_texture_line(t_cub *cub, char *line, char **path, char *name)
{
	int	len;

	len = ft_strlen(name); // ndiroha 3 mn ba3ed
	

}

void	parse_all_wall_textures(t_cub *cub, char *line, int i, int *succes)
{
	*succes += parse_texture_line(cub, line + i, &cub->no_texture_path, "NO");
	*succes += parse_texture_line(cub, line + i, &cub->so_texture_path, "SO");
	*succes += parse_texture_line(cub, line + i, &cub->we_texture_path, "WE");
	*succes += parse_texture_line(cub, line + i, &cub->ea_texture_path, "EA");
}

int	is_configuration_keyword(t_cub *cub, char *line, int i, int *succes)
{
    if (ft_strncmp("NO ", line + i, 3) == 0
        || ft_strncmp("SO ", line + i, 3) == 0
        || ft_strncmp("WE ", line + i, 3) == 0
        || ft_strncmp("EA ", line + i, 3) == 0
        || ft_strncmp("F ", line + i, 2) == 0
        || ft_strncmp("C ", line + i, 2) == 0)
    {
		parse_all_wall_textures(cub, line, i, succes);
        
    }
    
}