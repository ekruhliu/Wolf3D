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
		if (pool->mp == 1)
			n_s_e_w(pool, tex_num);
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
		pool->sdl->tex_arr[x][pool->draw_tex->y] = (pool->textures[2][texture_W * pool->draw_tex->floor_tex_y + pool->draw_tex->floor_tex_x] >> 1) & 8355711;
		pool->sdl->tex_arr[x][H - pool->draw_tex->y] = pool->textures[2][texture_W * pool->draw_tex->floor_tex_y + pool->draw_tex->floor_tex_x];
		pool->draw_tex->y++;
	}
}

void			draw_weapon_and_bar(t_pool *pool)
{
	SDL_RenderCopy(pool->sdl->rend, pool->sdl->screen_tex, &pool->sdl->SrcR, &pool->sdl->DestR);
	SDL_RenderCopy(pool->sdl->rend, pool->bar->face, &pool->bar->Sface, &pool->bar->Dface);
	SDL_RenderCopy(pool->sdl->rend, pool->bar->health, &pool->bar->Shealth, &pool->bar->Dhealth);
	SDL_RenderCopy(pool->sdl->rend, pool->bar->arms, &pool->bar->Sarms, &pool->bar->Darms);
	if (pool->weapon->act_knife == 1)
		SDL_RenderCopy(pool->sdl->rend, pool->weapon->knife, &pool->weapon->Sknife, &pool->weapon->Dknife);
	if (pool->weapon->act_pistol == 1)
		SDL_RenderCopy(pool->sdl->rend, pool->weapon->pistol, &pool->weapon->Spist, &pool->weapon->Dpist);
	if (pool->bar->act_fuck == 1)
		SDL_RenderCopy(pool->sdl->rend, pool->bar->fuck, &pool->bar->Sfuck, &pool->bar->Dfuck);
	if (pool->weapon->act_mp40 == 1)
		SDL_RenderCopy(pool->sdl->rend, pool->weapon->mp40, &pool->weapon->Smp40, &pool->weapon->Dmp40);
	if (pool->weapon->knife_attack == 1)
		SDL_RenderCopy(pool->sdl->rend, pool->weapon->knife_attack_tex, &pool->weapon->Sknife, &pool->weapon->Dknife);
	if (pool->weapon->pistol_attack == 1)
		SDL_RenderCopy(pool->sdl->rend, pool->weapon->pistol_attack_tex, &pool->weapon->Spist_att, &pool->weapon->Dpist_att);
	if (pool->weapon->mp40_attack == 1)
		SDL_RenderCopy(pool->sdl->rend, pool->weapon->mp40_attack_tex, &pool->weapon->Smp40_att, &pool->weapon->Dmp40_att);
	if (pool->weapon->act_shotgun == 1)
		SDL_RenderCopy(pool->sdl->rend, pool->weapon->shotgun, &pool->weapon->Sshotgun, &pool->weapon->Dshotgun);
	if (pool->weapon->shotgun_attack == 1)
		SDL_RenderCopy(pool->sdl->rend, pool->weapon->shotgun_attack_tex, &pool->weapon->Sshotgun, &pool->weapon->Dshotgun);
}