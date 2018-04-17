/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 13:13:16 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/15 13:13:18 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	init_textures(t_pool *pool)
{
	make_textures(pool->textures[0], "./pics/walls/redbrick.png");			// 1
	make_textures(pool->textures[1], "./pics/walls/multibrick.png");		// 2
	make_textures(pool->textures[2], "./pics/walls/greystone.png");			// 3
	make_textures(pool->textures[3], "./pics/walls/door_stone.png");		// 4
	make_textures(pool->textures[4], "./pics/walls/wood.png");				// 5
	make_textures(pool->textures[5], "./pics/walls/bluestone.png");			// 6
	make_textures(pool->textures[6], "./pics/walls/bluestone_v2.png");		// 7
	make_textures(pool->textures[7], "./pics/walls/sandstone.png");			// 8
	make_textures(pool->textures[8], "./pics/walls/blue_metal_door.png");	// 9
	make_textures(pool->textures[9], "./pics/walls/metal_button.png");		// 10
	make_textures(pool->textures[10], "./pics/walls/metal.png");			// 11
	make_textures(pool->textures[11], "./pics/walls/hitler_pict_wood.png");	// 12
	make_textures(pool->textures[12], "./pics/walls/cross_wood.png");		// 13
	make_textures(pool->textures[13], "./pics/walls/eagle.png");			// 14
	make_textures(pool->textures[14], "./pics/walls/sws_redbrick.png");		// 15
	make_textures(pool->textures[15], "./pics/walls/hitler_pict.png");		// 16
	make_textures(pool->textures[16], "./pics/walls/swas_flag.png");		// 17
	make_textures(pool->textures[17], "./pics/walls/eagle_pict.png");		// 18
	make_textures(pool->textures[18], "./pics/walls/mozaik_hitler.png");	// 19
	make_textures(pool->textures[19], "./pics/walls/hitler.png");			// 20
	make_textures(pool->textures[20], "./pics/walls/eagle_w_swas.png");		// 21
	make_textures(pool->textures[21], "./pics/walls/swas_flag_sandsquare.png");		// 22
}
