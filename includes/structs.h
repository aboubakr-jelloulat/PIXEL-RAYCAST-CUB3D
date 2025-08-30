/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:42:12 by ajelloul          #+#    #+#             */
/*   Updated: 2025/08/30 12:43:08 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"
# include "structs.h"

typedef struct s_map_row
{
	char				*row;
	int					size;
	struct s_map_row	*up_row;
	struct s_map_row	*down_row;
}	t_map_row;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_texture
{
	mlx_texture_t	*mlx_north;
	mlx_texture_t	*mlx_south;
	mlx_texture_t	*mlx_west;
	mlx_texture_t	*mlx_east;
}	t_texture;

typedef struct s_list_status
{
	bool	is_duplicate_key;
	bool	is_wrong_txtr_extension;
	int		floor_color;
	int		ceiling_color;
	bool	invalid_key;
}	t_list_status;

typedef struct s_duplicat_list
{
	char					*key;
	struct s_duplicat_list	*next;
}	t_duplicat_list;

typedef struct s_cub
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	char			*no_texture_path;
	char			*so_texture_path;
	char			*we_texture_path;
	char			*ea_texture_path;
	t_texture		textures;
	t_duplicat_list	*duplicate_list;
	t_list_status	list_status;
	t_map			map;
}	t_cub;

#endif