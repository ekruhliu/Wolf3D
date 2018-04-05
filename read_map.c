/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:42:06 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/05 11:42:07 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	map_widthe(char *argv, t_pool *pool)
{
	int		widthe;
	int		fd;
	char	**tab;

	widthe = 0;
	fd = open(argv, O_RDONLY);
	if (get_next_line(fd, &argv) <= 0)
	{
		error();
		exit(1);
	}
	// free(argv);
	tab = ft_strsplit(argv, ' ');
	while (tab[widthe])
		widthe++;
	while (get_next_line(fd, &argv) > 0)
		free(argv);
	// free(argv);
	close(fd);
	pool->len_map_x = widthe;
}

void	map_height(char *argv, t_pool *pool)
{
	int fd;
	int height;

	height = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &argv) > 0)
	{
		height++;
		free(argv);
	}
	// free(argv);
	close(fd);
	pool->len_map_y = height;
}

char		*read_file(char *argv)
{
	char	*res;
	char	*tmp;
	int		read_res;
	int		fd;

	fd = open(argv, O_RDONLY);
	res = ft_strdup("\0");
	while ((read_res = get_next_line(fd, &argv)) > 0)
	{
		tmp = ft_strdup(res);
		free(res);
		res = ft_strjoin(tmp, " ");
		free(tmp);
		tmp = ft_strdup(res);
		free(res);
		res = ft_strjoin(tmp, argv);
		free(tmp);
		free(argv);
	}
	// free(argv);
	close(fd);
	return (res);
}

void	create_map(char *argv, t_pool *pool)
{
	int		i;
	int		n;
	char	*line;
	char	**tab;
	int 	elem = 0;

	i = 0;
	n = 0;
	pool->map = (int**)malloc(sizeof(int*) * pool->len_map_y);
	while (i < pool->len_map_y)
	{
		pool->map[i] = (int*)malloc(sizeof(int) * pool->len_map_x);
		i++;
	}
	i = 0;
	line = read_file(argv);
	tab = ft_strsplit(line, ' ');
	while (i < pool->len_map_y)
	{
		n = 0;
		while (n < pool->len_map_x)
		{
			pool->map[i][n] = ft_atoi(tab[elem]);
			elem++;
			n++;
		}
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(line);
}
