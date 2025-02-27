/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodothers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:17:46 by naalmasr          #+#    #+#             */
/*   Updated: 2025/02/14 11:25:46 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_characters(t_map *gg, int i, int j)
{
	if (gg->map[i][j] == 'C')
		gg->collectibls++;
	if (gg->map[i][j] == 'P')
	{
		gg->player++;
		gg->playerx = j;
		gg->playery = i;
	}
	if (gg->map[i][j] == 'E')
	{
		gg->exit++;
		gg->exitx = j;
		gg->exity = i;
	}
}

void	check_validchar(t_map *gg)
{
	int		i;
	int		j;

	i = 0;
	if (!gg->map || !gg->map[0])
		cleanup_and_exit(gg, "Map is NULL or empty");
	while (gg->map[i])
	{
		j = 0;
		while (gg->map[i][j] != '\0')
		{
			if (gg->map[i][j] != '0' && gg->map[i][j] != '1' &&
				gg->map[i][j] != 'C' && gg->map[i][j] != 'P' &&
				gg->map[i][j] != 'E')
				cleanup_and_exit(gg, "Invalid character in map");
			if (gg->map[i][j] == ' ')
				cleanup_and_exit(gg, "Space character found in map");
			count_characters(gg, i, j);
			j++;
		}
		i++;
	}
	if (gg->player != 1 || gg->exit != 1 || gg->collectibls < 1)
		cleanup_and_exit(gg, "Invalid number of p, e, or c");
}

void	check_rectangular(t_map *gg)
{
	size_t	line_len;
	int		i;

	i = 1;
	if (!gg->map || !gg->map[0])
		cleanup_and_exit(gg, "Map is NULL or empty");
	line_len = ft_strlen(gg->map[0]);
	while (gg->map[i])
	{
		if (ft_strlen(gg->map[i]) != line_len)
			cleanup_and_exit(gg, "Map is not rectangular");
		i++;
	}
	gg->cols = line_len;
	gg->rows = i;
}

void	check_ifclosed(t_map *gg)
{
	int	i;

	i = 0;
	while (gg->map[0][i])
	{
		if (gg->map[0][i] != '1' || gg->map[gg->rows - 1][i] != '1')
			cleanup_and_exit(gg, "Map is not closed (top/bottom)");
		i++;
	}
	i = 0;
	while (gg->map[i])
	{
		if (gg->map[i][0] != '1' || gg->map[i][gg->cols - 1] != '1')
			cleanup_and_exit(gg, "Map is not closed (left/right)");
		i++;
	}
}

void	flood_fill(t_map *gg, int x, int y, char f)
{
	if (x < 0 || y < 0 || x >= gg->cols || y >= gg->rows || \
		gg->map[y][x] == '1' || gg->map_cpy[y][x] == f)
		return ;
	gg->map_cpy[y][x] = f;
	flood_fill(gg, x + 1, y, f);
	flood_fill(gg, x - 1, y, f);
	flood_fill(gg, x, y + 1, f);
	flood_fill(gg, x, y - 1, f);
}
