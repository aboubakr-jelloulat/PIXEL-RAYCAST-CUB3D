/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:26:57 by ajelloul          #+#    #+#             */
/*   Updated: 2025/09/01 17:53:32 by ael-krai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "/Users/ajelloul/MLX42/include/MLX42/MLX42.h"

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>

# include "../shared/libft/libft.h"
# include "../shared/gnl/get_next_line.h"

# include "prototypes.h"
# include "structs.h"

# define RED "\033[31m"
# define RESET "\033[0m"


# define tile_w 64
# define tile_h 64
# define FOV PI / 30
# define PI 3.14159265359
# define WIDTH 16 * 64
# define HEIGHT 10 * 64

#endif
