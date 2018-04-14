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
}

static void	part_one(t_pool *pool, char *argv)
{
	pool->sdl = malloc(sizeof(t_sdl));
	pool->ray_cast = malloc(sizeof(t_ray_cast));
	pool->draw_tex = malloc(sizeof(t_draw_tex));
	pool->bar = malloc(sizeof(t_bar));
	pool->weapon = malloc(sizeof(t_weapon));
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
	pool->bar->face_img = IMG_Load("./pics/bar/face.png");
	pool->bar->health_img = IMG_Load("./pics/bar/health.png");
	pool->bar->arms_img = IMG_Load("./pics/bar/all_arms.png");
	pool->weapon->pistol_img = IMG_Load("./pics/weapon/pistol.png");
	pool->weapon->knife_img = IMG_Load("./pics/weapon/knife.png");
	pool->bar->fuck_img = IMG_Load("./pics/weapon/fuck.png");
	pool->weapon->knife_attack_img = IMG_Load("./pics/weapon/knife_2.png");

	pool->bar->face = SDL_CreateTextureFromSurface(pool->sdl->rend, pool->bar->face_img);
	pool->bar->health = SDL_CreateTextureFromSurface(pool->sdl->rend, pool->bar->health_img);
	pool->bar->arms = SDL_CreateTextureFromSurface(pool->sdl->rend, pool->bar->arms_img);
	pool->weapon->pistol = SDL_CreateTextureFromSurface(pool->sdl->rend, pool->weapon->pistol_img);
	pool->weapon->knife = SDL_CreateTextureFromSurface(pool->sdl->rend, pool->weapon->knife_img);
	pool->bar->fuck = SDL_CreateTextureFromSurface(pool->sdl->rend, pool->bar->fuck_img);
	pool->weapon->knife_attack_tex = SDL_CreateTextureFromSurface(pool->sdl->rend, pool->weapon->knife_attack_img);

	pool->bar->Sface.x = 0;
	pool->bar->Sface.y = 0;
	pool->bar->Sface.w = 1024;
	pool->bar->Sface.h = 768;
	pool->bar->Shealth.x = 0;
	pool->bar->Shealth.y = 0;
	pool->bar->Shealth.w = 1024;
	pool->bar->Shealth.h = 768;
	pool->bar->Sarms.x = 0;
	pool->bar->Sarms.y = 0;
	pool->bar->Sarms.w = 1024;
	pool->bar->Sarms.h = 768;
	pool->bar->Dface.x = 0;
	pool->bar->Dface.y = 518;
	pool->bar->Dface.w = 150;
	pool->bar->Dface.h = 150;
	pool->bar->Dhealth.x = 0;
	pool->bar->Dhealth.y = 668;
	pool->bar->Dhealth.w = 150;
	pool->bar->Dhealth.h = 100;
	pool->bar->Darms.x = 805;
	pool->bar->Darms.y = 518;
	pool->bar->Darms.w = 220;
	pool->bar->Darms.h = 30;

	pool->weapon->Spist.x = 0;
	pool->weapon->Spist.y = 0;
	pool->weapon->Spist.w = 1024;
	pool->weapon->Spist.h = 768;
	pool->weapon->Dpist.x = 360;
	pool->weapon->Dpist.y = 470;
	pool->weapon->Dpist.w = 320;
	pool->weapon->Dpist.h = 300;

	pool->weapon->Sknife.x = 0;
	pool->weapon->Sknife.y = 0;
	pool->weapon->Sknife.w = 1024;
	pool->weapon->Sknife.h = 768;
	pool->weapon->Dknife.x = 500;
	pool->weapon->Dknife.y = 470;
	pool->weapon->Dknife.w = 320;
	pool->weapon->Dknife.h = 300;

	pool->bar->Sfuck.x = 0;
	pool->bar->Sfuck.y = 0;
	pool->bar->Sfuck.w = 1024;
	pool->bar->Sfuck.h = 768;
	pool->bar->Dfuck.x = 500;
	pool->bar->Dfuck.y = 470;
	pool->bar->Dfuck.w = 260;
	pool->bar->Dfuck.h = 300;

	SDL_FreeSurface(pool->weapon->pistol_img);
	SDL_FreeSurface(pool->bar->face_img);
	SDL_FreeSurface(pool->bar->health_img);
	SDL_FreeSurface(pool->bar->arms_img);
	SDL_FreeSurface(pool->weapon->knife_img);
	SDL_FreeSurface(pool->bar->fuck_img);

}

static void	part_two(t_pool *pool)
{
	from_nth_to_texture(pool);
	time_and_speed(pool);
	SDL_SetRenderDrawColor(pool->sdl->rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderCopy(pool->sdl->rend, pool->sdl->screen_tex, &pool->sdl->SrcR, &pool->sdl->DestR);
	SDL_RenderCopy(pool->sdl->rend, pool->bar->face, &pool->bar->Sface, &pool->bar->Dface);
	SDL_RenderCopy(pool->sdl->rend, pool->bar->health, &pool->bar->Shealth, &pool->bar->Dhealth);
	SDL_RenderCopy(pool->sdl->rend, pool->bar->arms, &pool->bar->Sarms, &pool->bar->Darms);
	if (pool->weapon->act_knife == 1)
		SDL_RenderCopy(pool->sdl->rend, pool->weapon->knife, &pool->weapon->Sknife, &pool->weapon->Dknife);
	if (pool->weapon->act_pistol == 1)
		SDL_RenderCopy(pool->sdl->rend, pool->weapon->pistol, &pool->weapon->Spist, &pool->weapon->Dpist);
	if (pool->bar->act_fuck == 1)
		SDL_RenderCopy(pool->sdl->rend, pool->bar->fuck, &pool->bar->Sfuck, &pool->bar->Dfuck);
	if (pool->weapon->knife_attack == 1)
		SDL_RenderCopy(pool->sdl->rend, pool->weapon->knife_attack_tex, &pool->weapon->Sknife, &pool->weapon->Dknife);
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
