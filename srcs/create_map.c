/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 13:07:52 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/15 13:07:52 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static	void	part_one(t_pool *pool, char **tab)
{
	int i;
	int n;

	i = 0;
	n = 0;
	MAP = (int**)malloc(sizeof(int*) * pool->len_map_y);
	while (i < pool->len_map_y)
	{
		MAP[i] = (int*)malloc(sizeof(int) * pool->len_map_x);
		i++;
	}
	while (tab[n] != 0)
		n++;
	if ((pool->len_map_x * pool->len_map_y) != n)
	{
		ft_putstr("\033[1;31mERROR\n\e[m");
		exit(1);
	}
}

static	void	part_two(t_pool *pool, char **tab)
{
	int y;
	int x;
	int elem;

	y = 0;
	x = 0;
	elem = 0;
	while (y < pool->len_map_y)
	{
		x = 0;
		while (x < pool->len_map_x)
		{
			if (tab[elem][0] == 'X')
			{
				pool->pos_y = (double)x + 0.1;
				pool->pos_x = (double)y + 0.1;
			}
			MAP[y][x] = ft_atoi(tab[elem]);
			if (MAP[y][x] > 22 || MAP[y][x] < 0)
				MAP[y][x] = 0;
			elem++;
			x++;
		}
		y++;
	}
}

static	void	part_three(t_pool *pool)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < pool->len_map_y)
	{
		if (MAP[y][0] == 0)
			MAP[y][0] = 1;
		if (MAP[y][pool->len_map_x - 1] == 0)
			MAP[y][pool->len_map_x - 1] = 1;
		y++;
	}
	while (x < pool->len_map_x)
	{
		if (MAP[0][x] == 0)
			MAP[0][x] = 1;
		if (MAP[pool->len_map_y - 1][x] == 0)
			MAP[pool->len_map_y - 1][x] = 1;
		x++;
	}
}

void			create_map(char *argv, t_pool *pool)
{
	int		i;
	char	*line;
	char	**tab;

	i = 0;
	line = read_file(argv);
	tab = ft_strsplit(line, ' ');
	ft_strdel(&line);
	part_one(pool, tab);
	part_two(pool, tab);
	part_three(pool);
	while (i < pool->len_map_y)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	return ;
}
