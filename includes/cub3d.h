/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krai <ael-krai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:26:57 by ajelloul          #+#    #+#             */
/*   Updated: 2025/09/16 14:01:39 by ael-krai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "/Users/ael-krai/MLX42/include/MLX42/MLX42.h"

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

# define PI 3.14159265359f
# define FOV (PI / 3.0f)
# define WIDTH 1280
# define HEIGHT 720
# define BLOCK 64
# define PLAYER_SPEED 6.0f
# define ANGLE_SPEED 0.03f

# define COLOR_WALL   0xFFFFFF
# define COLOR_RAY    0xFF0000
# define COLOR_PLAYER 0x00FF00
# define COLOR_BG     0x000000

# define DEG2RAD(a) ((a) * PI / 180.0f)


#endif
