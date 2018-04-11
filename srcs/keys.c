/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:51:45 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/11 16:51:46 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	keys(t_pool *pool)	
{
	pool->sdl->keyboard_state = SDL_GetKeyboardState(NULL);
	SDL_PollEvent(&pool->sdl->event);
	pool->sdl->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE ? pool->sdl->done = SDL_TRUE : SDL_FALSE;
	if (pool->sdl->event.type == SDL_QUIT)
			pool->sdl->done = SDL_TRUE;
	if (pool->sdl->keyboard_state[SDL_SCANCODE_UP] || pool->sdl->keyboard_state[SDL_SCANCODE_W])
		go_ahead(pool);
	if (pool->sdl->keyboard_state[SDL_SCANCODE_DOWN] || pool->sdl->keyboard_state[SDL_SCANCODE_S])
		go_back(pool);
	if (pool->sdl->keyboard_state[SDL_SCANCODE_RIGHT] || pool->sdl->keyboard_state[SDL_SCANCODE_D])
		turn_right(pool);
	if (pool->sdl->keyboard_state[SDL_SCANCODE_LEFT] || pool->sdl->keyboard_state[SDL_SCANCODE_A])
		turn_left(pool);
	if (pool->sdl->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		pool->sdl->done = SDL_TRUE;
}
