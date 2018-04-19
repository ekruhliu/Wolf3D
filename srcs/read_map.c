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

#include "../includes/wolf.h"

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
	free(argv);
	tab = ft_strsplit(argv, ' ');
	while (tab[widthe])
		widthe++;
	int i = 0;
	while (i < widthe)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	while (get_next_line(fd, &argv) > 0)
		free(argv);
	free(argv);
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
	free(argv);
	close(fd);
	pool->len_map_y = height;
}

char	*read_file(char *argv)
{
	char	*res;
	char	*tmp;
	int		fd;

	fd = open(argv, O_RDONLY);
	res = ft_strdup("\0");
	while (get_next_line(fd, &argv) > 0)
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
	free(argv);
	close(fd);
	return (res);
}
