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

static	void	part_one(t_pool *pool)
{
	int i;

	i = 0;
	pool->map = (int**)malloc(sizeof(int*) * pool->len_map_y);
	while (i < pool->len_map_y)
	{
		pool->map[i] = (int*)malloc(sizeof(int) * pool->len_map_x);
		i++;
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
				pool->pos_y = (double)x;
				pool->pos_x = (double)y;
			}
			pool->map[y][x] = ft_atoi(tab[elem]);
			elem++;
			x++;
		}
		y++;
	}
}

void	create_map(char *argv, t_pool *pool)
{
	int		i;
	char	*line;
	char	**tab;

	i = 0;
	line = read_file(argv);
	tab = ft_strsplit(line, ' ');
	part_one(pool);
	part_two(pool, tab);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(line);
}
