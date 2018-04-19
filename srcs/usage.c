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
	ft_putstr("\033[1;31musage: ./wolf3d MapName\n\e[m");
	ft_putstr("\033[1;31mMandatory part: ./wolf3d MapName mandatory\n\e[m");
}

void	error(void)
{
	ft_putstr("\033[1;31mERROR\n\e[m");
}

void	check_mand(t_pool *pool, char *argv)
{
	if (argv)
	{
		if (ft_strequ("mandatory", argv) == 1)
			pool->mp = 1;
	}
}
