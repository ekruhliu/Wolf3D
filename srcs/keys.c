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
	KEY_SCANCODE == SDL_SCANCODE_ESCAPE ? DONE = SDL_TRUE : SDL_FALSE;
	if (EVENT_TYPE == SDL_QUIT)
		DONE = SDL_TRUE;
	if (KEY_STATE[SDL_SCANCODE_UP] || KEY_STATE[SDL_SCANCODE_W])
		go_ahead(pool);
	if (KEY_STATE[SDL_SCANCODE_DOWN] || KEY_STATE[SDL_SCANCODE_S])
		go_back(pool);
	if (KEY_STATE[SDL_SCANCODE_RIGHT] || KEY_STATE[SDL_SCANCODE_D])
		turn_right(pool);
	if (KEY_STATE[SDL_SCANCODE_LEFT] || KEY_STATE[SDL_SCANCODE_A])
		turn_left(pool);
}

static	void	take_weapon(t_pool *pool)
{
	if (KEY_STATE[SDL_SCANCODE_1] && (CHECK))
	{
		clear_weapon(pool);
		pool->weapon->act_knife = 1;
	}
	if (KEY_STATE[SDL_SCANCODE_2] && (CHECK))
	{
		clear_weapon(pool);
		pool->weapon->act_pistol = 1;
	}
	if (KEY_STATE[SDL_SCANCODE_3] && (CHECK))
	{
		clear_weapon(pool);
		pool->weapon->act_mp40 = 1;
	}
	if (KEY_STATE[SDL_SCANCODE_4] && (CHECK))
	{
		clear_weapon(pool);
		pool->weapon->act_shotgun = 1;
	}
	if (KEY_STATE[SDL_SCANCODE_5] && (CHECK))
	{
		clear_weapon(pool);
		pool->weapon->act_chainsaw = 1;
	}
}

static	void	open_doors(t_pool *pool)
{
	if (pool->map[MAP_X][MAP_Y] == 9 && KEY_STATE[SDL_SCANCODE_E] && DOOR == 0)
	{
		DOOR = 1;
		pool->map[MAP_X][MAP_Y] = 0;
		pool->doors->blue_door_x = MAP_Y;
		pool->doors->blue_door_y = MAP_X;
		pool->doors->time_door = time(NULL) + 2;
	}
	if (pool->mp == 0)
	{
		if (pool->map[MAP_X][MAP_Y] == 2 && KEY_STATE[SDL_SCANCODE_E])
			pool->map[MAP_X][MAP_Y] = 0;
		if (pool->map[MAP_X][MAP_Y] == 4 && KEY_STATE[SDL_SCANCODE_E])
			pool->map[MAP_X][MAP_Y] = 0;
		if (pool->map[MAP_X][MAP_Y] == 7 && KEY_STATE[SDL_SCANCODE_E])
			pool->map[MAP_X][MAP_Y] = 0;
		if (pool->map[MAP_X][MAP_Y] == 18 && KEY_STATE[SDL_SCANCODE_E])
			pool->map[MAP_X][MAP_Y] = 0;
	}
}

void			keys(t_pool *pool)
{
	KEY_STATE = SDL_GetKeyboardState(NULL);
	SDL_PollEvent(&pool->sdl->event);
	moves(pool);
	if (EVENT_TYPE == SDL_KEYDOWN && KEY_SCANCODE == SDL_SCANCODE_F && (CHECK))
	{
		clear_weapon(pool);
		system("afplay ./music/fuck.mp3 &");
		pool->bar->act_fuck = 1;
	}
	take_weapon(pool);
	if (EVENT_TYPE == SDL_KEYUP && KEY_SCANCODE == SDL_SCANCODE_F)
	{
		system("pkill pgrep afplay");
		pool->bar->act_fuck = 0;
	}
	if (KEY_SCANCODE == SDL_SCANCODE_ESCAPE)
		DONE = SDL_TRUE;
	if (EVENT_TYPE == SDL_KEYDOWN && KEY_SCANCODE == SDL_SCANCODE_LSHIFT)
		pool->speed_val = 6.0;
	if (EVENT_TYPE == SDL_KEYUP && KEY_SCANCODE == SDL_SCANCODE_LSHIFT)
		pool->speed_val = 4.0;
	open_doors(pool);
	shots(pool);
}
