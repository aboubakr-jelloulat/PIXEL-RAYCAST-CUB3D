/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_key_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:46:36 by ajelloul          #+#    #+#             */
/*   Updated: 2025/08/27 16:07:29 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	add_key_to_duplicate_list(t_duplicat_list **list, char *key)
{
	t_duplicat_list	*new_node;
	t_duplicat_list	*cur;

	new_node = malloc(sizeof(t_duplicat_list));
	if (!new_node)
		return ;
	new_node->key = key;
	new_node->next = NULL;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new_node;
}

int	is_duplicate(t_duplicat_list **list, char *key)
{
	t_duplicat_list	*tmp;
	int				n;

	tmp = *list;
	n = ft_strlen(key);
	while (tmp)
	{
		if (ft_strncmp(tmp->key, key, n + 1) == 0)
			return (1);
		tmp = tmp->next;
	}
	add_key_to_duplicate_list(list, key);
	return (0);
}

char	*get_path(char *line, int i)
{
	int		cp;
	char	*sub_path;
	char	*return_path;

	cp = 0;
	while (line[i + cp] && line[i + cp] != '\n')
		cp++;
	sub_path = ft_substr(line, i, cp);
	return_path = ft_strtrim(sub_path, " ");
	free(sub_path);
	return (return_path);
}

int	save_image_path(t_cub *cub, char **path, char *line)
{
	int	len;
	int	i;

	i = 0;
	if (!line || !line[i])
		return (0);
	i = skip_spaces(&line);
	if (line[i] == 0 || line[i] == '\n')
		return (0);
	*path = get_path(line, i);
	if (!*path)
		return (0);
	len = ft_strlen(*path);
	if (len < 4 || ft_strncmp(*path + len - 4, ".png", 4) != 0)
	{
		free(*path);
		*path = NULL;
		cub->list_status.is_wrong_txtr_extension = true;
		return (0);
	}
	return (1);
}
