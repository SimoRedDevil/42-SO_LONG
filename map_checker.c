/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 08:22:08 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/15 01:36:38 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_begin_end(const char **map)
{
	int	j;
	int	tab_size;

	j = 0;
	tab_size = ft_tab_size(map) - 1;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			ft_show_error("The map is not closed!");
		j++;
	}
	j = 0;
	while (map[tab_size][j])
	{
		if (map[tab_size][j] != '1')
			ft_show_error("The map is not closed!");
		j++;
	}
}

static void	ft_map_closed(const char **map)
{
	int	i;
	int	j;
	int	len;
	int	tab_size;

	i = 0;
	len = ft_strlen(map[i]) - 1;
	tab_size = ft_tab_size(map) - 1;
	while (map[i])
	{
		j = 0;
		if (i == 0 || i == tab_size)
			ft_check_begin_end(map);
		else if (i != 0 && i != tab_size)
		{
			if (map[i][0] != '1' || map[i][len] != '1')
				ft_show_error("The map is not closed!");
		}
		i++;
	}
}

static void	ft_check_characters(const char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'C' && map[i][j] != 'P'
				&& map[i][j] != 'E')
				ft_show_error("The map contains an unknown character!");
			j++;
		}
		i++;
	}
	if (!ft_search_tab(map, '0') || !ft_search_tab(map, 'C')
		|| !ft_search_tab(map, 'P') || !ft_search_tab(map, 'E'))
		ft_show_error("One or some of the characters are missing!");
}

static void	ft_check_duplication(const char **map)
{
	int	i;
	int	j;
	int	player;
	int	exit;

	i = 0;
	player = 0;
	exit = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
			if (player > 1 || exit > 1)
				ft_show_error("There's a duplication of characters!");
			j++;
		}
		i++;
	}
}

void	ft_map_validator(const char **map)
{
	if (!map)
		ft_show_error("Error while reading the map!");
	ft_map_closed(map);
	ft_check_characters(map);
	ft_check_duplication(map);
}
