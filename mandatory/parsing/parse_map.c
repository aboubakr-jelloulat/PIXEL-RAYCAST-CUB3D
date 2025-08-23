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

int	parse_map(t_cub *cub, int fd)
{
	char	*line;
	int		succes;
	int		i;
	(void) cub; //unsed

	succes = 0;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = skip_spaces(&line);


	}
	return 0; // unsed
}


int	parsing(t_cub *cub, int argc, char **argv)
{
	(void) cub;
	int	fd;
	if (argc != 2)
	{
		printf(RED "\nInvalid number of arguments => Usage: ./cub3D [map.cub] file\n\n" RESET);
		return (1);
	}
	fd = open_map_file(argv[1]);
	if (valid_file_extension(argv[1]) || fd == -1)
		return (1);
	

	return (0);
}
