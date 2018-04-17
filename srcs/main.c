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
	pool->sdl->SrcR.x = 0;
	pool->sdl->SrcR.y = 0;
	pool->sdl->SrcR.w = 1024;
	pool->sdl->SrcR.h = 768;
	pool->sdl->DestR.x = 0;
	pool->sdl->DestR.y = 0;
	pool->sdl->DestR.w = 1024;
	pool->sdl->DestR.h = 768;
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
}

static void	part_one(t_pool *pool, char *argv)
{
	pool->sdl = malloc(sizeof(t_sdl));
	pool->ray_cast = malloc(sizeof(t_ray_cast));
	pool->draw_tex = malloc(sizeof(t_draw_tex));
	pool->bar = malloc(sizeof(t_bar));
	pool->weapon = malloc(sizeof(t_weapon));
	pool->doors = malloc(sizeof(t_doors));
	variables(pool);
	map_widthe(argv, pool);
	map_height(argv, pool);
	create_map(argv, pool);
	if (!pool->pos_x && !pool->pos_y)
	{
		ft_putstr("\033[1;31mERROR: No player position!\n\e[m");
		exit(1);
	}
	create_textures(pool);
	initialization(pool);
	init_bar(pool);
	init_weapon(pool);
	clear_surfs(pool);
}

static void	part_two(t_pool *pool)
{
	if (time(NULL) == pool->doors->time_door)
		pool->map[pool->doors->blue_door_y][pool->doors->blue_door_x] = 9;
	from_nth_to_texture(pool);
	time_and_speed(pool);
	SDL_SetRenderDrawColor(pool->sdl->rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
	draw_weapon_and_bar(pool);
	SDL_RenderPresent(pool->sdl->rend);
	SDL_RenderClear(pool->sdl->rend);
	keys(pool);
}

static void	part_three(t_pool *pool)
{
	SDL_DestroyRenderer(pool->sdl->rend);
	SDL_DestroyWindow(pool->sdl->win);
	SDL_Quit();
	cleaner(pool);
}

int	main(int argc, char **argv)
{
	if (argc > 1 && argv[1])
	{
		int		x;
		t_pool	*pool;

		pool = malloc(sizeof(t_pool));
		if (argv[2])
		{
			if (ft_atoi(argv[2]) == 1)
				pool->mp = 1;
		}
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
		part_three(pool);
	}
	else
		usage();
	return (0);
}
