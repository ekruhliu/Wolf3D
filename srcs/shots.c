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

static	void	part_one(t_pool *pool)
{
	if (EVENT_TYPE == SDL_KEYDOWN && SPACE && WEAPON->act_knife == 1)
	{
		WEAPON->act_knife = 0;
		WEAPON->knife_attack = 1;
	}
	if (EVENT_TYPE == SDL_KEYUP && SPACE && WEAPON->knife_attack == 1)
	{
		WEAPON->act_knife = 1;
		WEAPON->knife_attack = 0;
	}
	if (EVENT_TYPE == SDL_KEYDOWN && SPACE && WEAPON->act_pistol == 1)
	{
		system("afplay ./music/shoots/shoot_pistol.mp3 &");
		WEAPON->act_pistol = 0;
		WEAPON->pistol_attack = 1;
	}
	if (EVENT_TYPE == SDL_KEYUP && SPACE && WEAPON->pistol_attack == 1)
	{
		WEAPON->act_pistol = 1;
		WEAPON->pistol_attack = 0;
	}
}

static	void	part_two(t_pool *pool)
{
	if (EVENT_TYPE == SDL_KEYDOWN && SPACE && WEAPON->act_mp40 == 1)
	{
		system("afplay ./music/shoots/mp40_shoot.mp3 &");
		WEAPON->act_mp40 = 0;
		WEAPON->mp40_attack = 1;
	}
	if (EVENT_TYPE == SDL_KEYUP && SPACE && WEAPON->mp40_attack == 1)
	{
		system("pkill pgrep afplay");
		WEAPON->act_mp40 = 1;
		WEAPON->mp40_attack = 0;
	}
	if (EVENT_TYPE == SDL_KEYDOWN && SPACE && WEAPON->act_shotgun == 1)
	{
		system("afplay ./music/shoots/shotgun_shoot.mp3 &");
		WEAPON->act_shotgun = 0;
		WEAPON->shotgun_attack = 1;
	}
	if (EVENT_TYPE == SDL_KEYUP && SPACE && WEAPON->shotgun_attack == 1)
	{
		WEAPON->act_shotgun = 1;
		WEAPON->shotgun_attack = 0;
	}
}

static	void	part_three(t_pool *pool)
{
	if (EVENT_TYPE == SDL_KEYDOWN && SPACE && WEAPON->act_chainsaw == 1)
	{
		system("afplay ./music/shoots/chainsaw_shoot.mp3 &");
		WEAPON->act_chainsaw = 0;
		WEAPON->chainsaw_attack = 1;
	}
	if (EVENT_TYPE == SDL_KEYUP && SPACE && WEAPON->chainsaw_attack == 1)
	{
		system("pkill pgrep afplay");
		WEAPON->act_chainsaw = 1;
		WEAPON->chainsaw_attack = 0;
	}
}

void			shots(t_pool *pool)
{
	part_one(pool);
	part_two(pool);
	part_three(pool);
}
