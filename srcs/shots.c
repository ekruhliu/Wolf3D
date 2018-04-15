/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shots.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 13:26:03 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/15 13:26:04 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	shots(t_pool *pool)
{
	if (pool->sdl->event.type == SDL_KEYDOWN && SPACE && pool->weapon->act_knife == 1)
	{
		pool->weapon->act_knife = 0;
		pool->weapon->knife_attack = 1;
	}
	if (pool->sdl->event.type == SDL_KEYUP && SPACE && pool->weapon->knife_attack == 1)
	{
		pool->weapon->act_knife = 1;
		pool->weapon->knife_attack = 0;
	}
	if (pool->sdl->event.type == SDL_KEYDOWN && SPACE && pool->weapon->act_pistol == 1)
	{
		pool->weapon->act_pistol = 0;
		pool->weapon->pistol_attack = 1;
	}
	if (pool->sdl->event.type == SDL_KEYUP && SPACE && pool->weapon->pistol_attack == 1)
	{
		pool->weapon->act_pistol = 1;
		pool->weapon->pistol_attack = 0;
	}
	if (pool->sdl->event.type == SDL_KEYDOWN && SPACE && pool->weapon->act_mp40 == 1)
	{
		pool->weapon->act_mp40 = 0;
		pool->weapon->mp40_attack = 1;
	}
	if (pool->sdl->event.type == SDL_KEYUP && SPACE && pool->weapon->mp40_attack == 1)
	{
		pool->weapon->act_mp40 = 1;
		pool->weapon->mp40_attack = 0;
	}
	if (pool->sdl->event.type == SDL_KEYDOWN && SPACE && pool->weapon->act_shotgun == 1)
	{
		pool->weapon->act_shotgun = 0;
		pool->weapon->shotgun_attack = 1;
	}
	if (pool->sdl->event.type == SDL_KEYUP && SPACE && pool->weapon->shotgun_attack == 1)
	{
		pool->weapon->act_shotgun = 1;
		pool->weapon->shotgun_attack = 0;
	}
}