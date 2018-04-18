/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapon_and_bar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:02:43 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/18 21:02:44 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static	void	part_one(t_pool *pool)
{
	REND_CPY(RENDER, SCREEN_TEX, &SRC_R, &pool->sdl->dst_r);
	REND_CPY(RENDER, BAR->face, &SRC_R, &BAR->dst_face);
	REND_CPY(RENDER, BAR->health, &SRC_R, &BAR->dst_health);
	REND_CPY(RENDER, BAR->arms, &SRC_R, &BAR->dst_arms);
}

static	void	part_two(t_pool *pool)
{
	if (WEAPON->act_knife == 1)
		REND_CPY(RENDER, KNIFE, &SRC_R, &WEAPON->dst_knife);
	if (WEAPON->act_pistol == 1)
		REND_CPY(RENDER, PISTOL, &SRC_R, &WEAPON->dst_pist);
	if (BAR->act_fuck == 1)
		REND_CPY(RENDER, FUCK, &SRC_R, &BAR->dst_fuck);
	if (WEAPON->act_mp40 == 1)
		REND_CPY(RENDER, MP40, &SRC_R, &WEAPON->dst_mp40);
	if (WEAPON->knife_attack == 1)
		REND_CPY(RENDER, KNIFE_ATTACK, &SRC_R, &WEAPON->dst_knife);
	if (WEAPON->pistol_attack == 1)
		REND_CPY(RENDER, PISTOL_ATTACK, &SRC_R, &WEAPON->D_PS_ATT);
}

static	void	part_three(t_pool *pool)
{
	if (WEAPON->mp40_attack == 1)
		REND_CPY(RENDER, MP40_ATTACK, &SRC_R, &WEAPON->D_MP40_ATT);
	if (WEAPON->act_shotgun == 1)
		REND_CPY(RENDER, SHOTGUN, &SRC_R, &WEAPON->D_SGUN);
	if (WEAPON->shotgun_attack == 1)
		REND_CPY(RENDER, SHOTGUN_ATTACK, &SRC_R, &WEAPON->D_SGUN);
	if (WEAPON->act_chainsaw == 1)
		REND_CPY(RENDER, CHAINSAW, &SRC_R, &WEAPON->D_CNS);
	if (WEAPON->chainsaw_attack == 1)
		REND_CPY(RENDER, CHAINSAW, &SRC_R, &WEAPON->D_CNS_ATT);
}

void			draw_weapon_and_bar(t_pool *pool)
{
	part_one(pool);
	part_two(pool);
	part_three(pool);
}
