/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:15:19 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/08 11:26:03 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int ft_ber_checker(const char *map_path)
{
	int i;

	i = 0;
	while (map_path[i])
	{
		if (map_path[i] == '.' 
			&& map_path[i + 1] == 'b' && map_path[i + 2] == 'e'
			&& map_path[i + 3] == 'r' && map_path[i + 4] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static void ft_run_solong(const char *map_path)
{
	t_gameinfo game_data;
	
	if (ft_ber_checker(map_path) == 0)
		ft_show_error("The map extension is not valid!");
	game_data.map = ft_read_map(map_path);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_run_solong(argv[1]);
	else
		ft_show_error("The number of args is not valid!");
}
