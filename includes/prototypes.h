#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "cub3d.h"
# include "structs.h"




int	load_game_engine(int ac, char **av);
int	init_cub(t_cub *cub);
int	shutdown_cub(t_cub *cub);
int	parse_game_settings(t_cub *cub, int fd);


/*		handel ex and bascis output		*/

int	valid_file_extension(char *filename);
int	open_map_file(char *filename);

/*			Parse Map Key		*/

int	configuration_key(t_cub *cub, char *line, int i, int *success);
int	is_duplicate(t_duplicat_list **list, char *key);
void	add_key_to_duplicate_list(t_duplicat_list **list, char *key);
int save_image_path(t_cub *cub, char **path, char *line);
char *get_path(char *line, int i);
int	validate_textures_and_colors(t_cub *cub);


/*	PARSE Color		 */

void	parse_colors(t_cub *cub, char *line, int i, int *succes);
void	trim_newline(char *str);
bool	is_valid_numbers(char *str);

/*  Validate   Color 	*/

bool	validate_all_textures(t_cub *cub);
bool	validate_floor_color(t_cub *cub);
bool	validate_ceiling_color(t_cub *cub);
bool	validate_no_duplicates(t_cub *cub);
bool	validate_texture_extensions(t_cub *cub);

/*		PARSING  MAP */

int		skip_spaces(char **line);
bool	validate_ceiling_color(t_cub *cub);
bool	validate_no_duplicates(t_cub *cub);
bool	validate_texture_extensions(t_cub *cub);


/*		Errors	 */

void	display_errors(const char *error_msg);



/*			Shared		*/

bool	is_space(char c);


/*		Free		*/

void	free_rbg_values(char **value);


#endif