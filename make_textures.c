/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:14:13 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/10 19:14:13 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		save_color(void *pixels, int i)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)pixels;
	return (tmp[i + 2] << 16 | tmp[i + 1] << 8 | tmp[i]);
}

void	make_textures(int *textures, const char *file)
{
	SDL_Surface	*surface;
	int			i;
	int			size;
	int			k;

	i = 0;
	k = 0;
	surface = IMG_Load(file);
	size = texture_H * texture_W;
	while (i < size)
	{
		textures[i] = save_color(surface->pixels, k);
		k += 4;
		i++;
	}
	SDL_FreeSurface(surface);
}
