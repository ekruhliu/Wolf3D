/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:14:13 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/10 19:14:13 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static int		save_color(void *pixels, int i)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)pixels;
	return (tmp[i + 2] << 16 | tmp[i + 1] << 8 | tmp[i]);
}

void			make_textures(t_pool *pool, int *texture, const char *file)
{
	SDL_Surface	*surface;
	int			i;
	int			size;
	int			k;

	i = 0;
	k = 0;
	surface = IMG_Load(file);
	size = TEXTURE_H * TEXTURE_W;
	while (i < size)
	{
		texture[i] = save_color(surface->pixels, k);
		k += 4;
		i++;
	}
	SDL_FreeSurface(surface);
}

void			create_textures(t_pool *pool)
{
	int i;

	i = 0;
	while (i < 22)
	{
		TEXTURE[i] = malloc(sizeof(int) * (TEXTURE_W * TEXTURE_H));
		i++;
	}
	init_textures(pool);
}

void			from_nth_to_texture(t_pool *pool)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			REND_ARR[i] = TEXT_ARR[x][y];
			TEXT_ARR[x][y] = 0;
			i++;
			x++;
		}
		y++;
	}
	SDL_UpdateTexture(pool->sdl->screen_tex, NULL, REND_ARR, (W * 4));
	ft_bzero(REND_ARR, W * H);
}
