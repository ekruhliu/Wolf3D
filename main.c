/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:10:20 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/02 15:10:21 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

#define POINTS_COUNT 4

static SDL_Point	points[POINTS_COUNT] = 
{
	{320, 200},
	{300, 240},
	{340, 240},
	{320, 200}
};

int	main(int argc, char **argv)
{
	if (argc > 1 && argv[1])
	{
		SDL_Window*		win;
		Uint32			render_flags;
		SDL_Renderer*	rend;
		SDL_bool		done;

		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			ft_putstr("\033[1;31mError initializing SDL\n\e[m");
			return (1);
		}
		win = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 1200, 0);
		if (!win)
		{
			ft_putstr("\033[1;31mError creating window\n\e[m");
			SDL_Quit();
			return (1);
		}
		render_flags = SDL_RENDERER_ACCELERATED;
		rend = SDL_CreateRenderer(win, -1, render_flags);
		if (!rend)
		{
			ft_putstr("\033[1;31mError creating renderer\n\e[m");
			SDL_DestroyWindow(win);
			SDL_Quit();
			return (1);
		}
		done = SDL_FALSE;
		while (!done)
		{
			SDL_Event	event;

			SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
			SDL_RenderClear(rend);
			SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
			SDL_RenderDrawLines(rend, points, POINTS_COUNT);
			SDL_RenderPresent(rend);
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					done = SDL_TRUE;
				if (event.type)
				{
					if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
						done = SDL_TRUE;
					if (event.type == SDL_QUIT)
					done = SDL_TRUE;
				}
			}
		}
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
	}
	else
		usage();
}
