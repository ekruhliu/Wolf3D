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
	if (SIDE == 1 && RAY_VECTOR_Y > 0)
		TEXT_ARR[x][Y] = pool->textures[TEXT_NUM + 1][POSITION];
	if (SIDE == 1 && RAY_VECTOR_Y < 0)
		TEXT_ARR[x][Y] = pool->textures[TEXT_NUM + 6][POSITION];
	if (SIDE == 0 && RAY_VECTOR_X > 0)
		TEXT_ARR[x][Y] = pool->textures[TEXT_NUM + 3][POSITION];
	if (SIDE == 0 && RAY_VECTOR_X < 0)
		TEXT_ARR[x][Y] = pool->textures[TEXT_NUM + 4][POSITION];
}
