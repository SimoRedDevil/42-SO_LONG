/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:40:52 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/11 11:12:51 by mel-yous         ###   ########.fr       */
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
} t_gameinfo;

char **ft_read_map(const char *path);
void ft_map_validator(const char **map);
void ft_show_error(const char *msg);
void ft_struct_initializer(t_gameinfo *game_data, char **map);
int ft_serach_tab(const char **tab, char c);
int ft_tab_size(const char **tab);

#endif