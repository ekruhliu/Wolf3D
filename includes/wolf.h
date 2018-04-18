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
# include "../libSDL/SDL2.framework/Headers/SDL_timer.h"
# include "../libSDL/SDL2_image.framework/Headers/SDL_image.h"
# include <math.h>
# include <time.h>

# define W 1024
# define H 768
# define TEXTURE_W pool->texture_w
# define TEXTURE_H pool->texture_h
# define F_S SDL_WINDOW_FULLSCREEN
# define WIN pool->sdl->win
# define TEX_FMR_SRF SDL_CreateTextureFromSurface
# define REND_ARR pool->sdl->rend_arr
# define RENDER_FLAG pool->sdl->render_flags
# define RENDER pool->sdl->rend
# define SCREEN_TEX pool->sdl->screen_tex
# define TEX_IN SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET
# define WINDOW_IN SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED
# define SPACE pool->sdl->event.key.keysym.scancode == SDL_SCANCODE_SPACE
# define PISTOL pool->weapon->pistol
# define PISTOL_ATTACK pool->weapon->pistol_attack_tex
# define KNIFE pool->weapon->knife
# define KNIFE_ATTACK pool->weapon->knife_attack_tex
# define MP40 pool->weapon->mp40
# define MP40_ATTACK pool->weapon->mp40_attack_tex
# define SHOTGUN pool->weapon->shotgun
# define SHOTGUN_ATTACK pool->weapon->shotgun_attack_tex
# define CHAINSAW pool->weapon->chainsaw
# define MAP pool->map
# define POS_X pool->pos_x
# define POS_Y pool->pos_y
# define VECTOR_X pool->vector_x
# define VECTOR_Y pool->vector_y
# define MOVE_SPEED pool->move_speed
# define ROT_SPEED pool->rot_speed
# define PLANE_X pool->plane_x
# define PLANE_Y pool->plane_y
# define KEY_STATE pool->sdl->keyboard_state
# define MAP_X pool->ray_cast->map_x
# define MAP_Y pool->ray_cast->map_y
# define KEY_SCANCODE pool->sdl->event.key.keysym.scancode
# define CHECK pool->check = check_attack(pool) == 0
# define EVENT_TYPE pool->sdl->event.type
# define DONE pool->sdl->done
# define HIT pool->ray_cast->hit
# define CAMERA_X pool->camera_x
# define RAY_VECTOR_X pool->ray_vector_x
# define RAY_VECTOR_Y pool->ray_vector_y
# define DELTA_VECTOR_X pool->ray_cast->delta_vector_x
# define DELTA_VECTOR_Y pool->ray_cast->delta_vector_y
# define STEP_X pool->ray_cast->step_x
# define STEP_Y pool->ray_cast->step_y
# define SIDE_VECTOR_X pool->ray_cast->side_vector_x
# define SIDE_VECTOR_Y pool->ray_cast->side_vector_y
# define SIDE pool->ray_cast->side
# define RAY_LONG_VECTOR pool->ray_cast->ray_long_vector
# define LINE_HEIGHT pool->ray_cast->line_height
# define DRAW_START pool->ray_cast->draw_start
# define DRAW_END pool->ray_cast->draw_end
# define POSITION pool->draw_tex->position
# define TEXT_NUM pool->draw_tex->text_num
# define TEXT_ARR pool->sdl->tex_arr
# define Y pool->draw_tex->y
# define WALL_X  pool->draw_tex->wall_x
# define TEX_X pool->draw_tex->tex_x
# define TEX_Y pool->draw_tex->tex_y
# define FLOOR_X_WALL pool->draw_tex->floor_x_wall
# define FLOOR_Y_WALL pool->draw_tex->floor_y_wall
# define DIST_WALL pool->draw_tex->dist_wall
# define DIST_PLAYER pool->draw_tex->dist_player
# define FUCK pool->bar->fuck
# define REND_CPY SDL_RenderCopy
# define CURR_DIST pool->draw_tex->current_dist
# define WEIGHT pool->draw_tex->weight
# define CURR_FLOOR_X pool->draw_tex->current_floor_x
# define CURR_FLOOR_Y pool->draw_tex->current_floor_y
# define FLOOR_TEX_X pool->draw_tex->floor_tex_x
# define FLOOR_TEX_Y pool->draw_tex->floor_tex_y
# define FLOOR_POS TEXTURE_W * FLOOR_TEX_Y + FLOOR_TEX_X
# define WEAPON pool->weapon
# define BAR pool->bar
# define D_MP40_ATT dst_mp40_att
# define D_PS_ATT dst_pist_att
# define D_SGUN dst_shotgun
# define D_CNS dst_chainsaw
# define D_CNS_ATT dst_chainsaw_att
# define TEXTURE pool->textures
# define SRC_R pool->sdl->src_r

