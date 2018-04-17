/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:33:29 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/11 12:33:58 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	cleaner(t_pool *pool)
{
	int i;

	i = 0;
	while (i < 22)
	{
		free(pool->textures[i]);
		i++;
	}
	free(pool->map);
	free(pool->sdl);
	free(pool->ray_cast);
	free(pool->draw_tex);
	free(pool->bar);
	free(pool->weapon);
	free(pool->doors);
	free(pool);
}

void	clear_surfs(t_pool *pool)
{
	SDL_FreeSurface(pool->weapon->pistol_img);
	SDL_FreeSurface(pool->weapon->knife_img);
	SDL_FreeSurface(pool->weapon->mp40_img);
	SDL_FreeSurface(pool->weapon->pistol_attack_img);
	SDL_FreeSurface(pool->weapon->knife_attack_img);
	SDL_FreeSurface(pool->weapon->mp40_attack_img);
	SDL_FreeSurface(pool->bar->face_img);
	SDL_FreeSurface(pool->bar->health_img);
	SDL_FreeSurface(pool->bar->arms_img);
	SDL_FreeSurface(pool->bar->fuck_img);
	SDL_FreeSurface(pool->weapon->shotgun_img);
	SDL_FreeSurface(pool->weapon->shotgun_attack_img);
}
