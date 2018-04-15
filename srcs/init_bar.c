/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:45:00 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/15 12:45:02 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static	void	else_bar(t_pool *pool)
{
	pool->bar->Sface.x = 0;
	pool->bar->Sface.y = 0;
	pool->bar->Sface.w = 1024;
	pool->bar->Sface.h = 768;
	pool->bar->Shealth.x = 0;
	pool->bar->Shealth.y = 0;
	pool->bar->Shealth.w = 1024;
	pool->bar->Shealth.h = 768;
	pool->bar->Sarms.x = 0;
	pool->bar->Sarms.y = 0;
	pool->bar->Sarms.w = 1024;
	pool->bar->Sarms.h = 768;
	pool->bar->Dface.x = 0;
	pool->bar->Dface.y = 518;
	pool->bar->Dface.w = 150;
	pool->bar->Dface.h = 150;
	pool->bar->Dhealth.x = 0;
	pool->bar->Dhealth.y = 668;
	pool->bar->Dhealth.w = 150;
	pool->bar->Dhealth.h = 100;
	pool->bar->Darms.x = 805;
	pool->bar->Darms.y = 518;
	pool->bar->Darms.w = 220;
	pool->bar->Darms.h = 30;
}

void	init_bar(t_pool *pool)
{
	pool->bar->face_img = IMG_Load("./pics/bar/face.png");
	pool->bar->health_img = IMG_Load("./pics/bar/health.png");
	pool->bar->arms_img = IMG_Load("./pics/bar/all_arms.png");
	pool->bar->fuck_img = IMG_Load("./pics/weapon/fuck.png");

	pool->bar->face = TEX_FMR_SRF(pool->sdl->rend, pool->bar->face_img);
	pool->bar->health = TEX_FMR_SRF(pool->sdl->rend, pool->bar->health_img);
	pool->bar->arms = TEX_FMR_SRF(pool->sdl->rend, pool->bar->arms_img);
	pool->bar->fuck = TEX_FMR_SRF(pool->sdl->rend, pool->bar->fuck_img);

	else_bar(pool);
	pool->bar->Sfuck.x = 0;
	pool->bar->Sfuck.y = 0;
	pool->bar->Sfuck.w = 1024;
	pool->bar->Sfuck.h = 768;
	pool->bar->Dfuck.x = 490;
	pool->bar->Dfuck.y = 470;
	pool->bar->Dfuck.w = 260;
	pool->bar->Dfuck.h = 300;
}
