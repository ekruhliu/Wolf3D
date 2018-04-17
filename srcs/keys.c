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

static	void	moves(t_pool *pool)
{
	if (pool->sdl->keyboard_state[SDL_SCANCODE_UP] || pool->sdl->keyboard_state[SDL_SCANCODE_W])
		go_ahead(pool);
	if (pool->sdl->keyboard_state[SDL_SCANCODE_DOWN] || pool->sdl->keyboard_state[SDL_SCANCODE_S])
		go_back(pool);
	if (pool->sdl->keyboard_state[SDL_SCANCODE_RIGHT] || pool->sdl->keyboard_state[SDL_SCANCODE_D])
		turn_right(pool);
	if (pool->sdl->keyboard_state[SDL_SCANCODE_LEFT] || pool->sdl->keyboard_state[SDL_SCANCODE_A])
		turn_left(pool);
}

static	void	take_weapon(t_pool *pool)
{
	if (pool->sdl->keyboard_state[SDL_SCANCODE_1] && (pool->check = check_attack(pool)) == 0)
	{
		clear_weapon(pool);
		pool->weapon->act_knife = 1;
	}
	if (pool->sdl->keyboard_state[SDL_SCANCODE_2] && (pool->check = check_attack(pool)) == 0)
	{
		clear_weapon(pool);
		pool->weapon->act_pistol = 1;
	}
	if (pool->sdl->keyboard_state[SDL_SCANCODE_3] && (pool->check = check_attack(pool)) == 0)
	{
		clear_weapon(pool);
		pool->weapon->act_mp40 = 1;
	}
	if (pool->sdl->keyboard_state[SDL_SCANCODE_4] && (pool->check = check_attack(pool)) == 0)
	{
		clear_weapon(pool);
		pool->weapon->act_shotgun = 1;
	}
}

void	keys(t_pool *pool)	
{
	pool->sdl->keyboard_state = SDL_GetKeyboardState(NULL);
	SDL_PollEvent(&pool->sdl->event);
	pool->sdl->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE ? pool->sdl->done = SDL_TRUE : SDL_FALSE;
	if (pool->sdl->event.type == SDL_QUIT)
			pool->sdl->done = SDL_TRUE;
	moves(pool);
	if (pool->sdl->event.type == SDL_KEYDOWN && pool->sdl->event.key.keysym.scancode == SDL_SCANCODE_F && (pool->check = check_attack(pool)) == 0)
	{
		clear_weapon(pool);
		pool->bar->act_fuck = 1;
	}
	take_weapon(pool);
	if (pool->sdl->event.type == SDL_KEYUP && pool->sdl->event.key.keysym.scancode == SDL_SCANCODE_F)
		pool->bar->act_fuck = 0;
	if (pool->sdl->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		pool->sdl->done = SDL_TRUE;
	if (pool->sdl->event.type == SDL_KEYDOWN && pool->sdl->event.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
		pool->speed_val = 6.0;
	if (pool->sdl->event.type == SDL_KEYUP && pool->sdl->event.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
		pool->speed_val = 4.0;
	if (pool->map[pool->ray_cast->map_x][pool->ray_cast->map_y] == 9 && pool->sdl->keyboard_state[SDL_SCANCODE_E])
	{
		pool->map[pool->ray_cast->map_x][pool->ray_cast->map_y] = 0;
		pool->doors->blue_door_x = pool->ray_cast->map_y;
		pool->doors->blue_door_y = pool->ray_cast->map_x;
		pool->doors->time_door = time(NULL) + 4;
	}
	if (pool->map[pool->ray_cast->map_x][pool->ray_cast->map_y] == 2 && pool->sdl->keyboard_state[SDL_SCANCODE_E])
		pool->map[pool->ray_cast->map_x][pool->ray_cast->map_y] = 0;
	if (pool->map[pool->ray_cast->map_x][pool->ray_cast->map_y] == 4 && pool->sdl->keyboard_state[SDL_SCANCODE_E])
		pool->map[pool->ray_cast->map_x][pool->ray_cast->map_y] = 0;
	if (pool->map[pool->ray_cast->map_x][pool->ray_cast->map_y] == 7 && pool->sdl->keyboard_state[SDL_SCANCODE_E])
		pool->map[pool->ray_cast->map_x][pool->ray_cast->map_y] = 0;
	if (pool->map[pool->ray_cast->map_x][pool->ray_cast->map_y] == 18 && pool->sdl->keyboard_state[SDL_SCANCODE_E])
		pool->map[pool->ray_cast->map_x][pool->ray_cast->map_y] = 0;
	shots(pool);
}
