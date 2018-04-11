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
	pool->ray_cast->hit = 0;
	pool->camera_x = 2 * x / (double)W - 1;
	pool->ray_vector_x = pool->vector_x + pool->plane_x * pool->camera_x;
	pool->ray_vector_y = pool->vector_y + pool->plane_y * pool->camera_x;
	pool->ray_cast->map_x = (int)pool->pos_x;
	pool->ray_cast->map_y = (int)pool->pos_y;
	pool->ray_cast->delta_vector_x = fabs(1 / pool->ray_vector_x);
	pool->ray_cast->delta_vector_y = fabs(1 / pool->ray_vector_y);
}

static void	part_one(t_pool *pool)
{
	pool->ray_cast->step_x = (pool->ray_vector_x < 0) ? -1 : 1;
	pool->ray_cast->side_vector_x = (pool->ray_vector_x < 0) ? (pool->pos_x - pool->ray_cast->map_x) * pool->ray_cast->delta_vector_x : (pool->ray_cast->map_x + 1.0 - pool->pos_x) * pool->ray_cast->delta_vector_x;
	pool->ray_cast->step_y = (pool->ray_vector_y < 0) ? -1 : 1;
	pool->ray_cast->side_vector_y = (pool->ray_vector_y < 0) ? (pool->pos_y - pool->ray_cast->map_y) * pool->ray_cast->delta_vector_y : (pool->ray_cast->map_y + 1.0 - pool->pos_y) * pool->ray_cast->delta_vector_y;
}

static void	part_two(t_pool *pool)
{
	pool->ray_cast->perp_wall_vector = (pool->ray_cast->side == 0) ? (pool->ray_cast->map_x - pool->pos_x + (1 - pool->ray_cast->step_x) / 2) / pool->ray_vector_x : (pool->ray_cast->map_y - pool->pos_y + (1 - pool->ray_cast->step_y) / 2) / pool->ray_vector_y;
	pool->ray_cast->line_height = (int)(H / pool->ray_cast->perp_wall_vector);
	pool->ray_cast->draw_start = -pool->ray_cast->line_height / 2 + H / 2;
}

static void	part_three(t_pool *pool)
{
	if (pool->ray_cast->draw_start < 0)
		pool->ray_cast->draw_start = 0;
	pool->ray_cast->draw_end = pool->ray_cast->line_height / 2 + H / 2;
	if (pool->ray_cast->draw_end >= H)
		pool->ray_cast->draw_end = H - 1;
}

void		ray_casting(t_pool *pool, int x)
{
	variables(pool, x);
	part_one(pool);
	while (pool->ray_cast->hit == 0)
	{
		if (pool->ray_cast->side_vector_x < pool->ray_cast->side_vector_y)
		{
			pool->ray_cast->side_vector_x += pool->ray_cast->delta_vector_x;
			pool->ray_cast->map_x += pool->ray_cast->step_x;
			pool->ray_cast->side = 0;
		}
		else
		{
			pool->ray_cast->side_vector_y += pool->ray_cast->delta_vector_y;
			pool->ray_cast->map_y += pool->ray_cast->step_y;
			pool->ray_cast->side = 1;
		}
		if (pool->map[pool->ray_cast->map_x][pool->ray_cast->map_y] > 0)
			pool->ray_cast->hit = 1;
	}
	part_two(pool);
	part_three(pool);
}