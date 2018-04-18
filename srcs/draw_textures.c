/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:52:38 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/11 14:52:48 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void			draw_textures(t_pool *pool, int x)
{
	Y = DRAW_START;
	if (SIDE == 0)
		WALL_X = POS_Y + (RAY_LONG_VECTOR - 0.01) * RAY_VECTOR_Y;
	else
		WALL_X = POS_X + (RAY_LONG_VECTOR - 0.01) * RAY_VECTOR_X;
	WALL_X -= floor(WALL_X);
	TEX_X = (int)(WALL_X * (double)TEXTURE_W);
	if ((SIDE == 0 && RAY_VECTOR_X > 0) || (SIDE == 1 && RAY_VECTOR_Y < 0))
		TEX_X = TEXTURE_W - TEX_X - 1;
	while (Y < DRAW_END)
	{
		pool->draw_tex->d = Y * 256 - H * 128 + LINE_HEIGHT * 128;
		TEX_Y = ((pool->draw_tex->d * TEXTURE_H) / LINE_HEIGHT / 256);
		POSITION = TEXTURE_H * TEX_Y + TEX_X;
		TEXT_NUM = MAP[MAP_X][MAP_Y] - 1;
		TEXT_ARR[x][Y] = pool->textures[TEXT_NUM][POSITION];
		if (SIDE == 1)
			TEXT_ARR[x][Y] = (TEXT_ARR[x][Y] >> 1) & 8355711;
		if (pool->mp == 1)
			n_s_e_w(pool, x);
		Y++;
	}
}

static	void	check_side(t_pool *pool)
{
	if (SIDE == 0 && RAY_VECTOR_X > 0)
	{
		FLOOR_X_WALL = MAP_X;
		FLOOR_Y_WALL = MAP_Y + WALL_X;
	}
	else if (SIDE == 0 && RAY_VECTOR_X < 0)
	{
		FLOOR_X_WALL = MAP_X + 1.0;
		FLOOR_Y_WALL = MAP_Y + WALL_X;
	}
	else if (SIDE == 1 && RAY_VECTOR_Y > 0)
	{
		FLOOR_X_WALL = MAP_X + WALL_X;
		FLOOR_Y_WALL = MAP_Y;
	}
	else
	{
		FLOOR_X_WALL = MAP_X + WALL_X;
		FLOOR_Y_WALL = MAP_Y + 1.0;
	}
}

void			draw_floor_and_ceiling(t_pool *pool, int x)
{
	Y = DRAW_END + 1;
	check_side(pool);
	DIST_WALL = RAY_LONG_VECTOR - 0.01;
	DIST_PLAYER = 0.0;
	if (DRAW_END < 0)
		DRAW_END = H;
	while (Y < H)
	{
		CURR_DIST = H / (2.0 * Y - H);
		WEIGHT = (CURR_DIST - DIST_PLAYER) / (DIST_WALL - DIST_PLAYER);
		CURR_FLOOR_X = WEIGHT * FLOOR_X_WALL + (1.0 - WEIGHT) * POS_X;
		CURR_FLOOR_Y = WEIGHT * FLOOR_Y_WALL + (1.0 - WEIGHT) * POS_Y;
		FLOOR_TEX_X = (int)(CURR_FLOOR_X * TEXTURE_W) % TEXTURE_W;
		FLOOR_TEX_Y = (int)(CURR_FLOOR_Y * TEXTURE_W) % TEXTURE_W;
		TEXT_ARR[x][Y] = (pool->textures[2][FLOOR_POS] >> 1) & 8355711;
		TEXT_ARR[x][H - Y] = pool->textures[2][FLOOR_POS];
		Y++;
	}
}
