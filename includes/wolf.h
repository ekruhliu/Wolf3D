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

# include "../libft/libft.h"
# include <fcntl.h>
# include "../libSDL/SDL2.framework/Headers/SDL.h"
// # include "./libSDL/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "../libSDL/SDL2.framework/Headers/SDL_timer.h"
# include "../libSDL/SDL2_image.framework/Headers/SDL_image.h"
# include <math.h>
# include <time.h>

# define W 1024
# define H 768
# define texture_W 64
# define texture_H 64

# define TEX_FMR_SRF SDL_CreateTextureFromSurface
# define SPACE pool->sdl->event.key.keysym.scancode == SDL_SCANCODE_SPACE

typedef struct	s_bar
{
	SDL_Surface* face_img;
	SDL_Surface* health_img;
	SDL_Surface* arms_img;
	SDL_Surface* fuck_img;
	SDL_Texture* face;
	SDL_Texture* health;
	SDL_Texture* arms;
	SDL_Texture* fuck;
	SDL_Rect	Sface;
	SDL_Rect	Dface;
	SDL_Rect	Shealth;
	SDL_Rect	Dhealth;
	SDL_Rect	Sarms;
	SDL_Rect	Darms;
	SDL_Rect	Sfuck;
	SDL_Rect	Dfuck;
	int			act_fuck;
}				t_bar;

typedef struct	s_weapon
{
	SDL_Surface*	pistol_img;
	SDL_Surface*	pistol_attack_img;
	SDL_Surface*	knife_img;
	SDL_Surface*	knife_attack_img;
	SDL_Surface*	shotgun_img;
	SDL_Surface*	shotgun_attack_img;
	SDL_Surface*	mp40_img;
	SDL_Surface*	mp40_attack_img;
	SDL_Texture*	knife;
	SDL_Texture*	pistol;
	SDL_Texture*	mp40;
	SDL_Texture*	shotgun;
	SDL_Texture*	knife_attack_tex;
	SDL_Texture*	pistol_attack_tex;
	SDL_Texture*	mp40_attack_tex;
	SDL_Texture*	shotgun_attack_tex;
	SDL_Rect		Spist;
	SDL_Rect		Dpist;
	SDL_Rect		Sknife;
	SDL_Rect		Dknife;
	SDL_Rect		Smp40;
	SDL_Rect		Dmp40;
	SDL_Rect		Spist_att;
	SDL_Rect		Dpist_att;
	SDL_Rect		Smp40_att;
	SDL_Rect		Dmp40_att;
	SDL_Rect		Sshotgun;
	SDL_Rect		Dshotgun;
	int				act_pistol;
	int				act_knife;
	int				act_mp40;
	int				act_shotgun;
	int				knife_attack;
	int				pistol_attack;
	int				mp40_attack;
	int				shotgun_attack;
}				t_weapon;

typedef	struct	s_ray_cast
{
	int				hit;
	int				side;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			side_vector_x;
	double			side_vector_y;
	double			delta_vector_x;
	double			delta_vector_y;
	double			perp_wall_vector;
}				t_ray_cast;

typedef struct	s_sdl
{
	SDL_Event		event;
	SDL_Window*		win;
	SDL_bool		done;
	SDL_Renderer*	rend;
	SDL_Rect		SrcR;
	SDL_Rect		DestR;
	SDL_Texture*	screen_tex;
	const Uint8		*keyboard_state;
	Uint32			render_flags;
	Uint32			tex_arr[W][H];
	Uint32			rend_arr[W * H];
}				t_sdl;

typedef	struct	s_draw_tex
{
	double			wall_x;
	int				y;
	int				d;
	int				tex_x;
	int				tex_y;
	int				position;
	int				text_num;
	double			floor_x_wall;
	double			floor_y_wall;
	double			dist_wall;
	double			dist_player;
	double			current_dist;
	int				floor_tex_x;
	int				floor_tex_y;
	double			weight;
	double			current_floor_x;
	double			current_floor_y;
}				t_draw_tex;

typedef struct	s_doors
{
	int				blue_door_x;
	int				blue_door_y;
	long			time_door;
}				t_doors;

typedef	struct	s_pool
{
	double			time;
	double			old_time;
	int				len_map_x;
	int				len_map_y;
	int				**map;
	int				*textures[22];
	double			pos_x;
	double			pos_y;
	double			vector_x;
	double			vector_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_vector_x;
	double			ray_vector_y;
	double			frame_time;
	double			move_speed;
	double			rot_speed;
	int				check;
	int				speed_val;
	int				mp;
	t_sdl			*sdl;
	t_ray_cast		*ray_cast;
	t_draw_tex		*draw_tex;
	t_bar			*bar;
	t_weapon		*weapon;
	t_doors			*doors;
}				t_pool;



void	usage(void);
void	error(void);
void	map_widthe(char *argv, t_pool *pool);
void	map_height(char *argv, t_pool *pool);
char	*read_file(char *argv);
void	create_map(char *argv, t_pool *pool);
void	cleaner(t_pool *pool);
void	create_textures(t_pool *pool);
void	initialization(t_pool *pool);
void	ray_casting(t_pool *pool, int x);
void	draw_textures(t_pool *pool, int x);
void	from_nth_to_texture(t_pool *pool);
void	keys(t_pool *pool);
void	time_and_speed(t_pool *pool);
void	go_ahead(t_pool *pool);
void	go_back(t_pool *pool);
void	turn_right(t_pool *pool);
void	turn_left(t_pool *pool);
void	draw_floor_and_ceiling(t_pool *pool, int x);
void	clear_weapon(t_pool *pool);
int		check_attack(t_pool *pool);
void	init_bar(t_pool *pool);
void	clear_surfs(t_pool *pool);
void	init_weapon(t_pool *pool);
void	draw_weapon_and_bar(t_pool *pool);
void	init_textures(t_pool *pool);
void	make_textures(int *textures, const char *file);
void	shots(t_pool *pool);
void	n_s_e_w(t_pool *pool, int x);

#endif
