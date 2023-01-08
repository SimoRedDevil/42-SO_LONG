/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 08:38:24 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/08 11:30:58 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char *ft_call_strjoin(char *s1, char *s2)
{
	char *result;
	
	if (!s1)
		s1 = ft_strdup("");
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

static void ft_check_map_lines(const char *line)
{
	static int first_line;
	
	if (first_line == 0)
		first_line = (int)ft_strlen_pro(line, '\n');
	if (first_line != ft_strlen_pro(line, '\n'))
		ft_show_error("The map isn't in shape, please check it before you run the game!");
}

char **ft_read_map(const char *path)
{
	int fd;
	char *curr_line;
	char *map_content;
	char **map_tab;

	if (!path || *path == '\0')
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	curr_line = get_next_line(fd);
	map_content = NULL;
	while (curr_line)
	{
		ft_check_map_lines(curr_line);
		map_content = ft_call_strjoin(map_content, curr_line);
		free(curr_line);
		curr_line = NULL;
		curr_line = get_next_line(fd);
	}
	map_tab = ft_split(map_content, '\n');
	free(map_content);
	close(fd);
	return (map_tab);
}