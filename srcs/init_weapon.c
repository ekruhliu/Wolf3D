/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:53:51 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/15 12:53:52 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static	void	var_pist(t_pool *pool)
{
	WEAPON->dst_pist.x = 350;
	WEAPON->dst_pist.y = 470;
	WEAPON->dst_pist.w = 320;
	WEAPON->dst_pist.h = 300;
	WEAPON->dst_pist_att.x = 305;
	WEAPON->dst_pist_att.y = 325;
	WEAPON->dst_pist_att.w = 420;
	WEAPON->dst_pist_att.h = 480;
}

static	void	var_knife_and_shotgun(t_pool *pool)
{
	WEAPON->dst_knife.x = 490;
	WEAPON->dst_knife.y = 470;
	WEAPON->dst_knife.w = 320;
	WEAPON->dst_knife.h = 300;
	WEAPON->dst_shotgun.x = 315;
	WEAPON->dst_shotgun.y = 400;
	WEAPON->dst_shotgun.w = 350;
	WEAPON->dst_shotgun.h = 385;
}

static	void	var_mp40(t_pool *pool)
{
	WEAPON->dst_mp40.x = 252;
	WEAPON->dst_mp40.y = 315;
	WEAPON->dst_mp40.w = 435;
	WEAPON->dst_mp40.h = 465;
	WEAPON->dst_mp40_att.x = 260;
	WEAPON->dst_mp40_att.y = 292;
	WEAPON->dst_mp40_att.w = 420;
	WEAPON->dst_mp40_att.h = 480;
}

static	void	var_chainsaw(t_pool *pool)
{
	WEAPON->dst_chainsaw.x = 300;
	WEAPON->dst_chainsaw.y = 430;
	WEAPON->dst_chainsaw.w = 380;
	WEAPON->dst_chainsaw.h = 450;
	WEAPON->dst_chainsaw_att.x = 300;
	WEAPON->dst_chainsaw_att.y = 380;
	WEAPON->dst_chainsaw_att.w = 380;
	WEAPON->dst_chainsaw_att.h = 390;
}

void			init_weapon(t_pool *pool)
{
	WEAPON->pistol_img = IMG_Load("./img/weapon/pistol.png");
	WEAPON->knife_img = IMG_Load("./img/weapon/knife.png");
	WEAPON->knife_attack_img = IMG_Load("./img/weapon/knife_2.png");
	WEAPON->pistol_attack_img = IMG_Load("./img/weapon/pistol_2.png");
	WEAPON->mp40_img = IMG_Load("./img/weapon/mp40.png");
	WEAPON->mp40_attack_img = IMG_Load("./img/weapon/mp40_2.png");
	WEAPON->shotgun_img = IMG_Load("./img/weapon/shotgun.png");
	WEAPON->shotgun_attack_img = IMG_Load("./img/weapon/shotgun_2.png");
	WEAPON->chainsaw_img = IMG_Load("./img/weapon/chainsaw.png");
	PISTOL = TEX_FMR_SRF(RENDER, WEAPON->pistol_img);
	KNIFE = TEX_FMR_SRF(RENDER, WEAPON->knife_img);
	KNIFE_ATTACK = TEX_FMR_SRF(RENDER, WEAPON->knife_attack_img);
	PISTOL_ATTACK = TEX_FMR_SRF(RENDER, WEAPON->pistol_attack_img);
	MP40 = TEX_FMR_SRF(RENDER, WEAPON->mp40_img);
	MP40_ATTACK = TEX_FMR_SRF(RENDER, WEAPON->mp40_attack_img);
	SHOTGUN = TEX_FMR_SRF(RENDER, WEAPON->shotgun_img);
	SHOTGUN_ATTACK = TEX_FMR_SRF(RENDER, WEAPON->shotgun_attack_img);
	CHAINSAW = TEX_FMR_SRF(RENDER, WEAPON->chainsaw_img);
	var_pist(pool);
	var_knife_and_shotgun(pool);
	var_mp40(pool);
	var_chainsaw(pool);
}
