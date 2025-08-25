/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:12:58 by naalmasr          #+#    #+#             */
/*   Updated: 2025/02/14 12:30:29 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	key_hooka(int k, t_map *gg)
{
	if (k == 65307)
	{
		ft_closewin(gg);
		return (0);
	}
	if (k == 119)
		move_up(gg, k);
	if (k == 97)
		move_left(gg, k);
	if (k == 115)
		move_down(gg, k);
	if (k == 100)
		move_right(gg, k);
	design_game(gg);
	return (0);
}

void	read_fun(char *map, t_map *gg)
{
	char	*tmp;

	gg->fd = open(map, O_RDONLY);
	tmp = get_next_line(gg->fd);
	if (!tmp)
		cleanup_and_exit(gg, "Memory allocation failed for line");
	gg->line = ft_calloc(1, 1);
	if (!gg->line)
		cleanup_and_exit(gg, "Memory allocation failed for line");
	while (tmp)
	{
		if (gg->line)
		{
			gg->line = ft_strjoin(gg->line, tmp);
			free(tmp);
		}
		tmp = get_next_line(gg->fd);
	}
	free(tmp);
	close(gg->fd);
	check_map(gg, gg->line);
}

int	main(int ac, char **av)
{
	t_map	*gg;

	if (ac != 2 || check_ex(av[1]) != 0)
	{
		ft_printf("Error:\n Invalid arguments\n");
		return (1);
	}
	gg = malloc(sizeof(t_map));
	if (!gg)
		cleanup_and_exit(gg, "Error: Memory allocation failed\n");
	init_map(gg);
	read_fun(av[1], gg);
	gg->mlx = mlx_init();
	if (!gg->mlx)
		cleanup_and_exit(gg, "Error: mlx initialization failed\n");
	gg->window = mlx_new_window(gg->mlx, gg->cols * NUM,
			gg->rows * NUM, "SUPER NARIO");
	if (!gg->window)
		cleanup_and_exit(gg, "Error\n");
	fill_img(gg);
	design_game(gg);
	mlx_hook(gg->window, 2, 1L << 0, key_hooka, gg);
	mlx_hook(gg->window, 17, 0, ft_closewin, gg);
	mlx_loop(gg->mlx);
	return (0);
}
