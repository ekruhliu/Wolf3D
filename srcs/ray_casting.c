/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:42:50 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/11 13:42:51 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void	variables(t_pool *pool, int x)
{
	HIT = 0;
	CAMERA_X = 2 * x / (double)W - 1;
	RAY_VECTOR_X = VECTOR_X + PLANE_X * CAMERA_X;
	RAY_VECTOR_Y = VECTOR_Y + PLANE_Y * CAMERA_X;
	MAP_X = (int)POS_X;
	MAP_Y = (int)POS_Y;
	DELTA_VECTOR_X = fabs(1 / RAY_VECTOR_X);
	DELTA_VECTOR_Y = fabs(1 / RAY_VECTOR_Y);
}

static void	part_one(t_pool *pool)
{
	STEP_X = (RAY_VECTOR_X < 0) ? -1 : 1;
	SIDE_VECTOR_X = (RAY_VECTOR_X < 0) ? (POS_X - MAP_X) * DELTA_VECTOR_X \
	: (MAP_X + 1.0 - POS_X) * DELTA_VECTOR_X;
	STEP_Y = (RAY_VECTOR_Y < 0) ? -1 : 1;
	SIDE_VECTOR_Y = (RAY_VECTOR_Y < 0) ? (POS_Y - MAP_Y) * DELTA_VECTOR_Y \
	: (MAP_Y + 1.0 - POS_Y) * DELTA_VECTOR_Y;
}

static void	part_two(t_pool *pool)
{
	RAY_LONG_VECTOR = (SIDE == 0) ? (MAP_X - POS_X + (1 - STEP_X) / 2) / \
	RAY_VECTOR_X : (MAP_Y - POS_Y + (1 - STEP_Y) / 2) / RAY_VECTOR_Y;
	RAY_LONG_VECTOR += 0.01;
	LINE_HEIGHT = (int)(H / RAY_LONG_VECTOR);
	DRAW_START = -LINE_HEIGHT / 2 + H / 2;
}

static void	part_three(t_pool *pool)
{
	if (DRAW_START < 0)
		DRAW_START = 0;
	DRAW_END = LINE_HEIGHT / 2 + H / 2;
	if (DRAW_END >= H)
		DRAW_END = H - 1;
}

void		ray_casting(t_pool *pool, int x)
{
	variables(pool, x);
	part_one(pool);
	while (HIT == 0)
	{
		if (SIDE_VECTOR_X < SIDE_VECTOR_Y)
		{
			SIDE_VECTOR_X += DELTA_VECTOR_X;
			MAP_X += STEP_X;
			SIDE = 0;
		}
		else
		{
			SIDE_VECTOR_Y += DELTA_VECTOR_Y;
			MAP_Y += STEP_Y;
			SIDE = 1;
		}
		if (MAP[MAP_X][MAP_Y] > 0)
			HIT = 1;
	}
	part_two(pool);
	part_three(pool);
}
