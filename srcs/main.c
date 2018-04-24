/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:10:20 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/02 15:10:21 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void	variables(t_pool *pool)
{
	pool->time = 0;
	pool->old_time = 0;
	pool->sdl->src_r.x = 0;
	pool->sdl->src_r.y = 0;
	pool->sdl->src_r.w = 1024;
	pool->sdl->src_r.h = 768;
	pool->sdl->dst_r.x = 0;
	pool->sdl->dst_r.y = 0;
	pool->sdl->dst_r.w = 1024;
	pool->sdl->dst_r.h = 768;
	pool->vector_y = 0;
	pool->vector_x = -1;
	pool->plane_x = 0;
	pool->plane_y = 0.66;
	pool->sdl->done = SDL_FALSE;
	pool->weapon->act_pistol = 0;
	pool->weapon->act_knife = 1;
	pool->weapon->knife_attack = 0;
	pool->weapon->pistol_attack = 0;
	pool->speed_val = 4.0;
	pool->doors->time_door = 0;
	pool->texture_w = 64;
	pool->texture_h = 64;
}

static void	part_one(t_pool *pool, char *argv)
{
	pool->sdl = malloc(sizeof(t_sdl));
	pool->ray_cast = malloc(sizeof(t_ray_cast));
	pool->draw_tex = malloc(sizeof(t_draw_tex));
	pool->bar = malloc(sizeof(t_bar));
	pool->weapon = malloc(sizeof(t_weapon));
	pool->doors = malloc(sizeof(t_doors));
	// int i;
	// for(i = 0; i < SDL_GetNumAudioDrivers(); ++i)
	// {
	// 	pool->sdl->driver_name = SDL_GetAudioDriver(i);
	// 	if (SDL_AudioInit(pool->sdl->driver_name))
	// 	{
	// 		ft_putstr("\033[1;31mAudio driver failed to initialize\n\e[m");
	// 		continue;
	// 	}
	// 	SDL_AudioQuit();
	// }
	variables(pool);
	map_height(argv, pool);
	map_widthe(argv, pool);
	create_map(argv, pool);
	// system("leaks wolf3d");
	// exit(1);
	if (!pool->pos_x && !pool->pos_y)
	{
		ft_putstr("\033[1;31mERROR\n\e[m");
		exit(1);
	}
	create_textures(pool);
	initialization(pool);
	init_bar(pool);
	init_weapon(pool);
	// BAR->mini_map_img->pixels = argv;
	// BAR->mini_map = TEX_FMR_SRF(RENDER, BAR->mini_map_img);
	clear_surfs(pool);
}

static void	part_two(t_pool *pool)
{
	if (time(NULL) == pool->doors->time_door)
		pool->map[pool->doors->blue_door_y][pool->doors->blue_door_x] = 9;
	from_nth_to_texture(pool);
	time_and_speed(pool);
	SDL_SetRenderDrawColor(pool->sdl->rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
	// BAR->d_map.x = 300;
	// BAR->d_map.y = 300;
	// BAR->d_map.w = 500;
	// BAR->d_map.h = 350;
	// REND_CPY(RENDER, BAR->mini_map, &SRC_R, &BAR->d_map);
	draw_weapon_and_bar(pool);
	SDL_RenderPresent(pool->sdl->rend);
	SDL_RenderClear(pool->sdl->rend);
	keys(pool);
}

int			main(int argc, char **argv)
{
	int		x;
	int		leaks;
	t_pool	*pool;

	leaks = 0;
	if (argc > 1 && argv[1])
	{
		pool = malloc(sizeof(t_pool));
		check_mand(pool, argv[2]);
		part_one(pool, argv[1]);
		while (!pool->sdl->done)
		{
			x = 0;
			while (x < W)
			{
				ray_casting(pool, x);
				draw_textures(pool, x);
				draw_floor_and_ceiling(pool, x);
				x++;
			}
			part_two(pool);
		}
		leaks = pool->check_leak;
		just_exit(pool);
	}
	else
		usage();
	return (0);
}
