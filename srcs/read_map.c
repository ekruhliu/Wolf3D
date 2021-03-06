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

static	int	clean_tab(char **tab)
{
	int		widthe;
	int		i;

	i = 0;
	widthe = 0;
	while (tab[widthe])
		widthe++;
	while (i < widthe)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (widthe);
}

void		map_widthe(char *argv, t_pool *pool)
{
	int		fd;
	char	**tab;
	int		widthe;

	fd = open(argv, O_RDONLY);
	if (get_next_line(fd, &argv) <= 0)
	{
		error();
		exit(1);
	}
	if (argv)
		free(argv);
	tab = ft_strsplit(argv, ' ');
	widthe = clean_tab(tab);
	while (get_next_line(fd, &argv) > 0)
		ft_strdel(&argv);
	if (argv)
		free(argv);
	close(fd);
	pool->len_map_x = widthe;
}

void		map_height(char *argv, t_pool *pool)
{
	int fd;
	int height;

	height = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &argv) > 0)
	{
		height++;
		ft_strdel(&argv);
	}
	if (argv)
		free(argv);
	close(fd);
	pool->len_map_y = height;
}

char		*read_file(char *argv)
{
	char	*res;
	char	*tmp;
	int		fd;

	fd = open(argv, O_RDONLY);
	res = ft_strdup("\0");
	while (get_next_line(fd, &argv) > 0)
	{
		tmp = ft_strdup(res);
		ft_strdel(&res);
		res = ft_strjoin(tmp, " ");
		ft_strdel(&tmp);
		tmp = ft_strdup(res);
		ft_strdel(&res);
		res = ft_strjoin(tmp, argv);
		ft_strdel(&tmp);
		ft_strdel(&argv);
	}
	if (argv)
		free(argv);
	close(fd);
	return (res);
}
