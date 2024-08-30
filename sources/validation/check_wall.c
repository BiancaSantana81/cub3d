/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:26:43 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/30 17:47:39 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	fill_map_with_twos(t_data *data);

bool	check_diagonals(t_data *data, int line, int col)
{
	char	**map;

	map = data->map;
	if (line > 0 && col > 0
		&& (map[line - 1][col - 1] == ' ' || map[line - 1][col - 1] == '2'))
		return (false);
	if (line + 1 < data->lines && col > 0
		&& (map[line + 1][col - 1] == ' ' || map[line + 1][col - 1] == '2'))
		return (false);
	if (line > 0 && col + 1 < data->columns
		&& (map[line - 1][col + 1] == ' ' || map[line - 1][col + 1] == '2'))
		return (false);
	if (line + 1 < data->lines && col + 1 < data->columns
		&& (map[line + 1][col + 1] == ' ' || map[line + 1][col + 1] == '2'))
		return (false);
	return (true);
}

bool	check_sides(t_data *data, int line, int col)
{
	char	**map;

	map = data->map;
	if (line <= 0 || line >= data->lines || col <= 0 || col >= data->columns)
		return (false);
	if (line > 0 && (map[line - 1][col] == ' ' || map[line - 1][col] == '2'))
		return (false);
	if (line + 1 < data->lines
		&& (map[line + 1][col] == ' ' || map[line + 1][col] == '2'))
		return (false);
	if (col > 0 && (map[line][col - 1] == ' ' || map[line][col - 1] == '2'))
		return (false);
	if (col + 1 < data->columns
		&& (map[line][col + 1] == ' ' || map[line][col + 1] == '2'))
		return (false);
	return (true);
}

void	surrounded_by_walls(t_data *data)
{
	char	**map;
	int		y;
	int		x;
	int		width;

	y = 0;
	fill_map_with_twos(data);
	map = data->map;
	while (map[y])
	{
		x = 0;
		width = ft_strlen(map[y]);
		while (x <= width)
		{
			if (map[y][x] == '0' || ft_strchr("NSWE", map[y][x]))
			{
				if ((y == 0 || y == data->lines - 1) || (x == 0 || x == width))
					handle_error("Error: invalid map, check the edges.\n");
				if (!check_sides(data, y, x) || !check_diagonals(data, y, x))
					handle_error("Error: invalid map, check the walls.\n");
			}
			x++;
		}
		y++;
	}
}

static void	fill_map_with_twos(t_data *data)
{
	int		i;
	int		j;
	int		len;
	char	**new_map;

	i = 0;
	new_map = ft_calloc(data->lines + 1, sizeof(char *));
	while (i < data->lines)
	{
		j = 0;
		new_map[i] = ft_calloc((data->columns + 1), sizeof(char));
		len = strlen(data->map[i]) - 1;
		while (j < len)
		{
			new_map[i][j] = data->map[i][j];
			j++;
		}
		while (j++ < data->columns)
			new_map[i][j] = '2';
		i++;
	}
	ft_free_matrix(data->map);
	data->map = new_map;
}
