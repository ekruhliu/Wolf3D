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

static void		make_textures(int *textures, const char *file)
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

void			create_textures(t_pool *pool)
{
	pool->textures[0] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[1] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[2] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[3] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[4] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[5] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[6] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[7] = malloc(sizeof(int) * (texture_W * texture_H));
	make_textures(pool->textures[0], "./pics/wood.png");
	make_textures(pool->textures[1], "./pics/colorstone.png");
	make_textures(pool->textures[2], "./pics/greystone.png");
	make_textures(pool->textures[3], "./pics/dsaEHty.png");
	make_textures(pool->textures[4], "./pics/7fMmatx.png");
	make_textures(pool->textures[5], "./pics/redbrick.png");
	make_textures(pool->textures[6], "./pics/mossy.png");
	make_textures(pool->textures[7], "./pics/greenlight.png");
}

void		from_nth_to_texture(t_pool *pool)
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
			pool->sdl->rend_arr[i] = pool->sdl->tex_arr[x][y];
			pool->sdl->tex_arr[x][y] = 0;
			i++;
			x++;
		}
		y++;
	}
	SDL_UpdateTexture(pool->sdl->screen_tex, NULL, pool->sdl->rend_arr, (W * 4));
	ft_bzero(pool->sdl->rend_arr, W * H);
}
