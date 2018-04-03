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

#define mapWidthe 24
#define mapHeight 24

// int worldMap[mapWidthe][mapHeight]=
// {
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
// 	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
// 	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };

void	map_widthe(char *argv, t_pool *pool)
{
	int		widthe;
	int		fd;
	char	**tab;

	widthe = 0;
	fd = open(argv, O_RDONLY);
	if (get_next_line(fd, &argv) <= 0)
		error();
	free(argv);
	tab = ft_strsplit(argv, ' ');
	while (tab[widthe])
		widthe++;
	while (get_next_line(fd, &argv) > 0)
		free(argv);
	free(argv);
	close(fd);
	pool->len_map_x = widthe;
}

void	map_height(char *argv, t_pool *pool)
{
	int fd;
	int height;

	height = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &argv) > 0)
	{
		height++;
		free(argv);
	}
	free(argv);
	close(fd);
	pool->len_map_y = height;
}

char		*read_file(char *argv)
{
	char	*res;
	char	*tmp;
	int		read_res;
	int		fd;

	fd = open(argv, O_RDONLY);
	res = ft_strdup("\0");
	while ((read_res = get_next_line(fd, &argv)) > 0)
	{
		tmp = ft_strdup(res);
		free(res);
		res = ft_strjoin(tmp, " ");
		free(tmp);
		tmp = ft_strdup(res);
		free(res);
		res = ft_strjoin(tmp, argv);
		free(tmp);
		free(argv);
	}
	free(argv);
	close(fd);
	return (res);
}

