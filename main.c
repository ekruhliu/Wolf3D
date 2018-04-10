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

#include "wolf.h"

int	main(int argc, char **argv)
{
	if (argc > 1 && argv[1])
	{
		t_pool	*pool;
		pool = malloc(sizeof(t_pool));
		double	pos_x;
		double	pos_y;
		double	vector_x;
		double	vector_y;
		double	plane_x;
		double	plane_y;
		int		x;
		SDL_Event	event;
		double			camera_x;
		double			ray_vector_x;
		double			ray_vector_y;
		SDL_Window*		win;
		SDL_bool		done;
		Uint32			render_flags;
		SDL_Renderer*	rend;
		double			time = 0;
		double			old_time = 0;
		int		*textures[8];
		// SDL_Texture		*textures[5];
		Uint32 		tex_arr[W][H];
		Uint32 		rend_arr[W * H];
		// bzero(rend_arr, W * H);


		SDL_Rect SrcR;
		SDL_Rect DestR;

		SrcR.x = 0;
		SrcR.y = 0;
		SrcR.w = 1024;
		SrcR.h = 768;

		DestR.x = 0;
		DestR.y = 0;
		DestR.w = 1024;
		DestR.h = 768;



		pos_x = 2;
		pos_y = 2;
		vector_y = 0;
		vector_x = -1;
		plane_x = 0;
		plane_y = 0.66;
		
		map_widthe(argv[1], pool);
		map_height(argv[1], pool);
		create_map(argv[1], pool);

		/***/
		textures[0] = malloc(sizeof(int) * (texture_W * texture_H));
		textures[1] = malloc(sizeof(int) * (texture_W * texture_H));
		textures[2] = malloc(sizeof(int) * (texture_W * texture_H));
		textures[3] = malloc(sizeof(int) * (texture_W * texture_H));
		textures[4] = malloc(sizeof(int) * (texture_W * texture_H));
		textures[5] = malloc(sizeof(int) * (texture_W * texture_H));
		textures[6] = malloc(sizeof(int) * (texture_W * texture_H));
		textures[7] = malloc(sizeof(int) * (texture_W * texture_H));
		make_textures(textures[0], "./pics/bluestone.png");
		make_textures(textures[1], "./pics/colorstone.png");
		make_textures(textures[2], "./pics/greystone.png");
		make_textures(textures[3], "./pics/wood.png");
		make_textures(textures[4], "./pics/eagle.png");
		make_textures(textures[5], "./pics/redbrick.png");
		make_textures(textures[6], "./pics/mossy.png");
		make_textures(textures[7], "./pics/greenlight.png");
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			ft_putstr("\033[1;31mError initializing SDL\n\e[m");
			return (1);
		}
		win = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W, H, 0);
		if (!win)
		{
			ft_putstr("\033[1;31mError creating window\n\e[m");
			SDL_Quit();
			return (1);
		}
		render_flags = SDL_RENDERER_ACCELERATED;
		rend = SDL_CreateRenderer(win, -1, render_flags);
		if (!rend)
		{
			ft_putstr("\033[1;31mError creating renderer\n\e[m");
			SDL_DestroyWindow(win);
			SDL_Quit();
			return (1);
		}
		SDL_Texture* screen_tex = SDL_CreateTexture(rend, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, W, H);
		done = SDL_FALSE;
		while (!done)
		{
			x = 0;
			while (x < W)
			{
				camera_x = 2 * x / (double)W - 1;
				ray_vector_x = vector_x + plane_x * camera_x;
				ray_vector_y = vector_y + plane_y * camera_x;
				int map_x = (int)pos_x;
				int map_y = (int)pos_y;
				
				double	side_vector_x;
				double	side_vector_y;

				double	delta_vector_x = fabs(1 / ray_vector_x);
				double	delta_vector_y = fabs(1 / ray_vector_y);
				double	perp_wall_vector;

				int step_x;
				int step_y;

				int hit = 0;
				int side;
				if (ray_vector_x < 0)
				{
					step_x = -1;
					side_vector_x = (pos_x - map_x) * delta_vector_x;
				}
				else
				{
					step_x = 1;
					side_vector_x = (map_x + 1.0 - pos_x) * delta_vector_x;
				}
				if (ray_vector_y < 0)
				{
					step_y = -1;
					side_vector_y = (pos_y - map_y) * delta_vector_y;
				}
				else
				{
					step_y = 1;
					side_vector_y = (map_y + 1.0 - pos_y) * delta_vector_y;
				}
				while (hit == 0)
				{
					if (side_vector_x < side_vector_y)
					{
						side_vector_x += delta_vector_x;
						map_x += step_x;
						side = 0;
					}
					else
					{
						side_vector_y += delta_vector_y;
						map_y += step_y;
						side = 1;
					}
					if (pool->map[map_x][map_y] > 0)
						hit = 1;
				}
				if (side == 0)
					perp_wall_vector = (map_x - pos_x + (1 - step_x) / 2) / ray_vector_x;
				else
					perp_wall_vector = (map_y - pos_y + (1 - step_y) / 2) / ray_vector_y;
				int line_height = (int)(H / perp_wall_vector);
				int draw_start = -line_height / 2 + H / 2;
				if (draw_start < 0)
					draw_start = 0;
				int draw_end = line_height / 2 + H / 2;
				if (draw_end >= H)
					draw_end = H - 1;
				/***/

				double	wall_x;
				if (side == 0)
					wall_x = pos_y + perp_wall_vector * ray_vector_y;
				else
					wall_x = pos_x + perp_wall_vector * ray_vector_x;
				wall_x -= floor(wall_x);

				int tex_x = (int)(wall_x * (double)texture_W);
				if ((side == 0 && ray_vector_x > 0) || (side == 1 && ray_vector_y < 0))
					tex_x = texture_W - tex_x - 1;
				int y = draw_start;
				int xcount = x;
				while(y < draw_end)
				{
					int d = y * 256 - H * 128 + line_height * 128;
					int tex_y = ((d * texture_H) / line_height / 256);
					xcount = texture_H * tex_y + tex_x;
					int textnum = pool->map[map_x][map_y] - 1;
					tex_arr[x][y] = textures[textnum][xcount];
					if (side == 1)
						tex_arr[x][y] = (tex_arr[x][y] >> 1) & 8355711;
					y++;
				}

				/* COLOR
				// int color = 255;
				// if (side == 1)
				// 	color = color / 4;
				// if (pool->map[map_x][map_y] == 1 || pool->map[map_x][map_y] == 2)
				// 	pool->map[map_x][map_y] == 1 ? SDL_SetRenderDrawColor(rend, color, 0, 0, SDL_ALPHA_OPAQUE) : SDL_SetRenderDrawColor(rend, 0, color, 0, SDL_ALPHA_OPAQUE);
				// if (pool->map[map_x][map_y] == 3 || pool->map[map_x][map_y] == 4)
				// 	pool->map[map_x][map_y] == 3 ? SDL_SetRenderDrawColor(rend, 0, 0, color, SDL_ALPHA_OPAQUE) : SDL_SetRenderDrawColor(rend, color, 0, color, SDL_ALPHA_OPAQUE);
				// if (pool->map[map_x][map_y] == 5)
				// 	pool->map[map_x][map_y] = SDL_SetRenderDrawColor(rend, 60, 0, color, SDL_ALPHA_OPAQUE);
				// if (pool->map[map_x][map_y] == 6)
				// 	pool->map[map_x][map_y] = SDL_SetRenderDrawColor(rend, 30, 30, 40, SDL_ALPHA_OPAQUE);
				// if (pool->map[map_x][map_y] == 7)
				// 	pool->map[map_x][map_y] = SDL_SetRenderDrawColor(rend, 60, 20, 20, SDL_ALPHA_OPAQUE);
				// if (pool->map[map_x][map_y] == 8)
				// 	pool->map[map_x][map_y] = SDL_SetRenderDrawColor(rend, 20, 30, 80, SDL_ALPHA_OPAQUE);
				// SDL_RenderDrawLine(rend, x, draw_start, x, draw_end);
				*/

				x++;
			}
			int wirina = 0;
			int ika = 0;
			int visota = 0;
			while (visota < H)
			{
				wirina = 0;
				while (wirina < W)
				{
					rend_arr[ika] = tex_arr[wirina][visota];
					tex_arr[wirina][visota] = 0;
					ika++;
					wirina++;
				}
				visota++;
			}
			SDL_UpdateTexture(screen_tex, NULL, rend_arr, (W * 4));
			ft_bzero(rend_arr, W * H);
			SDL_RenderCopy(rend, screen_tex, &SrcR, &DestR);
			old_time = time;
			time = SDL_GetTicks();
			double frameTime = (time - old_time) / 1000.0;
			double moveSpeed = frameTime * 4.0;
			double rotSpeed = frameTime * 3.0;
			
			SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE);

			SDL_RenderPresent(rend);
			SDL_RenderClear(rend);
			SDL_PollEvent(&event);
			if (event.type == SDL_QUIT)
				done = SDL_TRUE;
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.scancode == SDL_SCANCODE_UP || event.key.keysym.scancode == SDL_SCANCODE_W)
				{
					if (pool->map[(int)(pos_x + vector_x * moveSpeed)][(int)(pos_y)] == 0)
						pos_x += vector_x * moveSpeed;
					if (pool->map[(int)(pos_x)][(int)(pos_y + vector_y * moveSpeed)] == 0)
						pos_y += vector_y * moveSpeed;
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_DOWN || event.key.keysym.scancode == SDL_SCANCODE_S)
				{
					if (pool->map[(int)(pos_x - vector_x * moveSpeed)][(int)pos_y] == 0)
						pos_x -= vector_x * moveSpeed;
					if (pool->map[(int)(pos_x)][(int)(pos_y - vector_y * moveSpeed)] == 0)
						pos_y -= vector_y * moveSpeed;
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT || event.key.keysym.scancode == SDL_SCANCODE_D)
				{
					double	old_vector_x = vector_x;
					vector_x = vector_x * cos(-rotSpeed) - vector_y * sin(-rotSpeed);
					vector_y = old_vector_x * sin(-rotSpeed) + vector_y * cos(-rotSpeed);
					double	old_plane_x = plane_x;
					plane_x = plane_x * cos(-rotSpeed) - plane_y * sin(-rotSpeed);
					plane_y = old_plane_x * sin(-rotSpeed) + plane_y * cos(-rotSpeed);
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_LEFT || event.key.keysym.scancode == SDL_SCANCODE_A)
				{
					double	old_vector_x = vector_x;
					vector_x = vector_x * cos(rotSpeed) - vector_y * sin(rotSpeed);
					vector_y = old_vector_x * sin(rotSpeed) + vector_y * cos(rotSpeed);
					double	old_plane_x = plane_x;
					plane_x = plane_x * cos(rotSpeed) - plane_y * sin(rotSpeed);
					plane_y = old_plane_x * sin(rotSpeed) + plane_y * cos(rotSpeed);
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					done = SDL_TRUE;
			}
		}
		// int jopa = 0;
		// int jops2 = 0;
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		// while (pool->map[jopa])
		// {
		// 	free(pool->map[jopa]);
		// 	jopa++;
		// }
		free(pool);
	}
	else
		usage();
	return (0);
}
