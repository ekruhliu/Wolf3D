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
	free(pool->textures[0]);
	free(pool->textures[1]);
	free(pool->textures[2]);
	free(pool->textures[3]);
	free(pool->textures[4]);
	free(pool->textures[5]);
	free(pool->textures[6]);
	free(pool->textures[7]);
	free(pool->map);
	free(pool->sdl);
	free(pool->ray_cast);
	free(pool->draw_tex);
	free(pool);
}
