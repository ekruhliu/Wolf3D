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
	WEAPON->act_pistol = 0;
	WEAPON->act_knife = 0;
	WEAPON->act_mp40 = 0;
	BAR->act_fuck = 0;
	WEAPON->knife_attack = 0;
	WEAPON->pistol_attack = 0;
	WEAPON->mp40_attack = 0;
	WEAPON->act_shotgun = 0;
	WEAPON->shotgun_attack = 0;
	WEAPON->act_chainsaw = 0;
	WEAPON->chainsaw_attack = 0;
}

int		check_attack(t_pool *pool)
{
	if (BAR->act_fuck != 0)
		return (1);
	if (WEAPON->knife_attack != 0)
		return (1);
	if (WEAPON->pistol_attack != 0)
		return (1);
	if (WEAPON->mp40_attack != 0)
		return (1);
	if (WEAPON->shotgun_attack != 0)
		return (1);
	if (WEAPON->chainsaw_attack != 0)
		return (1);
	return (0);
}
