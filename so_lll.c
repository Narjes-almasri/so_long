/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_lll.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:38:53 by naalmasr          #+#    #+#             */
/*   Updated: 2025/02/14 12:29:20 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	fill_img(t_map *gg)
{
	int	width;
	int	hight;

	gg->background = mlx_xpm_file_to_image(
			gg->mlx, "textures/waaa.xpm", &width, &hight);
	gg->c = mlx_xpm_file_to_image(
			gg->mlx, "textures/colec.xpm", &width, &hight);
	gg->e = mlx_xpm_file_to_image(
			gg->mlx, "textures/e.xpm", &width, &hight);
	gg->p = mlx_xpm_file_to_image(
			gg->mlx, "textures/plaa.xpm", &width, &hight);
	gg->wall = mlx_xpm_file_to_image(
			gg->mlx, "textures/w.xpm", &width, &hight);
	if (!gg->wall || !gg->p || !gg->e || !gg->c || !gg->background)
	{
		cleanup_and_exit(gg, "protection");
	}
}

void	design_game2(t_map *gg, int y, int x)
{
	if (gg->map[y][x] == 'E' && gg->collectibls == 0)
		mlx_put_image_to_window(gg->mlx, gg->window, gg->e,
			x * NUM, y * NUM);
	if (gg->map[y][x] == 'P')
		mlx_put_image_to_window(gg->mlx, gg->window, gg->p,
			x * NUM, y * NUM);
}

void	design_game(t_map *gg)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (gg->map[y])
	{
		while (gg->map[y][x])
		{
			if (gg->map[y][x] == '1')
				mlx_put_image_to_window(gg->mlx, gg->window, gg->wall,
					x * NUM, y * NUM);
			if (gg->map[y][x] == '0' || (gg->map[y][x] == 'E'
					&& gg->collectibls != 0))
				mlx_put_image_to_window(gg->mlx, gg->window, gg->background,
					x * NUM, y * NUM);
			if (gg->map[y][x] == 'C')
				mlx_put_image_to_window(gg->mlx, gg->window, gg->c,
					x * NUM, y * NUM);
			design_game2(gg, y, x);
			x++;
		}
		x = 0;
		y++;
	}
}

void	check_path(t_map *gg)
{
	int	y;
	int	x;

	y = 0;
	flood_fill(gg, gg->playerx, gg->playery, 'F');
	while (y < gg->rows)
	{
		x = 0;
		while (x < gg->cols)
		{
			if ((gg->map[y][x] == 'E' || gg->map[y][x] == 'C') &&
				gg->map_cpy[y][x] != 'F')
				cleanup_and_exit(gg, "Invalid path to exit or collectible");
			x++;
		}
		y++;
	}
}

void	check_map(t_map *gg, char *line)
{
	int	i;
	int	len;

	i = 0;
	while (line[i])
	{
		len = ft_strlen(line);
		if ((line[i] == '\n' && line[i + 1] == '\n') || line[0] == '\n' \
			|| (line[len - 1] != '\n' && len > 0))
			cleanup_and_exit(gg, "there is a \n");
		i++;
	}
	gg->map = ft_split(gg->line, '\n');
	if (!gg->map)
		cleanup_and_exit(gg, "protection \n");
	gg->map_cpy = ft_split(gg->line, '\n');
	if (!gg->map_cpy)
	{
		cleanup_and_exit(gg, "protection \n");
	}
	check_validchar(gg);
	check_rectangular(gg);
	check_ifclosed(gg);
	check_path(gg);
}
