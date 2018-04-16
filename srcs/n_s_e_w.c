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

void	n_s_e_w(t_pool *pool, int tex_num)
{
	if (pool->ray_cast->side == 1 && tex_num == 1 && pool->ray_cast->side_vector_y > 0)
		= pool->sdl->tex_arr[tex_num + 2][pool->draw_tex->y]

}