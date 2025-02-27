/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:20:43 by naalmasr          #+#    #+#             */
/*   Updated: 2025/02/14 11:30:13 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *gg)
{
	gg->collectibls = 0;
	gg->c = NULL;
	gg->background = NULL;
	gg->e = NULL;
	gg->p = NULL;
	gg->wall = NULL;
	gg->player = 0;
	gg->exit = 0;
	gg->playerx = 0;
	gg->playery = 0;
	gg->exitx = 0;
	gg->exity = 0;
	gg->map = NULL;
	gg->map_cpy = NULL;
	gg->line = NULL;
	gg->rows = 0;
	gg->cols = 0;
	gg->mlx = NULL;
	gg->window = NULL;
	gg->fd = -1;
	gg->mov = 0;
	gg->flag = 0;
}

void	print_mov(t_map *gg)
{
	ft_printf("movements: %d\n", gg->mov);
}

void	cleanup_and_exit(t_map *gg, char *error_msg)
{
	if (error_msg)
		ft_printf("Error:\n %s", error_msg);
	if (gg->map)
		free_arr(gg->map);
	if (gg->map_cpy)
		free_arr(gg->map_cpy);
	if (gg->line)
		free(gg->line);
	if (gg->background)
		mlx_destroy_image(gg->mlx, gg->background);
	if (gg->e)
		mlx_destroy_image(gg->mlx, gg->e);
	if (gg->p)
		mlx_destroy_image(gg->mlx, gg->p);
	if (gg->wall)
		mlx_destroy_image(gg->mlx, gg->wall);
	if (gg->c)
		mlx_destroy_image(gg->mlx, gg->c);
	if (gg->window)
		mlx_destroy_window(gg->mlx, gg->window);
	if (gg->mlx)
		mlx_destroy_display(gg->mlx);
	free(gg->mlx);
	free(gg);
	exit(1);
}

int	ft_closewin(t_map *gg)
{
	cleanup_and_exit(gg, NULL);
	return (0);
}

int	check_ex(char *av)
{
	int	i;
	int	num;

	i = ft_strlen(av);
	num = (ft_strcmp(av + (i - 4), ".ber"));
	if (num == 0)
		return (0);
	else
		return (num);
}
