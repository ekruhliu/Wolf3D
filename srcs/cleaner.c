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

static	void	clear_textures(t_pool *pool)
{
	SDL_DestroyTexture(WEAPON->knife);
	SDL_DestroyTexture(WEAPON->pistol);
	SDL_DestroyTexture(WEAPON->mp40);
	SDL_DestroyTexture(WEAPON->shotgun);
	SDL_DestroyTexture(WEAPON->chainsaw);
	SDL_DestroyTexture(WEAPON->pistol_attack_tex);
	SDL_DestroyTexture(WEAPON->knife_attack_tex);
	SDL_DestroyTexture(WEAPON->mp40_attack_tex);
	SDL_DestroyTexture(WEAPON->shotgun_attack_tex);
	SDL_DestroyTexture(pool->sdl->screen_tex);
	SDL_DestroyRenderer(pool->sdl->rend);
}

void			cleaner(t_pool *pool)
{
	int i;

	i = 0;
	while (i < 22)
	{
		free(TEXTURE[i]);
		i++;
	}
	i = 0;
	while (i < pool->len_map_y)
	{
		free(MAP[i]);
		i++;
	}
	free(MAP);
	clear_textures(pool);
	free(pool->sdl);
	free(pool->ray_cast);
	free(pool->draw_tex);
	free(BAR);
	free(WEAPON);
	free(pool->doors);
	free(pool);
}

void			clear_surfs(t_pool *pool)
{
	SDL_FreeSurface(WEAPON->pistol_img);
	SDL_FreeSurface(WEAPON->knife_img);
	SDL_FreeSurface(WEAPON->mp40_img);
	SDL_FreeSurface(WEAPON->pistol_attack_img);
	SDL_FreeSurface(WEAPON->knife_attack_img);
	SDL_FreeSurface(WEAPON->mp40_attack_img);
	SDL_FreeSurface(BAR->face_img);
	SDL_FreeSurface(BAR->health_img);
	SDL_FreeSurface(BAR->arms_img);
	SDL_FreeSurface(BAR->fuck_img);
	SDL_FreeSurface(WEAPON->shotgun_img);
	SDL_FreeSurface(WEAPON->shotgun_attack_img);
	SDL_FreeSurface(WEAPON->chainsaw_img);
	// SDL_FreeSurface(BAR->mini_map_img);
}
