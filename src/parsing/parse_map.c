#include "../../includes/cub3d.h"


int	valid_file_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".cub", 4))
	{
		printf(RED "\nError: file must be a [.cub]\n\n" RESET);
		return (1);
	}
	return (0); 
}

int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(RED "\nError opening file ");
		printf("\n");
		return (-1);
	}
	return (fd);
}

void	delete_duplicate_list(t_duplicat_list *list)
{
	t_duplicat_list	*key;

	while (list)
	{
		key = list;
		list = list->next;
		free(key);
		key = NULL;
	}
}

int	parse_map(t_cub *cub, int fd)
{
	char	*line;
	int		succes;
	int		i;

	succes = 0;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = skip_spaces(&line);
		if (configuration_key(cub, line, i, &succes))
		{
			free(line);
			break;
		}
		free(line);
		if (succes == 6)
			break;
		line = get_next_line(fd);
	}
	if (!line)
	delete_duplicate_list(cub->duplicate_list);
	cub->duplicate_list = NULL;
	return (validate_textures_and_colors(cub));
}


int	load_map_data(t_cub *cub, int ac, char **av)
{
	(void) cub;
	int	fd;
	if (ac != 2)
	{
		printf(RED "\nInvalid number of arguments => Usage: ./cub3D [map.cub] file\n\n" RESET);
		return (1);
	}
	fd = open_map_file(av[1]);
	if (valid_file_extension(av[1]) || fd == -1)
		return (1);
	if (parse_map(cub, fd) == 1)
		return (1);
	

	return (0);
}
