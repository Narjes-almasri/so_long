/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:07:27 by naalmasr          #+#    #+#             */
/*   Updated: 2025/02/12 16:42:09 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	complete_move(t_map *gg, int k)
{
	if (gg->flag == 1 && gg->collectibls >= 0)
	{
		mlx_put_image_to_window(gg->mlx, gg->window, gg->e,
			gg->exitx * NUM, gg->exity * NUM);
		gg->map[gg->playery][gg->playerx] = 'E';
		gg->flag = 0;
	}
	if (k == XK_w)
		gg->playery--;
	if (k == XK_s)
		gg->playery++;
	if (k == XK_a)
		gg->playerx--;
	if (k == XK_d)
		gg->playerx++;
	if (gg->map[gg->playery][gg->playerx] == 'E')
		gg->flag = 1;
	mlx_put_image_to_window(gg->mlx, gg->window, gg->p,
		gg->playerx * NUM, gg->playery * NUM);
	gg->map[gg->playery][gg->playerx] = 'P';
	gg->mov++;
	print_mov(gg);
}

void	move_right(t_map *gg, int k)
{
	if (gg->map[gg->playery][gg->playerx + 1] != '1')
	{
		gg->map[gg->playery][gg->playerx] = '0';
		if (gg->map[gg->playery][gg->playerx + 1] == 'E' \
			&& gg->collectibls == 0)
		{
			gg->mov++;
			print_mov(gg);
			ft_printf("You won!\n");
			ft_closewin(gg);
		}
		if (gg->map[gg->playery][gg->playerx + 1] == 'C')
		{
			gg->map[gg->playery][gg->playerx + 1] = '0';
			gg->collectibls--;
		}
		mlx_put_image_to_window(gg->mlx, gg->window, gg->background,
			gg->playerx * NUM, gg->playery * NUM);
		complete_move(gg, k);
	}
}

void	move_left(t_map *gg, int k)
{
	if (gg->map[gg->playery][gg->playerx - 1] != '1')
	{
		gg->map[gg->playery][gg->playerx] = '0';
		if (gg->map[gg->playery][gg->playerx - 1] == 'E' \
			&& gg->collectibls == 0)
		{
			gg->mov++;
			print_mov(gg);
			ft_printf("You won!\n");
			ft_closewin(gg);
		}
		if (gg->map[gg->playery][gg->playerx - 1] == 'C')
		{
			gg->map[gg->playery][gg->playerx - 1] = '0';
			gg->collectibls--;
		}
		mlx_put_image_to_window(gg->mlx, gg->window, gg->background,
			gg->playerx * NUM, gg->playery * NUM);
		complete_move(gg, k);
	}
}

void	move_up(t_map *gg, int k)
{
	if (gg->playery > 0 && gg->map[gg->playery - 1][gg->playerx] != '1')
	{
		gg->map[gg->playery][gg->playerx] = '0';
		if (gg->map[gg->playery - 1][gg->playerx] == 'E' \
			&& gg->collectibls == 0)
		{
			gg->mov++;
			print_mov(gg);
			ft_printf("You won!\n");
			ft_closewin(gg);
		}
		if (gg->map[gg->playery - 1][gg->playerx] == 'C')
		{
			gg->map[gg->playery - 1][gg->playerx] = '0';
			gg->collectibls--;
		}
		mlx_put_image_to_window(gg->mlx, gg->window, gg->background,
			gg->playerx * NUM, gg->playery * NUM);
		complete_move(gg, k);
	}
}

void	move_down(t_map *gg, int k)
{
	if (gg->map[gg->playery + 1][gg->playerx] != '1')
	{
		gg->map[gg->playery][gg->playerx] = '0';
		if (gg->map[gg->playery + 1][gg->playerx] == 'E' \
			&& gg->collectibls == 0)
		{
			gg->mov++;
			print_mov(gg);
			ft_printf("You won!\n");
			ft_closewin(gg);
		}
		if (gg->map[gg->playery + 1][gg->playerx] == 'C')
		{
			gg->map[gg->playery + 1][gg->playerx] = '0';
			gg->collectibls--;
		}
		mlx_put_image_to_window(gg->mlx, gg->window, gg->background,
			gg->playerx * NUM, gg->playery * NUM);
		complete_move(gg, k);
	}
}
