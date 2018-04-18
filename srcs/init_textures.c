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
	make_textures(pool, TEXTURE[0], "./pics/walls/redbrick.png");
	make_textures(pool, TEXTURE[1], "./pics/walls/multibrick.png");
	make_textures(pool, TEXTURE[2], "./pics/walls/greystone.png");
	make_textures(pool, TEXTURE[3], "./pics/walls/door_stone.png");
	make_textures(pool, TEXTURE[4], "./pics/walls/wood.png");
	make_textures(pool, TEXTURE[5], "./pics/walls/bluestone.png");
	make_textures(pool, TEXTURE[6], "./pics/walls/bluestone_v2.png");
	make_textures(pool, TEXTURE[7], "./pics/walls/sandstone.png");
	make_textures(pool, TEXTURE[8], "./pics/walls/blue_metal_door.png");
	make_textures(pool, TEXTURE[9], "./pics/walls/metal_button.png");
	make_textures(pool, TEXTURE[10], "./pics/walls/metal.png");
	make_textures(pool, TEXTURE[11], "./pics/walls/hitler_pict_wood.png");
	make_textures(pool, TEXTURE[12], "./pics/walls/cross_wood.png");
	make_textures(pool, TEXTURE[13], "./pics/walls/eagle.png");
	make_textures(pool, TEXTURE[14], "./pics/walls/sws_redbrick.png");
	make_textures(pool, TEXTURE[15], "./pics/walls/hitler_pict.png");
	make_textures(pool, TEXTURE[16], "./pics/walls/swas_flag.png");
	make_textures(pool, TEXTURE[17], "./pics/walls/eagle_pict.png");
	make_textures(pool, TEXTURE[18], "./pics/walls/mozaik_hitler.png");
	make_textures(pool, TEXTURE[19], "./pics/walls/hitler.png");
	make_textures(pool, TEXTURE[20], "./pics/walls/eagle_w_swas.png");
	make_textures(pool, TEXTURE[21], "./pics/walls/swas_flag_sandsquare.png");
}
