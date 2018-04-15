/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_weapon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 08:38:47 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/15 08:38:47 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	clear_weapon(t_pool *pool)
{
	pool->weapon->act_pistol = 0;
	pool->weapon->act_knife = 0;
	pool->weapon->act_mp40 = 0;
	pool->bar->act_fuck = 0;
	pool->weapon->knife_attack = 0;
	pool->weapon->pistol_attack = 0;
	pool->weapon->mp40_attack = 0;
	pool->weapon->act_shotgun = 0;
	pool->weapon->shotgun_attack = 0;
}

int	check_attack(t_pool *pool)
{
	if (pool->bar->act_fuck != 0)
		return (1);
	if (pool->weapon->knife_attack != 0)
		return (1);
	if (pool->weapon->pistol_attack != 0)
		return (1);
	if (pool->weapon->mp40_attack != 0)
		return (1);
	if (pool->weapon->shotgun_attack != 0)
		return (1);
	return (0);
}
