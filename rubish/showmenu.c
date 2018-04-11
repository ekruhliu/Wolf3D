/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showmenu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 10:53:47 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/06 10:53:48 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	showmenu(SDL_Surface* screen, TTF_Font* font)
{
	Uint32 time;
	int x;
	int y;
	const int num_menu = 2;
	const char* label[num_menu];
	label[0] = "Start Game\0";
	label[1] = "Exit\0";
	SDL_Surface* menu[num_menu];
	int selected[num_menu] = {0,0};
	SDL_Color color[2];
	color[0] = {255,255,255};
	color[1] = {255,0,0};

	menu[0] = TTF_RenderText_Solid(font, label[0], color[0]);
	menu[1] = TTF_RenderText_Solid(font, label[1], color[0]);

	SDL_Rect pos[num_menu];
	pos[0].x = screen->clip_rect.w/2 - menu[0]->clip_rect.w/2;
	pos[0].y = screen->clip_rect.h/2 - menu[0]->clip_rect.h/2;
	pos[1].x = screen->clip_rect.w/2 - menu[0]->clip_rect.w/2;
	pos[1].y = screen->clip_rect.h/2 - menu[0]->clip_rect.h/2;

	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0, 0, 240));
	SDL_Event event;

	SDL_bool		done;
	done = SDL_FALSE;
	while (!done)
	{
		time = SDL_GetTicks();
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				SDL_FreeSurface(menu[0]);
				SDL_FreeSurface(menu[1]);
				done = SDL_TRUE;
				return (1);
			}
			if (event.type == SDL_MOUSEMOTION)
			{
				x = event.motion.x;
				y = event.motion.y;
				int i = 0;
				while (i < num_menu)
				{
					if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
					{
						if (!selected[i])
						{
							selected[i] = 1;
							SDL_FreeSurface(menu[i]);
							menu[i] = TTF_RenderText_Solid(font, label[i], color[1]);
						}
					}
					else
					{
						if (!selected[i])
						{
							selected[i] = 0;
							SDL_FreeSurface(menu[i]);
							menu[i] = TTF_RenderText_Solid(font, label[i], color[0]);
						}
					}
					i++;
				}
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				x = event.button.x;
				y = event.button.y;
				int i = 0;
				while (i < num_menu)
				{
					if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
					{
						SDL_FreeSurface(menu[0]);
						SDL_FreeSurface(menu[1]);
						done = SDL_TRUE;
						return (1);
					}
					i++;
				}
				break;
			}
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					return (0);
					// done = SDL_TRUE;
			}
			SDL_FreeSurface(menu[0]);
			SDL_FreeSurface(menu[1]);
			done = SDL_TRUE;
			return (1);
			SDL_Flip(screen);
			if (1000/30>(SDL_GetTicks() - time))
				SDL_Delay(1000/30>(SDL_GetTicks() - time));
		}
	}
}
