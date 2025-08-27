/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:38:55 by ajelloul          #+#    #+#             */
/*   Updated: 2025/08/27 16:09:06 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	trim_trailing_spaces(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (len > 0 && is_space(str[len - 1]))
	{
		str[len - 1] = '\0';
		len--;
	}
}

bool	validate_color_syntax(char *str)
{
	int	pos;
	int	comma_count;

	pos = 0;
	comma_count = 0;
	trim_newline(str);
	trim_trailing_spaces(str);
	while (str[pos])
	{
		if (str[pos] == ',')
			comma_count++;
		if (!ft_isdigit(str[pos]) && str[pos] != ',' && !is_space(str[pos]))
			return (true);
		if (is_space(str[pos]) && str[pos + 1] == ',')
			return (true);
		pos++;
	}
	if (comma_count != 2)
		return (true);
	return (false);
}

int	validate_rgb_components(char **values, int *r, int *g, int *b)
{
	if (!values || !values[0] || !values[1] || !values[2] || values[3])
		return (0);
	if (!is_valid_numbers(values[0]) || !is_valid_numbers(values[1])
		|| !is_valid_numbers(values[2]))
		return (0);
	*r = ft_atoi(values[0]);
	*g = ft_atoi(values[1]);
	*b = ft_atoi(values[2]);
	if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255)
		return (0);
	return (1);
}

int	parse_color_value(char *line, int *out_color)
{
	int		r;
	int		g;
	int		b;
	char	**values;

	if (validate_color_syntax(line))
		return (0);
	while (is_space(*line))
		line++;
	values = ft_split(line, ',');
	if (!validate_rgb_components(values, &r, &g, &b))
	{
		free_rbg_values(values);
		return (0);
	}
	free_rbg_values(values);
	*out_color = (r << 24) | (g << 16) | (b << 8) | 255;
	return (1);
}

void	parse_colors(t_cub *cub, char *line, int i, int *succes)
{
	char	*id;

	id = line + i;
	if (*id == 'F')
	{
		if (is_duplicate(&cub->duplicate_list, "F"))
			cub->list_status.is_duplicate_key = true;
		if (parse_color_value(id + 1, &cub->list_status.floor_color))
			(*succes)++;
	}
	else if (*id == 'C')
	{
		if (is_duplicate(&cub->duplicate_list, "C"))
			cub->list_status.is_duplicate_key = true;
		if (parse_color_value(id + 1, &cub->list_status.ceiling_color))
			(*succes)++;
	}
}
