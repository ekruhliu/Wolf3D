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
# include <SDL_timer.h>
# include <SDL_image.h>

# define We 640
# define He 480

typedef	struct	s_pool
{
	int len_map_x;
	int len_map_y;
	int	**map;	
}				t_pool;

void	usage(void);
void	error(void);

#endif

// SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
// SDL_RenderClear(rend);
// SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
// SDL_RenderDrawLines(rend, points, POINTS_COUNT);
// SDL_RenderPresent(rend);
