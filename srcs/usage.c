/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:05:43 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/02 15:05:44 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	usage(void)
{
	ft_putstr("\033[1;31musage: ./wolf3d MAP NAME\n\e[m");
}

void	error(void)
{
	ft_putstr("\033[1;31mERROR\n\e[m");
}

void	check_mand(t_pool *pool, char *argv)
{
	if (argv)
	{
		if (ft_atoi(argv) == 1)
			pool->mp = 1;
	}
}
