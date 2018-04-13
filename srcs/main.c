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
	pool->pos_x = 2;
	pool->pos_y = 2;
	pool->vector_y = 0;
	pool->vector_x = -1;
	pool->plane_x = 0;
	pool->plane_y = 0.66;
	pool->sdl->done = SDL_FALSE;
}

static void	part_one(t_pool *pool, char *argv)
{
	pool->sdl = malloc(sizeof(t_sdl));
	pool->ray_cast = malloc(sizeof(t_ray_cast));
	pool->draw_tex = malloc(sizeof(t_draw_tex));
	variables(pool);
	map_widthe(argv, pool);
	map_height(argv, pool);
	create_map(argv, pool);
	create_textures(pool);
	initialization(pool);

	pool->bar->face_img = IMG_Load("./pics/bar/face.png");
	// pool->bar->health_img = IMG_Load("./pics/bar/health.png");
	// pool->bar->arms_img = IMG_Load("./pics/bar/all_arms.png");

	pool->bar->face = SDL_CreateTextureFromSurface(pool->sdl->rend, pool->bar->face_img);
	// pool->bar->health = SDL_CreateTextureFromSurface(pool->sdl->rend, pool->bar->health_img);
	// pool->bar->arms = SDL_CreateTextureFromSurface(pool->sdl->rend, pool->bar->arms_img);

	pool->bar->Sface.x = 0;
	pool->bar->Sface.y = 0;
	pool->bar->Sface.w = 1024;
	pool->bar->Sface.h = 768;
	// pool->bar->Shealth.x = 200;
	// pool->bar->Shealth.y = 200;
	// pool->bar->Shealth.w = 200;
	// pool->bar->Shealth.h = 200;
	// pool->bar->Sarms.x = 300;
	// pool->bar->Sarms.y = 300;
	// pool->bar->Sarms.w = 300;
	// pool->bar->Sarms.h = 300;
	pool->bar->Dface.x = 100;
	pool->bar->Dface.y = 300;
	pool->bar->Dface.w = 100;
	pool->bar->Dface.h = 300;
	// pool->bar->Dhealth.x = 500;
	// pool->bar->Dhealth.y = 500;
	// pool->bar->Dhealth.w = 500;
	// pool->bar->Dhealth.h = 500;
	// pool->bar->Darms.x = 600;
	// pool->bar->Darms.y = 600;
	// pool->bar->Darms.w = 600;
	// pool->bar->Darms.h = 600;
	SDL_FreeSurface(pool->bar->face_img);
	// SDL_FreeSurface(pool->bar->health_img);
	// SDL_FreeSurface(pool->bar->arms_img);
}

static void	part_two(t_pool *pool)
{
	from_nth_to_texture(pool);
	time_and_speed(pool);
	SDL_SetRenderDrawColor(pool->sdl->rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderCopy(pool->sdl->rend, pool->sdl->screen_tex, &pool->sdl->SrcR, &pool->sdl->DestR);
	SDL_RenderCopy(pool->sdl->rend, pool->bar->face, &pool->bar->Sface, &pool->bar->Dface);
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