typedef struct		s_bar
{
	SDL_Surface		*face_img;
	SDL_Surface		*health_img;
	SDL_Surface		*arms_img;
	SDL_Surface		*fuck_img;
	SDL_Texture		*face;
	SDL_Texture		*health;
	SDL_Texture		*arms;
	SDL_Texture		*fuck;
	SDL_Rect		dst_face;
	SDL_Rect		dst_health;
	SDL_Rect		dst_arms;
	SDL_Rect		dst_fuck;
	int				act_fuck;
}					t_bar;

typedef	struct		s_weapon
{
	SDL_Surface		*pistol_img;
	SDL_Surface		*pistol_attack_img;
	SDL_Surface		*knife_img;
	SDL_Surface		*knife_attack_img;
	SDL_Surface		*shotgun_img;
	SDL_Surface		*shotgun_attack_img;
	SDL_Surface		*mp40_img;
	SDL_Surface		*mp40_attack_img;
	SDL_Surface		*chainsaw_img;
	SDL_Texture		*knife;
	SDL_Texture		*pistol;
	SDL_Texture		*mp40;
	SDL_Texture		*shotgun;
	SDL_Texture		*chainsaw;
	SDL_Texture		*knife_attack_tex;
	SDL_Texture		*pistol_attack_tex;
	SDL_Texture		*mp40_attack_tex;
	SDL_Texture		*shotgun_attack_tex;
	SDL_Rect		dst_pist;
	SDL_Rect		dst_knife;
	SDL_Rect		dst_mp40;
	SDL_Rect		dst_pist_att;
	SDL_Rect		dst_mp40_att;
	SDL_Rect		dst_shotgun;
	SDL_Rect		dst_chainsaw;
	SDL_Rect		dst_chainsaw_att;
	int				act_pistol;
	int				act_knife;
	int				act_mp40;
	int				act_shotgun;
	int				act_chainsaw;
	int				knife_attack;
	int				pistol_attack;
	int				mp40_attack;
	int				shotgun_attack;
	int				chainsaw_attack;
}					t_weapon;

typedef	struct		s_ray_cast
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
	double			ray_long_vector;
}					t_ray_cast;

typedef	struct		s_sdl
{
	SDL_Event		event;
	SDL_Window		*win;
	SDL_bool		done;
	SDL_Renderer	*rend;
	SDL_Rect		src_r;
	SDL_Rect		dst_r;
	SDL_Texture		*screen_tex;
	const Uint8		*keyboard_state;
	Uint32			render_flags;
	Uint32			tex_arr[W][H];
	Uint32			rend_arr[W * H];
	const	char	*driver_name;
}					t_sdl;

typedef	struct		s_draw_tex
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
}					t_draw_tex;

typedef	struct		s_doors
{
	int				blue_door_x;
	int				blue_door_y;
	long			time_door;
}					t_doors;

typedef	struct		s_pool
{
	double		time;
	double		old_time;
	int			len_map_x;
	int			len_map_y;
	int			**map;
	int			*textures[22];
	double		pos_x;
	double		pos_y;
	double		vector_x;
	double		vector_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		ray_vector_x;
	double		ray_vector_y;
	double		frame_time;
	double		move_speed;
	double		rot_speed;
	int			check;
	int			speed_val;
	int			mp;
	int			texture_w;
	int			texture_h;
	t_sdl		*sdl;
	t_ray_cast	*ray_cast;
	t_draw_tex	*draw_tex;
	t_bar		*bar;
	t_weapon	*weapon;
	t_doors		*doors;
}					t_pool;

void				usage(void);
void				error(void);
void				map_widthe(char *argv, t_pool *pool);
void				map_height(char *argv, t_pool *pool);
char				*read_file(char *argv);
void				create_map(char *argv, t_pool *pool);
void				cleaner(t_pool *pool);
void				create_textures(t_pool *pool);
void				initialization(t_pool *pool);
void				ray_casting(t_pool *pool, int x);
void				draw_textures(t_pool *pool, int x);
void				from_nth_to_texture(t_pool *pool);
void				keys(t_pool *pool);
void				time_and_speed(t_pool *pool);
void				go_ahead(t_pool *pool);
void				go_back(t_pool *pool);
void				turn_right(t_pool *pool);
void				turn_left(t_pool *pool);
void				draw_floor_and_ceiling(t_pool *pool, int x);
void				clear_weapon(t_pool *pool);
int					check_attack(t_pool *pool);
void				init_bar(t_pool *pool);
void				clear_surfs(t_pool *pool);
void				init_weapon(t_pool *pool);
void				draw_weapon_and_bar(t_pool *pool);
void				init_textures(t_pool *pool);
void				make_textures(t_pool *pool, int *texture, const char *file);
void				shots(t_pool *pool);
void				n_s_e_w(t_pool *pool, int x);
void				check_mand(t_pool *pool, char *argv);
void				draw_weapon_and_bar(t_pool *pool);

#endif
