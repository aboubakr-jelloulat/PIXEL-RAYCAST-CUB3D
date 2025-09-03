/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:43:47 by ajelloul          #+#    #+#             */
/*   Updated: 2025/09/03 22:52:33 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "cub3d.h"
# include "structs.h"

int		init_cub(t_cub *cub);
int		shutdown_cub(t_cub *cub);
int		parse_game_settings(t_cub *cub, int fd);
int		load_map_data(t_cub *cub, int ac, char **av);
void	run_cub(t_cub *cub);

/*		handel bascis output		*/

int		valid_file_extension(char *filename);
int		open_map_file(char *filename);

/*			Parse Map Key		*/

int		configuration_key(t_cub *cub, char *line, int i, int *success);
int		is_duplicate(t_duplicat_list **list, char *key);
void	add_key_to_duplicate_list(t_duplicat_list **list, char *key);
int		save_image_path(t_cub *cub, char **path, char *line);
char	*get_path(char *line, int i);
int		validate_textures_and_colors(t_cub *cub);

/*	PARSE Color		 */

void	parse_colors(t_cub *cub, char *line, int i, int *succes);
void	trim_newline(char *str);
bool	is_valid_numbers(char *str);

/*  Validate   Color 	*/

int		validate_textures_and_colors(t_cub *cub);

/*		Errors	 */

void	display_errors(const char *error_msg);

/*			Shared		*/

bool	is_space(char c);

/*		Free		*/

void	free_rbg_values(char **value);
void	gc_collect(t_cub *cub);
void	delete_duplicate_list(t_duplicat_list *list);
void	delete_map_rows(t_map_row *map_row);

/*	Exec  hooks 		*/

void	close_window_esc(mlx_key_data_t key, void *param);

/*     Parse Map       */

int		parse_map(t_cub *cub, int fd);
int		is_valid_map_char(char c);
int		is_wall_or_space(char c);
int		is_whitespace(char c);
int		up_valid(t_map_row *up, int pos);
int		down_valid(t_map_row *down, int pos);
int		is_valid_map(t_map_row *map_row);
int		skip_spaces(char **line);

/*     Validate & Set Player       */

int		validate_and_set_player(t_cub *cub);
void	set_player(t_cub *cub, int x, int y, int angle);



#endif