void	create_map(char *argv, t_pool *pool)
{
	int		i;
	int		n;
	char	*line;
	char	**tab;
	int 	elem = 0;

	i = 0;
	n = 0;
	printf("Y -> %d\n", pool->len_map_y);
	printf("X -> %d\n", pool->len_map_x);
	pool->map = (int**)malloc(sizeof(int*) * pool->len_map_y);
	while (i < pool->len_map_y)
	{
		pool->map[i] = (int*)malloc(sizeof(int) * pool->len_map_x);
		i++;
	}
	i = 0;
	line = read_file(argv);
	printf("%s\n", line);
	tab = ft_strsplit(line, ' ');
	free(line);
	while (i < pool->len_map_y)
	{
		n = 0;
		while (n < pool->len_map_x)
		{
			pool->map[i][n] = ft_atoi(tab[elem]);
			printf("elem - > %d ", pool->map[i][n]);
			elem++;
			n++;
		}
		i++;
	}
	printf("\n");
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	i = 0;
	while (i < pool->len_map_y)
	{
		n = 0;
		while (n < pool->len_map_x)
		{
			printf("%d ", pool->map[i][n]);
			n++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1 && argv[1])
	{
		t_pool	*pool;
		pool = malloc(sizeof(t_pool));
		// double	pos_x;
		// double	pos_y;
		// double	vector_x;
		// double	vector_y;
		// double	plane_x;
		// double	plane_y;
		// int		x;
		// SDL_Event	event;
		// double			camera_x;
		// double			ray_vector_x;
		// double			ray_vector_y;
		SDL_Window*		win;
		SDL_bool		done;
		Uint32			render_flags;
		SDL_Renderer*	rend;
		// double			time = 0;
		// double			old_time = 0;

		// pos_x = 22;
		// pos_y = 12;
		// vector_y = 0;
		// vector_x = -1;
		// plane_x = 0;
		// plane_y = 0.66;
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			ft_putstr("\033[1;31mError initializing SDL\n\e[m");
			return (1);
		}
		win = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, We, He, 0);
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
		map_widthe(argv[1], pool);
		map_height(argv[1], pool);
		create_map(argv[1], pool);
		done = SDL_FALSE;
		// while (!done)
		// {
		// 	x = 0;
		// 	while (x < We)
		// 	{
		// 		int color = 255;
		// 		camera_x = 2 * x / (double)We - 1;
		// 		ray_vector_x = vector_x + plane_x * camera_x;
		// 		ray_vector_y = vector_y + plane_y * camera_x;
		// 		int map_x = (int)pos_x;
		// 		int map_y = (int)pos_y;
				
		// 		double	side_vector_x;
		// 		double	side_vector_y;

		// 		double	delta_vector_x = fabs(1 / ray_vector_x);
		// 		double	delta_vector_y = fabs(1 / ray_vector_y);
		// 		double	perp_wall_vector;

		// 		int step_x;
		// 		int step_y;

		// 		int hit = 0;
		// 		int side;
		// 		if (ray_vector_x < 0)
		// 		{
		// 			step_x = -1;
		// 			side_vector_x = (pos_x - map_x) * delta_vector_x;
		// 		}
		// 		else
		// 		{
		// 			step_x = 1;
		// 			side_vector_x = (map_x + 1.0 - pos_x) * delta_vector_x;
		// 		}
		// 		if (ray_vector_y < 0)
		// 		{
		// 			step_y = -1;
		// 			side_vector_y = (pos_y - map_y) * delta_vector_y;
		// 		}
		// 		else
		// 		{
		// 			step_y = 1;
		// 			side_vector_y = (map_y + 1.0 - pos_y) * delta_vector_y;
		// 		}
		// 		while (hit == 0)
		// 		{
		// 			if (side_vector_x < side_vector_y)
		// 			{
		// 				side_vector_x += delta_vector_x;
		// 				map_x += step_x;
		// 				side = 0;
		// 			}
		// 			else
		// 			{
		// 				side_vector_y += delta_vector_y;
		// 				map_y += step_y;
		// 				side = 1;
		// 			}
		// 			if (pool->map[map_x][map_y] > 0)
		// 				hit = 1;
		// 		}
		// 		if (side == 0)
		// 			perp_wall_vector = (map_x - pos_x + (1 - step_x) / 2) / ray_vector_x;
		// 		else
		// 			perp_wall_vector = (map_y - pos_y + (1 - step_y) / 2) / ray_vector_y;
		// 		int line_height = (int)(He / perp_wall_vector);
		// 		int draw_start = -line_height / 2 + He / 2;
		// 		if (draw_start < 0)
		// 			draw_start = 0;
		// 		int draw_end = line_height / 2 + He / 2;
		// 		if (draw_end >= He)
		// 			draw_end = He - 1;
		// 		if (side == 1)
		// 			color = color / 4;
		// 		if (pool->map[map_x][map_y] == 1 || pool->map[map_x][map_y] == 2)
		// 			pool->map[map_x][map_y] == 1 ? SDL_SetRenderDrawColor(rend, color, 0, 0, SDL_ALPHA_OPAQUE) : SDL_SetRenderDrawColor(rend, 0, color, 0, SDL_ALPHA_OPAQUE);
		// 		if (pool->map[map_x][map_y] == 3 || pool->map[map_x][map_y] == 4)
		// 			pool->map[map_x][map_y] == 3 ? SDL_SetRenderDrawColor(rend, 0, 0, color, SDL_ALPHA_OPAQUE) : SDL_SetRenderDrawColor(rend, color, 0, color, SDL_ALPHA_OPAQUE);
		// 		if (pool->map[map_x][map_y] == 5)
		// 			pool->map[map_x][map_y] = SDL_SetRenderDrawColor(rend, 60, 0, color, SDL_ALPHA_OPAQUE);

		// 		SDL_RenderDrawLine(rend, x, draw_start, x, draw_end);
		// 		x++;
		// 	}
		// 	old_time = time;
		// 	time = SDL_GetTicks();
		// 	double frameTime = (time - old_time) / 1000.0;
		// 	double moveSpeed = frameTime * 4.0;
		// 	double rotSpeed = frameTime * 3.0;
		// 	SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
		// 	SDL_RenderPresent(rend);
		// 	SDL_RenderClear(rend);
		// 	SDL_PollEvent(&event);
		// 	if (event.type == SDL_QUIT)
		// 		done = SDL_TRUE;
		// 	if (event.type == SDL_KEYDOWN)
		// 	{
		// 		if (event.key.keysym.scancode == SDL_SCANCODE_UP || event.key.keysym.scancode == SDL_SCANCODE_W)
		// 		{
		// 			if (pool->map[(int)(pos_x + vector_x * moveSpeed)][(int)(pos_y)] == 0)
		// 				pos_x += vector_x * moveSpeed;
		// 			if (pool->map[(int)(pos_x)][(int)(pos_y + vector_y * moveSpeed)] == 0)
		// 				pos_y += vector_y * moveSpeed;
		// 		}
		// 		if (event.key.keysym.scancode == SDL_SCANCODE_DOWN || event.key.keysym.scancode == SDL_SCANCODE_S)
		// 		{
		// 			if (pool->map[(int)(pos_x - vector_x * moveSpeed)][(int)pos_y] == 0)
		// 				pos_x -= vector_x * moveSpeed;
		// 			if (pool->map[(int)(pos_x)][(int)(pos_y - vector_y * moveSpeed)] == 0)
		// 				pos_y -= vector_y * moveSpeed;
		// 		}
		// 		if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT || event.key.keysym.scancode == SDL_SCANCODE_D)
		// 		{
		// 			double	old_vector_x = vector_x;
		// 			vector_x = vector_x * cos(-rotSpeed) - vector_y * sin(-rotSpeed);
		// 			vector_y = old_vector_x * sin(-rotSpeed) + vector_y * cos(-rotSpeed);
		// 			double	old_plane_x = plane_x;
		// 			plane_x = plane_x * cos(-rotSpeed) - plane_y * sin(-rotSpeed);
		// 			plane_y = old_plane_x * sin(-rotSpeed) + plane_y * cos(-rotSpeed);
		// 		}
		// 		if (event.key.keysym.scancode == SDL_SCANCODE_LEFT || event.key.keysym.scancode == SDL_SCANCODE_A)
		// 		{
		// 			double	old_vector_x = vector_x;
		// 			vector_x = vector_x * cos(rotSpeed) - vector_y * sin(rotSpeed);
		// 			vector_y = old_vector_x * sin(rotSpeed) + vector_y * cos(rotSpeed);
		// 			double	old_plane_x = plane_x;
		// 			plane_x = plane_x * cos(rotSpeed) - plane_y * sin(rotSpeed);
		// 			plane_y = old_plane_x * sin(rotSpeed) + plane_y * cos(rotSpeed);
		// 		}
		// 		if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		// 			done = SDL_TRUE;
		// 	}
		// }
		free(pool);
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
	}
	else
		usage();
}
