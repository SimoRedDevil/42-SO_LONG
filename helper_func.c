/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 09:08:50 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/11 11:12:40 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_serach_tab(const char **tab, char c)
{
	int i;
	int j;
	
	i = 0;
	while(tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int ft_tab_size(const char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void ft_show_error(const char *msg)
{
	ft_printf("Error\n%s", msg);
	exit(1);
}

void ft_struct_initializer(t_gameinfo *game_data, char **map)
{
	int i;
	int j;

	i = 0;
	game_data->map = map;
	if (!(game_data->map))
		ft_show_error("Error while reading the map!");
}