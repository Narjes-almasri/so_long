/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:12:14 by naalmasr          #+#    #+#             */
/*   Updated: 2025/02/14 13:06:06 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>

# define NUM 64

typedef struct s_map
{
	void	*mlx;
	void	*window;
	void	*background;
	void	*wall;
	void	*s;
	void	*c;
	void	*e;
	void	*p;
	int		fd;
	int		cols;
	int		rows;
	int		exit;
	int		exitx;
	int		exity;
	int		mov;
	int		collectibls;
	int		player;
	int		playerx;
	int		playery;
	int		flag;
	char	*line;
	char	**map;
	char	**map_cpy;
}	t_map;

char	**ft_split(char const *s, char c);
void	*free_arr(char **arr);
char	*fill_word(char const *s, char c, int start);
int		count_words(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	init_map(t_map *gg);
int		key_hooka(int k, t_map *gg);
void	move_down(t_map *gg, int k);
void	move_up(t_map *gg, int k);
void	move_left(t_map *gg, int k);
void	move_right(t_map *gg, int k);
void	complete_move(t_map *gg, int k);
void	read_fun(char *map, t_map *gg);
void	check_map(t_map *gg, char *line);
void	check_path(t_map *gg);
void	design_game(t_map *gg);
void	fill_img(t_map *gg);
void	flood_fill(t_map *gg, int x, int y, char f);
void	check_ifclosed(t_map *gg);
void	check_rectangular(t_map *gg);
void	check_validchar(t_map *gg);
void	count_characters(t_map *gg, int i, int j);
int		check_ex(char *av);
int		ft_closewin(t_map *gg);
void	cleanup_and_exit(t_map *gg, char *error_msg);
void	print_mov(t_map *gg);

#endif
