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
	free(pool->textures[8]);
	free(pool->textures[9]);
	free(pool->textures[10]);
	free(pool->textures[11]);
	free(pool->textures[12]);
	free(pool->textures[13]);
	free(pool->textures[14]);
	free(pool->textures[15]);
	free(pool->textures[16]);
	free(pool->textures[17]);
	free(pool->textures[18]);
	free(pool->textures[19]);
	free(pool->textures[20]);
	free(pool->textures[21]);
	free(pool->textures[22]);
	free(pool->textures[23]);
	free(pool->textures[24]);
	free(pool->textures[25]);
	free(pool->textures[26]);
	free(pool->textures[27]);
	free(pool->textures[28]);
	free(pool->textures[29]);
	free(pool->textures[30]);
	free(pool->textures[31]);
	free(pool->textures[32]);
	free(pool->textures[33]);
	free(pool->textures[34]);
	free(pool->textures[35]);
	free(pool->textures[36]);
	free(pool->textures[37]);
	free(pool->textures[38]);
	free(pool->textures[39]);
	free(pool->textures[40]);
	free(pool->textures[41]);
	free(pool->textures[42]);
	free(pool->textures[43]);
	free(pool->textures[44]);
	free(pool->textures[45]);
	free(pool->textures[46]);
	free(pool->textures[47]);
	free(pool->textures[48]);
	free(pool->textures[49]);
	free(pool->textures[50]);
	free(pool->textures[51]);
	free(pool->textures[52]);
	free(pool->textures[53]);
	free(pool->textures[54]);
	free(pool->textures[55]);
	free(pool->textures[56]);
	free(pool->textures[57]);
	free(pool->textures[58]);
	free(pool->textures[59]);
	free(pool->textures[60]);
	free(pool->textures[61]);
	free(pool->textures[62]);
	free(pool->map);
	free(pool->sdl);
	free(pool->ray_cast);
	free(pool->draw_tex);
	free(pool);
}
