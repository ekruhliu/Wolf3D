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
	if (pool->sdl->keyboard_state[SDL_SCANCODE_1])
	{
		pool->weapon->act_pistol = 0;
		pool->weapon->act_knife = 1;
		pool->bar->act_fuck = 0;
	}
	if (pool->sdl->keyboard_state[SDL_SCANCODE_2] && pool->weapon->act_pistol == 0)
	{
		pool->weapon->act_pistol = 1;
		pool->weapon->act_knife = 0;
		pool->bar->act_fuck = 0;
	}
	if (pool->sdl->event.type == SDL_KEYDOWN && pool->sdl->event.key.keysym.scancode == SDL_SCANCODE_F)
	{
		pool->weapon->act_pistol = 0;
		pool->weapon->act_knife = 0;
		pool->bar->act_fuck = 1;
	}
	if (pool->sdl->event.type == SDL_KEYUP && pool->sdl->event.key.keysym.scancode == SDL_SCANCODE_F)
		pool->bar->act_fuck = 0;
	if (pool->sdl->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		pool->sdl->done = SDL_TRUE;
	if (pool->sdl->event.type == SDL_KEYDOWN && pool->sdl->event.key.keysym.scancode == SDL_SCANCODE_SPACE && pool->weapon->act_knife == 1)
	{
		pool->weapon->act_knife = 0;
		pool->weapon->knife_attack = 1;
	}
	if (pool->sdl->event.type == SDL_KEYUP && pool->sdl->event.key.keysym.scancode == SDL_SCANCODE_SPACE && pool->weapon->knife_attack == 1)
	{
		pool->weapon->act_knife = 1;
		pool->weapon->knife_attack = 0;
	}
}
