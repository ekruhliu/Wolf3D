/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:45:10 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/24 19:45:11 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static	void	create_surface_and_pixels(t_pool *pool)
{
	BAR->mini_map_img = CREATE_SURF(0, LEN_X, LEN_Y, 32, 0, 0, 0, 0);
	BAR->mini_map = BAR->mini_map_img->pixels;
}

static	void	init_minimap_and_draw(t_pool *pool)
{
	BAR->mini_map_tex = TEX_FMR_SRF(RENDER, BAR->mini_map_img);
	BAR->d_map.x = 814;
	BAR->d_map.y = 558;
	BAR->d_map.w = 210;
	BAR->d_map.h = 210;
	REND_CPY(RENDER, BAR->mini_map_tex, NULL, &BAR->d_map);
}

void			make_minimap(t_pool *pool)
{
	int y;
	int x;
	int i;

	y = 0;
	i = 0;
	create_surface_and_pixels(pool);
	while (y < LEN_Y)
	{
		x = 0;
		while (x < LEN_X)
		{
			MAP[y][x] == 0 ? BAR->MM[i] = 0x000000 : (0);
			MAP[y][x] >= 1 && MAP[y][x] != 9 ? BAR->MM[i] = 0x003080 : (0);
			MAP[y][x] == 9 ? BAR->MM[i] = 0x00FF00 : (0);
			if (y == (int)pool->pos_x && x == (int)pool->pos_y)
				BAR->MM[i] = 0xFF0000;
			x++;
			i++;
		}
		y++;
	}
	init_minimap_and_draw(pool);
}
