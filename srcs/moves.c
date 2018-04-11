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
	if (pool->map[(int)(pool->pos_x + pool->vector_x * pool->move_speed)][(int)(pool->pos_y)] == 0)
		pool->pos_x += pool->vector_x * pool->move_speed;
	if (pool->map[(int)(pool->pos_x)][(int)(pool->pos_y + pool->vector_y * pool->move_speed)] == 0)
		pool->pos_y += pool->vector_y * pool->move_speed;
}

void	go_back(t_pool *pool)
{
	if (pool->map[(int)(pool->pos_x - pool->vector_x * pool->move_speed)][(int)pool->pos_y] == 0)
		pool->pos_x -= pool->vector_x * pool->move_speed;
	if (pool->map[(int)(pool->pos_x)][(int)(pool->pos_y - pool->vector_y * pool->move_speed)] == 0)
		pool->pos_y -= pool->vector_y * pool->move_speed;
}

void	turn_right(t_pool *pool)
{
	double	old_vector_x;
	double	old_plane_x;

	old_vector_x = pool->vector_x;
	pool->vector_x = pool->vector_x * cos(-pool->rot_speed) - pool->vector_y * sin(-pool->rot_speed);
	pool->vector_y = old_vector_x * sin(-pool->rot_speed) + pool->vector_y * cos(-pool->rot_speed);
	old_plane_x = pool->plane_x;
	pool->plane_x = pool->plane_x * cos(-pool->rot_speed) - pool->plane_y * sin(-pool->rot_speed);
	pool->plane_y = old_plane_x * sin(-pool->rot_speed) + pool->plane_y * cos(-pool->rot_speed);
}

void	turn_left(t_pool *pool)
{
	double	old_vector_x;
	double	old_plane_x;

	old_vector_x = pool->vector_x;
	pool->vector_x = pool->vector_x * cos(pool->rot_speed) - pool->vector_y * sin(pool->rot_speed);
	pool->vector_y = old_vector_x * sin(pool->rot_speed) + pool->vector_y * cos(pool->rot_speed);
	old_plane_x = pool->plane_x;
	pool->plane_x = pool->plane_x * cos(pool->rot_speed) - pool->plane_y * sin(pool->rot_speed);
	pool->plane_y = old_plane_x * sin(pool->rot_speed) + pool->plane_y * cos(pool->rot_speed);
}
