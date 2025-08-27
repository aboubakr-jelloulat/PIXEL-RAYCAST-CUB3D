/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krai <ael-krai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:09:43 by ajelloul          #+#    #+#             */
/*   Updated: 2025/08/27 19:14:43 by ael-krai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(t_cub));
	if (load_map_data(&cub, ac, av) == 1)
	{
		shutdown_cub(&cub);
		return (1);
	}
	// mlx_key_hook(cub->mlx, close_window_esc, cub);
	// render_game(); // 
	if (init_cub(&cub) == 1)
	{
		shutdown_cub(&cub);
		return (1);
	}
	run_cub(&cub);
	shutdown_cub(&cub);
	return (0);
}
