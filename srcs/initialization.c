/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:41:29 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/11 13:41:30 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static	void	part_one(t_pool *pool)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		ft_putstr("\033[1;31mError initializing SDL\n\e[m");
		exit(1);
	}
	WIN = SDL_CreateWindow("Wolf3d", WINDOW_IN, W, H, 0);
	if (!WIN)
	{
		ft_putstr("\033[1;31mError creating window\n\e[m");
		SDL_Quit();
		exit(1);
	}
}

static void		part_two(t_pool *pool)
{
	RENDER_FLAG = SDL_RENDERER_ACCELERATED;
	RENDER = SDL_CreateRenderer(WIN, -1, RENDER_FLAG);
	if (!RENDER)
	{
		ft_putstr("\033[1;31mError creating renderer\n\e[m");
		SDL_DestroyWindow(WIN);
		SDL_Quit();
		exit(1);
	}
	SCREEN_TEX = SDL_CreateTexture(RENDER, TEX_IN, W, H);
	if (!SCREEN_TEX)
	{
		ft_putstr("\033[1;31mError creating texture\n\e[m");
		SDL_DestroyTexture(SCREEN_TEX);
		SDL_DestroyWindow(WIN);
		SDL_Quit();
		exit(1);
	}
}

void			initialization(t_pool *pool)
{
	part_one(pool);
	part_two(pool);
}
