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
	BAR->dst_face.x = 0;
	BAR->dst_face.y = 518;
	BAR->dst_face.w = 150;
	BAR->dst_face.h = 150;
	BAR->dst_health.x = 0;
	BAR->dst_health.y = 668;
	BAR->dst_health.w = 150;
	BAR->dst_health.h = 100;
	BAR->dst_arms.x = 847;
	BAR->dst_arms.y = 518;
	BAR->dst_arms.w = 220;
	BAR->dst_arms.h = 30;
	BAR->dst_fuck.x = 490;
	BAR->dst_fuck.y = 470;
	BAR->dst_fuck.w = 260;
	BAR->dst_fuck.h = 300;
}

void			init_bar(t_pool *pool)
{
	BAR->face_img = IMG_Load("./pics/bar/face.png");
	BAR->health_img = IMG_Load("./pics/bar/health.png");
	BAR->arms_img = IMG_Load("./pics/bar/all_arms.png");
	BAR->fuck_img = IMG_Load("./pics/weapon/fuck.png");
	BAR->face = TEX_FMR_SRF(pool->sdl->rend, BAR->face_img);
	BAR->health = TEX_FMR_SRF(pool->sdl->rend, BAR->health_img);
	BAR->arms = TEX_FMR_SRF(pool->sdl->rend, BAR->arms_img);
	BAR->fuck = TEX_FMR_SRF(pool->sdl->rend, BAR->fuck_img);
	else_bar(pool);
}
