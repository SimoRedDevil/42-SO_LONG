/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:34:59 by mel-yous          #+#    #+#             */
/*   Updated: 2023/02/04 14:22:18 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	*ft_choose_xy(const char **m)
{
	int			x;
	int			y;
	int			*xy;

	y = 0;
	xy = (int *)ft_calloc(2, sizeof(int));
	if (!xy)
		ft_show_error("Allocation of the fake map failed!");
	while (m[y])
	{
		x = 0;
		while (m[y][x])
		{
			if (m[y][x] == 'P')
			{
				xy[0] = x;
				xy[1] = y;
				break ;
			}
			x++;
		}
		y++;
	}
	return (xy);
}

char	**ft_create_fakemap(const char **map)
{
	char		**fake_map;
	int			i;

	i = 0;
	fake_map = malloc((ft_tab_size((const char **)map) + 1) * sizeof(char *));
	if (!fake_map)
		ft_show_error("Allocation of the fake map failed!");
	while (map[i])
	{
		fake_map[i] = ft_strdup(map[i]);
		if (!fake_map[i])
			ft_show_error("Allocation of the fake map failed!");
		i++;
	}
	fake_map[i] = NULL;
	return (fake_map);
}

void	ft_flood_fill(char **map, int x, int y)
{
	if (x < 0 || x >= (int)ft_strlen_pro(map[0], '\n') || y < 0
		|| y >= ft_tab_size((const char **)map) || map[y][x] == '1'
		|| map[y][x] == 'V' || map[y][x] == 'E')
		return ;
	if (map[y][x] != 'P')
		map[y][x] = 'V';
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x, y - 1);
	ft_flood_fill(map, x, y + 1);
}

void	ft_check_validpath(const char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				ft_show_error("Something wrong with valid path!");
			if (map[i][j] == 'E' && map[i - 1][j] != 'V'
			&& map[i + 1][j] != 'V'
			&& map[i][j - 1] != 'V' && map[i][j + 1] != 'V')
				ft_show_error("Something wrong with valid path!");
			j++;
		}
		i++;
	}
}
