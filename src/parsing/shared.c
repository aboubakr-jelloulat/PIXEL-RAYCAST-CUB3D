/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:19:49 by ajelloul          #+#    #+#             */
/*   Updated: 2025/09/02 10:54:25 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_valid_numbers(char *str)
{
	int	idx;

	idx = 0;
	if (!str || !*str)
		return (false);
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return (false);
		idx++;
	}
	return (true);
}

/*
	If it finds a newline character '\n' it replaces it with '\0'
	
	removes the trailing newline from lines you read with get_next_line

	str = "220,100,0\n"
	
	str = "220,100,0"
*/
void	trim_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			return ;
		}
		i++;
	}
}

int	skip_spaces(char **line)
{
	int	i;

	i = 0;
	while ((*line)[i] == ' ' || (*line)[i] == '\t')
	{
		i++;
	}
	return (i);
}

void	display_errors(const char *error_msg)
{
	printf(RED "\nError\n \t=> %s \033[0m\n", error_msg);
}

bool	is_space(char c)
{
	return (c == 32);
}
