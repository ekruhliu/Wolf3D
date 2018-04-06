/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:00:10 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/02 13:00:11 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <SDL.h>
# include "./libSDL/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include <SDL_timer.h>
# include <SDL_image.h>
# include <math.h>

# define W 1024
# define H 768
# define texture_W 64
# define texture_H 64

typedef	struct	s_pool
{
	int				len_map_x;
	int				len_map_y;
	int				**map;
	SDL_Surface		**wall_texture;
	SDL_Surface 	*surface;
}				t_pool;

// typedef struct	s_masks
// {
// 	Uint_32	rmask;
// 	Uint_32	gmask;
// 	Uint_32	bmask;
// 	Uint_32	amask;
// }				t_masks;

void	usage(void);
void	error(void);
void	map_widthe(char *argv, t_pool *pool);
void	map_height(char *argv, t_pool *pool);
char	*read_file(char *argv);
void	create_map(char *argv, t_pool *pool);
int		showmenu(SDL_Surface* screen, TTF_Font* font);

#endif

// SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
// SDL_RenderClear(rend);
// SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
// SDL_RenderDrawLines(rend, points, POINTS_COUNT);
// SDL_RenderPresent(rend);
