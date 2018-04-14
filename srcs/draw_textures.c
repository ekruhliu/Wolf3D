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
	pool->draw_tex->y = pool->ray_cast->draw_start;
	if (pool->ray_cast->side == 0)
		pool->draw_tex->wall_x = pool->pos_y + pool->ray_cast->perp_wall_vector * pool->ray_vector_y;
	else
		pool->draw_tex->wall_x = pool->pos_x + pool->ray_cast->perp_wall_vector * pool->ray_vector_x;
	pool->draw_tex->wall_x -= floor(pool->draw_tex->wall_x);
	pool->draw_tex->tex_x = (int)(pool->draw_tex->wall_x * (double)texture_W);
	if ((pool->ray_cast->side == 0 && pool->ray_vector_x > 0) || (pool->ray_cast->side == 1 && pool->ray_vector_y < 0))
		pool->draw_tex->tex_x = texture_W - pool->draw_tex->tex_x - 1;
	while(pool->draw_tex->y < pool->ray_cast->draw_end)
	{
		pool->draw_tex->d = pool->draw_tex->y * 256 - H * 128 + pool->ray_cast->line_height * 128;
		pool->draw_tex->tex_y = ((pool->draw_tex->d * texture_H) / pool->ray_cast->line_height / 256);
		pool->draw_tex->position = texture_H * pool->draw_tex->tex_y + pool->draw_tex->tex_x;
		pool->draw_tex->text_num = pool->map[pool->ray_cast->map_x][pool->ray_cast->map_y] - 1;
		pool->sdl->tex_arr[x][pool->draw_tex->y] = pool->textures[pool->draw_tex->text_num][pool->draw_tex->position];
		if (pool->ray_cast->side == 1)
			pool->sdl->tex_arr[x][pool->draw_tex->y] = (pool->sdl->tex_arr[x][pool->draw_tex->y] >> 1) & 8355711;
		pool->draw_tex->y++;
	}
}

static	void	check_side(t_pool *pool)
{
	if (pool->ray_cast->side == 0 && pool->ray_vector_x > 0)
	{
		pool->draw_tex->floor_x_wall = pool->ray_cast->map_x;
		pool->draw_tex->floor_y_wall = pool->ray_cast->map_y + pool->draw_tex->wall_x;
	}
	else if (pool->ray_cast->side == 0 && pool->ray_vector_x < 0)
	{
		pool->draw_tex->floor_x_wall = pool->ray_cast->map_x + 1.0;
		pool->draw_tex->floor_y_wall = pool->ray_cast->map_y + pool->draw_tex->wall_x;
	}
	else if (pool->ray_cast->side == 1 && pool->ray_vector_y > 0)
	{
		pool->draw_tex->floor_x_wall = pool->ray_cast->map_x + pool->draw_tex->wall_x;
		pool->draw_tex->floor_y_wall = pool->ray_cast->map_y;
	}
	else
	{
		pool->draw_tex->floor_x_wall = pool->ray_cast->map_x + pool->draw_tex->wall_x;
		pool->draw_tex->floor_y_wall = pool->ray_cast->map_y + 1.0;
	}
}

void			draw_floor_and_ceiling(t_pool *pool, int x)
{
	pool->draw_tex->y = pool->ray_cast->draw_end + 1;
	check_side(pool);
	pool->draw_tex->dist_wall = pool->ray_cast->perp_wall_vector;
	pool->draw_tex->dist_player = 0.0;
	if (pool->ray_cast->draw_end < 0)
		pool->ray_cast->draw_end = H;
	while (pool->draw_tex->y < H)
	{
		pool->draw_tex->current_dist = H / (2.0 * pool->draw_tex->y - H);
		pool->draw_tex->weight = (pool->draw_tex->current_dist - pool->draw_tex->dist_player) / (pool->draw_tex->dist_wall - pool->draw_tex->dist_player);
		pool->draw_tex->current_floor_x = pool->draw_tex->weight * pool->draw_tex->floor_x_wall + (1.0 - pool->draw_tex->weight) * pool->pos_x;
		pool->draw_tex->current_floor_y = pool->draw_tex->weight * pool->draw_tex->floor_y_wall + (1.0 - pool->draw_tex->weight) * pool->pos_y;
		pool->draw_tex->floor_tex_x = (int)(pool->draw_tex->current_floor_x * texture_W) % texture_W;
		pool->draw_tex->floor_tex_y = (int)(pool->draw_tex->current_floor_y * texture_W) % texture_W;
		pool->sdl->tex_arr[x][pool->draw_tex->y] = (pool->textures[0][texture_W * pool->draw_tex->floor_tex_y + pool->draw_tex->floor_tex_x] >> 1) & 8355711;
		pool->sdl->tex_arr[x][H - pool->draw_tex->y] = pool->textures[0][texture_W * pool->draw_tex->floor_tex_y + pool->draw_tex->floor_tex_x];
		pool->draw_tex->y++;
	}
}
