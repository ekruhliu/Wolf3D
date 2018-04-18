/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:32:37 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/11 15:32:47 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	go_ahead(t_pool *pool)
{
	if (MAP[(int)(POS_X + VECTOR_X * MOVE_SPEED)][(int)(POS_Y)] == 0)
		POS_X += VECTOR_X * MOVE_SPEED;
	if (MAP[(int)(POS_X)][(int)(POS_Y + VECTOR_Y * MOVE_SPEED)] == 0)
		POS_Y += VECTOR_Y * MOVE_SPEED;
}

void	go_back(t_pool *pool)
{
	if (MAP[(int)(POS_X - VECTOR_X * MOVE_SPEED)][(int)POS_Y] == 0)
		POS_X -= VECTOR_X * MOVE_SPEED;
	if (MAP[(int)(POS_X)][(int)(POS_Y - VECTOR_Y * MOVE_SPEED)] == 0)
		POS_Y -= VECTOR_Y * MOVE_SPEED;
}

void	turn_right(t_pool *pool)
{
	double	old_vector_x;
	double	old_plane_x;

	old_vector_x = VECTOR_X;
	VECTOR_X = VECTOR_X * cos(-ROT_SPEED) - VECTOR_Y * sin(-ROT_SPEED);
	VECTOR_Y = old_vector_x * sin(-ROT_SPEED) + VECTOR_Y * cos(-ROT_SPEED);
	old_plane_x = PLANE_X;
	PLANE_X = PLANE_X * cos(-ROT_SPEED) - PLANE_Y * sin(-ROT_SPEED);
	PLANE_Y = old_plane_x * sin(-ROT_SPEED) + PLANE_Y * cos(-ROT_SPEED);
}

void	turn_left(t_pool *pool)
{
	double	old_vector_x;
	double	old_plane_x;

	old_vector_x = VECTOR_X;
	VECTOR_X = VECTOR_X * cos(ROT_SPEED) - VECTOR_Y * sin(ROT_SPEED);
	VECTOR_Y = old_vector_x * sin(ROT_SPEED) + VECTOR_Y * cos(ROT_SPEED);
	old_plane_x = PLANE_X;
	PLANE_X = PLANE_X * cos(ROT_SPEED) - PLANE_Y * sin(ROT_SPEED);
	PLANE_Y = old_plane_x * sin(ROT_SPEED) + PLANE_Y * cos(ROT_SPEED);
}
