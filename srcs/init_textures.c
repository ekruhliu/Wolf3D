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
	make_textures(pool, TEXTURE[0], "./img/walls/redbrick.png");
	make_textures(pool, TEXTURE[1], "./img/walls/multibrick.png");
	make_textures(pool, TEXTURE[2], "./img/walls/greystone.png");
	make_textures(pool, TEXTURE[3], "./img/walls/door_stone.png");
	make_textures(pool, TEXTURE[4], "./img/walls/wood.png");
	make_textures(pool, TEXTURE[5], "./img/walls/bluestone.png");
	make_textures(pool, TEXTURE[6], "./img/walls/bluestone_v2.png");
	make_textures(pool, TEXTURE[7], "./img/walls/sandstone.png");
	make_textures(pool, TEXTURE[8], "./img/walls/blue_metal_door.png");
	make_textures(pool, TEXTURE[9], "./img/walls/metal_button.png");
	make_textures(pool, TEXTURE[10], "./img/walls/metal.png");
	make_textures(pool, TEXTURE[11], "./img/walls/hitler_pict_wood.png");
	make_textures(pool, TEXTURE[12], "./img/walls/cross_wood.png");
	make_textures(pool, TEXTURE[13], "./img/walls/eagle.png");
	make_textures(pool, TEXTURE[14], "./img/walls/sws_redbrick.png");
	make_textures(pool, TEXTURE[15], "./img/walls/hitler_pict.png");
	make_textures(pool, TEXTURE[16], "./img/walls/swas_flag.png");
	make_textures(pool, TEXTURE[17], "./img/walls/eagle_pict.png");
	make_textures(pool, TEXTURE[18], "./img/walls/mozaik_hitler.png");
	make_textures(pool, TEXTURE[19], "./img/walls/hitler.png");
	make_textures(pool, TEXTURE[20], "./img/walls/eagle_w_swas.png");
	make_textures(pool, TEXTURE[21], "./img/walls/swas_flag_sandsquare.png");
}
