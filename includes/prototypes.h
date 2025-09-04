#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "cub3d.h"
# include "structs.h"





int	init_cub(t_cub *cub);
int	shutdown_cub(t_cub *cub);
int	parse_game_settings(t_cub *cub, int fd);
int	load_map_data(t_cub *cub, int ac, char **av);
void	run_cub(t_cub *cub);


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

int	validate_textures_and_colors(t_cub *cub);

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
void	gc_collect(t_cub *cub);
void	delete_duplicate_list(t_duplicat_list *list);




/*	Exec  hooks 		*/


void	close_window_esc(mlx_key_data_t key, void *param);




/*     Randring  / Recast      */
// player
void    clear_player(t_cub *cub);
void	draw_player(t_cub *cub);

// hooks
void    key_handler(mlx_key_data_t key, void *param);
void	render_player(void *param);

// drawing
void	draw_square(t_cub *cub, int x, int y, int w, int h, int color);
void    draw_celling_and_ground(t_cub *cub);
void	draw_map(t_cub *cub);


#endif