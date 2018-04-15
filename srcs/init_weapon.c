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
	pool->weapon->Spist.x = 0;
	pool->weapon->Spist.y = 0;
	pool->weapon->Spist.w = 1024;
	pool->weapon->Spist.h = 768;
	pool->weapon->Dpist.x = 350;
	pool->weapon->Dpist.y = 470;
	pool->weapon->Dpist.w = 320;
	pool->weapon->Dpist.h = 300;
	pool->weapon->Spist_att.x = 0;
	pool->weapon->Spist_att.y = 0;
	pool->weapon->Spist_att.w = 1024;
	pool->weapon->Spist_att.h = 768;
	pool->weapon->Dpist_att.x = 305;
	pool->weapon->Dpist_att.y = 325;
	pool->weapon->Dpist_att.w = 420;
	pool->weapon->Dpist_att.h = 480;
}

static	void	var_knife(t_pool *pool)
{
	pool->weapon->Sknife.x = 0;
	pool->weapon->Sknife.y = 0;
	pool->weapon->Sknife.w = 1024;
	pool->weapon->Sknife.h = 768;
	pool->weapon->Dknife.x = 490;
	pool->weapon->Dknife.y = 470;
	pool->weapon->Dknife.w = 320;
	pool->weapon->Dknife.h = 300;
}

static	void	var_mp40(t_pool *pool)
{
	pool->weapon->Smp40.x = 0;
	pool->weapon->Smp40.y = 0;
	pool->weapon->Smp40.w = 1024;
	pool->weapon->Smp40.h = 768;
	pool->weapon->Dmp40.x = 252;
	pool->weapon->Dmp40.y = 315;
	pool->weapon->Dmp40.w = 435;
	pool->weapon->Dmp40.h = 465;
	pool->weapon->Smp40_att.x = 0;
	pool->weapon->Smp40_att.y = 0;
	pool->weapon->Smp40_att.w = 1024;
	pool->weapon->Smp40_att.h = 768;
	pool->weapon->Dmp40_att.x = 260;
	pool->weapon->Dmp40_att.y = 292;
	pool->weapon->Dmp40_att.w = 420;
	pool->weapon->Dmp40_att.h = 480;
}

static	void	var_shotgun(t_pool *pool)
{
	pool->weapon->Sshotgun.x = 0;
	pool->weapon->Sshotgun.y = 0;
	pool->weapon->Sshotgun.w = 1024;
	pool->weapon->Sshotgun.h = 768;
	pool->weapon->Dshotgun.x = 315;
	pool->weapon->Dshotgun.y = 400;
	pool->weapon->Dshotgun.w = 350;
	pool->weapon->Dshotgun.h = 385;
}

void	init_weapon(t_pool *pool)
{
	pool->weapon->pistol_img = IMG_Load("./pics/weapon/pistol.png");
	pool->weapon->knife_img = IMG_Load("./pics/weapon/knife.png");
	pool->weapon->knife_attack_img = IMG_Load("./pics/weapon/knife_2.png");
	pool->weapon->pistol_attack_img = IMG_Load("./pics/weapon/pistol_2.png");
	pool->weapon->mp40_img = IMG_Load("./pics/weapon/mp40.png");
	pool->weapon->mp40_attack_img = IMG_Load("./pics/weapon/mp40_2.png");
	pool->weapon->shotgun_img = IMG_Load("./pics/weapon/shotgun.png");
	pool->weapon->shotgun_attack_img = IMG_Load("./pics/weapon/shotgun_2.png");
	pool->weapon->pistol = TEX_FMR_SRF(pool->sdl->rend, pool->weapon->pistol_img);
	pool->weapon->knife = TEX_FMR_SRF(pool->sdl->rend, pool->weapon->knife_img);
	pool->weapon->knife_attack_tex = TEX_FMR_SRF(pool->sdl->rend, pool->weapon->knife_attack_img);
	pool->weapon->pistol_attack_tex = TEX_FMR_SRF(pool->sdl->rend, pool->weapon->pistol_attack_img);
	pool->weapon->mp40 = TEX_FMR_SRF(pool->sdl->rend, pool->weapon->mp40_img);
	pool->weapon->mp40_attack_tex = TEX_FMR_SRF(pool->sdl->rend, pool->weapon->mp40_attack_img);
	pool->weapon->shotgun = TEX_FMR_SRF(pool->sdl->rend, pool->weapon->shotgun_img);
	pool->weapon->shotgun_attack_tex = TEX_FMR_SRF(pool->sdl->rend, pool->weapon->shotgun_attack_img);
	var_pist(pool);
	var_knife(pool);
	var_mp40(pool);
	var_shotgun(pool);
}
