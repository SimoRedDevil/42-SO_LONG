/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:40:52 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/08 09:16:39 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include <mlx.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_gameinfo
{
	char **map;
	int walls;
	int space;
	int collec;
	int exit;
	int player;
} t_gameinfo;

char **ft_read_map(const char *path);
int ft_map_validator(char **map);
void ft_show_error(const char *msg);

#endif