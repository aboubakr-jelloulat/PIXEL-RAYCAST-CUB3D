#include "../includes/cub3d.h"




int	main(int ac, char **av)
{
	t_cub	cub;

	if (parsing(&cub, ac, av))
	{
		return 1;
	}
	return 0;
}
