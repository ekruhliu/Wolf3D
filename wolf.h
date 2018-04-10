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

// typedef struct	s_surfs
// {

// }				t_surfs;

typedef	struct	s_pool
{
	int				len_map_x;
	int				len_map_y;
	int				**map;
	int				*textures[8];
	// t_surfs			*surfs;
}				t_pool;



void	usage(void);
void	error(void);
void	map_widthe(char *argv, t_pool *pool);
void	map_height(char *argv, t_pool *pool);
char	*read_file(char *argv);
void	create_map(char *argv, t_pool *pool);
// int		showmenu(SDL_Surface* screen, TTF_Font* font);
void	make_textures(int *textures, const char *file);

#endif
