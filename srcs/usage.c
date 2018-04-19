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

void	just_exit(t_pool *pool)
{
	SDL_DestroyWindow(WIN);
	cleaner(pool);;
	SDL_Quit();
}

void	usage(void)
{
	ft_putstr("\033[1;31musage: ./wolf3d MapName\n\e[m");
	ft_putstr("\033[1;31mMandatory part: ./wolf3d MapName mandatory\n\e[m");
}

void	error(void)
{
	ft_putstr("\033[1;31mERROR\n\e[m");
}

void	check_mand_and_leaks(t_pool *pool, char *arg, char *arg_2)
{
	if (arg || arg_2)
	{
		if ((CHEK("mandatory", arg) == 1) || (CHEK("mandatory", arg_2) == 1))
			pool->mp = 1;
		if ((CHEK("leaks", arg) == 1) || (CHEK("leaks", arg) == 1))
			pool->check_leak = 1;
	}
}
