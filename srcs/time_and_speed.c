/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_and_speed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:04:40 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/11 16:04:57 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	time_and_speed(t_pool *pool)
{
	pool->old_time = pool->time;
	pool->time = SDL_GetTicks();
	pool->frame_time = (pool->time - pool->old_time) / 1000.0;
	MOVE_SPEED = pool->frame_time * pool->speed_val;
	ROT_SPEED = pool->frame_time * 3.0;
}
