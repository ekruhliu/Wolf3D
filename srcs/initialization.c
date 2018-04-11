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

void	initialization(t_pool *pool)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		ft_putstr("\033[1;31mError initializing SDL\n\e[m");
		exit(1);
	}
	pool->sdl->win = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W, H, SDL_WINDOW_FULLSCREEN);
	if (!pool->sdl->win)
	{
		ft_putstr("\033[1;31mError creating window\n\e[m");
		SDL_Quit();
		exit(1);
	}
	pool->sdl->render_flags = SDL_RENDERER_ACCELERATED;
	pool->sdl->rend = SDL_CreateRenderer(pool->sdl->win, -1, pool->sdl->render_flags);
	if (!pool->sdl->rend)
	{
		ft_putstr("\033[1;31mError creating renderer\n\e[m");
		SDL_DestroyWindow(pool->sdl->win);
		SDL_Quit();
		exit(1);
	}
	pool->sdl->screen_tex = SDL_CreateTexture(pool->sdl->rend, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, W, H);
	if(!pool->sdl->screen_tex)
	{
		ft_putstr("\033[1;31mError creating texture\n\e[m");
		SDL_DestroyTexture(pool->sdl->screen_tex);
		SDL_DestroyWindow(pool->sdl->win);
		SDL_Quit();
		exit(1);
	}
}
