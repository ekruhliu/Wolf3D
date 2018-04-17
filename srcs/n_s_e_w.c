/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_s_e_w.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:24:16 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/16 20:24:16 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	n_s_e_w(t_pool *pool, int x)
{
	if (pool->ray_cast->side == 1 && pool->ray_vector_y > 0)
		pool->sdl->tex_arr[x][pool->draw_tex->y] = pool->textures[pool->draw_tex->text_num + 1][pool->draw_tex->position];
	if (pool->ray_cast->side == 1 && pool->ray_vector_y < 0)
		pool->sdl->tex_arr[x][pool->draw_tex->y] = pool->textures[pool->draw_tex->text_num + 6][pool->draw_tex->position];
	if (pool->ray_cast->side == 0 && pool->ray_vector_x > 0)
		pool->sdl->tex_arr[x][pool->draw_tex->y] = pool->textures[pool->draw_tex->text_num + 3][pool->draw_tex->position];
	if (pool->ray_cast->side == 0 && pool->ray_vector_x < 0)
		pool->sdl->tex_arr[x][pool->draw_tex->y] = pool->textures[pool->draw_tex->text_num + 4][pool->draw_tex->position];
}
