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
	// PROTECTION
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
	pool->textures[8] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[9] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[10] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[11] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[12] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[13] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[14] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[15] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[16] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[17] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[18] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[19] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[20] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[21] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[22] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[23] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[24] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[25] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[26] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[27] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[28] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[29] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[30] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[31] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[32] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[33] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[34] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[35] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[36] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[37] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[38] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[39] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[40] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[41] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[42] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[43] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[44] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[45] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[46] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[47] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[48] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[49] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[50] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[51] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[52] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[53] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[54] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[55] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[56] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[57] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[58] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[59] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[60] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[61] = malloc(sizeof(int) * (texture_W * texture_H));
	pool->textures[62] = malloc(sizeof(int) * (texture_W * texture_H));
	// pool->textures[63] = malloc(sizeof(int) * (texture_W * texture_H));
	make_textures(pool->textures[0], "./pics/walls/greystone.png");
	make_textures(pool->textures[1], "./pics/walls/door_stone.png");
	make_textures(pool->textures[2], "./pics/walls/swas_flag.png");
	make_textures(pool->textures[3], "./pics/walls/hitler_pict.png");
	make_textures(pool->textures[4], "./pics/walls/lattice_door.png");
	make_textures(pool->textures[5], "./pics/walls/eagle_w_swas.png");
	make_textures(pool->textures[6], "./pics/walls/lattice_skeleton_door.png");
	make_textures(pool->textures[7], "./pics/walls/bluestone_v2.png");
	make_textures(pool->textures[8], "./pics/walls/bluestone.png");
	make_textures(pool->textures[9], "./pics/walls/eagle_pict.png");
	make_textures(pool->textures[10], "./pics/walls/hitler_pict_wood.png");
	make_textures(pool->textures[11], "./pics/walls/wood.png");
	make_textures(pool->textures[12], "./pics/walls/metal.png");
	make_textures(pool->textures[13], "./pics/walls/verboten.png");
	make_textures(pool->textures[14], "./pics/walls/achtung.png");
	make_textures(pool->textures[15], "./pics/walls/bluemetal.png");
	make_textures(pool->textures[16], "./pics/walls/earth.png");
	make_textures(pool->textures[17], "./pics/walls/night_sky.png");
	make_textures(pool->textures[18], "./pics/walls/redbrick.png");
	make_textures(pool->textures[19], "./pics/walls/sws_redbrick.png");
	make_textures(pool->textures[20], "./pics/walls/purplestone.png");
	make_textures(pool->textures[21], "./pics/walls/eagle.png");
	make_textures(pool->textures[22], "./pics/walls/metal_wall.png");
	make_textures(pool->textures[23], "./pics/walls/switch_down.png");
	make_textures(pool->textures[24], "./pics/walls/lazure.png");
	make_textures(pool->textures[25], "./pics/walls/switch_up.png");
	make_textures(pool->textures[26], "./pics/walls/cross_wood.png");
	make_textures(pool->textures[27], "./pics/walls/mossy_v2.png");
	make_textures(pool->textures[28], "./pics/walls/blood_purplestone.png");
	make_textures(pool->textures[29], "./pics/walls/mossy.png");
	make_textures(pool->textures[30], "./pics/walls/greystone_v2.png");
	make_textures(pool->textures[31], "./pics/walls/stone_varboten.png");
	make_textures(pool->textures[32], "./pics/walls/stone_achtung.png");
	make_textures(pool->textures[33], "./pics/walls/sandstone.png");
	make_textures(pool->textures[34], "./pics/walls/blood_sandstone.png");
	make_textures(pool->textures[35], "./pics/walls/blood_sandstone_v2.png");
	make_textures(pool->textures[36], "./pics/walls/blood_sandstone_v3.png");
	make_textures(pool->textures[37], "./pics/walls/mozaik_hitler.png");
	make_textures(pool->textures[38], "./pics/walls/blue_skull_wall.png");
	make_textures(pool->textures[39], "./pics/walls/greybrick.png");
	make_textures(pool->textures[40], "./pics/walls/swas_blue_wall.png");
	make_textures(pool->textures[41], "./pics/walls/greybrick_v2.png");
	make_textures(pool->textures[42], "./pics/walls/multibrick.png");
	make_textures(pool->textures[43], "./pics/walls/brkn_greybrick.png");
	make_textures(pool->textures[44], "./pics/walls/bluewall.png");
	make_textures(pool->textures[45], "./pics/walls/blue_verboten.png");
	make_textures(pool->textures[46], "./pics/walls/blue_achtung.png");
	make_textures(pool->textures[47], "./pics/walls/sandsquare.png");
	make_textures(pool->textures[48], "./pics/walls/earth_pict.png");
	make_textures(pool->textures[49], "./pics/walls/orangebrick.png");
	make_textures(pool->textures[50], "./pics/walls/orangebrick_v2.png");
	make_textures(pool->textures[51], "./pics/walls/sandsquare_v2.png");
	make_textures(pool->textures[52], "./pics/walls/swas_flag_sandsquare.png");
	make_textures(pool->textures[53], "./pics/walls/plywood.png");
	make_textures(pool->textures[54], "./pics/walls/hitler.png");
	make_textures(pool->textures[55], "./pics/walls/blue_metal_door.png");
	make_textures(pool->textures[56], "./pics/walls/open_blue_metal_door.png");
	make_textures(pool->textures[57], "./pics/walls/metal_button.png");
	make_textures(pool->textures[58], "./pics/walls/metalwall.png");
	make_textures(pool->textures[59], "./pics/walls/metal_wall_nails.png");
	make_textures(pool->textures[60], "./pics/walls/switch_down_nails.png");
	make_textures(pool->textures[61], "./pics/walls/black.png");
	make_textures(pool->textures[62], "./pics/walls/switch_up_nails.png");
	// make_textures(pool->textures[63], "./pics/walls/");
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
