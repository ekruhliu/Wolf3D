/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:32:00 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/02 12:32:01 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define POINTS_COUNT 4

// static SDL_Point    points[POINTS_COUNT] = 
// {
//     {320, 200},
//     {300, 240},
//     {340, 240},
//     {320, 200}
// };

//  while (!done) 
//  {
//                 SDL_Event event;

//                 SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
//                 SDL_RenderClear(renderer);

//                 SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
//                 SDL_RenderDrawLines(renderer, points, POINTS_COUNT);
//                 SDL_RenderPresent(renderer);

//                 while (SDL_PollEvent(&event)) {
//                     if (event.type == SDL_QUIT) {
//                         done = SDL_TRUE;
//                     }
//                 }
//             }

// #include "wolf.h"

// #define WINDOW_WIDTH (640)
// #define WINDOW_HEIGHT (480)

// // speed in pixels/second
// #define SPEED (600)

// int main(void)
// {
//     // attempt to initialize graphics and timer system
//     if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
//     {
//         printf("error initializing SDL: %s\n", SDL_GetError());
//         return 1;
//     }

//     SDL_Window* win = SDL_CreateWindow("Hello, CS50!",
//                                        SDL_WINDOWPOS_CENTERED,
//                                        SDL_WINDOWPOS_CENTERED,
//                                        WINDOW_WIDTH, WINDOW_HEIGHT,0);
//     if (!win)
//     {
//         printf("error creating window: %s\n", SDL_GetError());
//         SDL_Quit();
//         return 1;
//     }

//     // create a renderer, which sets up the graphics hardware
//     Uint32 render_flags = SDL_RENDERER_ACCELERATED;
//     SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
//     if (!rend)
//     {
//       printf("error creating renderer: %s\n", SDL_GetError());
//       SDL_DestroyWindow(win);
//       SDL_Quit();
//       return 1;
//     }

//     // load the image into memory using SDL_image library function
//     SDL_Surface* surface = IMG_Load("resources/hello.png");
//     if (!surface)
//     {
//         printf("error creating surface\n");
//         SDL_DestroyRenderer(rend);
//         SDL_DestroyWindow(win);
//         SDL_Quit();
//         return 1;
//     }

//     // load the image data into the graphics hardware's memory
//     SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
//     SDL_FreeSurface(surface);
//     if (!tex)
//     {
//         printf("error creating texture: %s\n", SDL_GetError());
//         SDL_DestroyRenderer(rend);
//         SDL_DestroyWindow(win);
//         SDL_Quit();
//         return 1;
//     }

//     // struct to hold the position and size of the sprite
//     SDL_Rect dest;

//     // get and scale the dimensions of texture
//     SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
//     dest.w /= 4;
//     dest.h /= 4;

//     // start sprite in center of screen
//     float x_pos = (WINDOW_WIDTH - dest.w) / 2;
//     float y_pos = (WINDOW_HEIGHT - dest.h) / 2;
//     float x_vel = 0;
//     float y_vel = 0;

//     // set to 1 when window close button is pressed
//     int close_requested = 0;
    
//     // animation loop
//     while (!close_requested)
//     {
//         // process events
//         SDL_Event event;
//         while (SDL_PollEvent(&event))
//         {
//             if (event.type == SDL_QUIT)
//             {
//                 close_requested = 1;
//             }
//         }

//         // get cursor position relative to window
//         int mouse_x, mouse_y;
//         int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);

//         // determine velocity toward mouse
//         int target_x = mouse_x - dest.w / 2;
//         int target_y = mouse_y - dest.h / 2;
//         float delta_x = target_x - x_pos;
//         float delta_y = target_y - y_pos;
//         float distance = sqrt(delta_x * delta_x + delta_y * delta_y);
        
//         // prevent jitter
//         if (distance < 5)
//         {
//             x_vel = y_vel = 0;
//         }
//         else
//         {
//             x_vel = delta_x * SPEED / distance;
//             y_vel = delta_y * SPEED / distance;
//         }

//         // reverse velocity if mouse button 1 pressed
//         if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
//         {
//             x_vel = -x_vel;
//             y_vel = -y_vel;
//         }
        
//         // update positions
//         x_pos += x_vel / 60;
//         y_pos += y_vel / 60;

//         // collision detection with bounds
//         if (x_pos <= 0) x_pos = 0;
//         if (y_pos <= 0) y_pos = 0;
//         if (x_pos >= WINDOW_WIDTH - dest.w) x_pos = WINDOW_WIDTH - dest.w;
//         if (y_pos >= WINDOW_HEIGHT - dest.h) y_pos = WINDOW_HEIGHT - dest.h;

//         // set the positions in the struct
//         dest.y = (int) y_pos;
//         dest.x = (int) x_pos;
        
//         // clear the window
//         SDL_RenderClear(rend);

//         // draw the image to the window
//         SDL_RenderCopy(rend, tex, NULL, &dest);
//         SDL_RenderPresent(rend);

//         // wait 1/60th of a second
//         SDL_Delay(1000/60);
//     }
    
//     // clean up resources before exiting
//     SDL_DestroyTexture(tex);
//     SDL_DestroyRenderer(rend);
//     SDL_DestroyWindow(win);
//     SDL_Quit();
// }

#include "wolf.h"
#include <stdbool.h>
// #include "ft_sdl.h"
#include <SDL_image.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>

#define mapWidth 24
#define mapHeight 24

#define texH 64
#define texW 64

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,4,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int                 set_rgb(unsigned int r, unsigned int g, unsigned int b)
{
 return ((r << 16) | (g << 8) | b);
}

static int      get_col_by_i(void *ptr, int i)
{
    unsigned char *tmp;

    tmp = (unsigned char*)ptr;
    return (set_rgb(tmp[i + 2], tmp[i + 1], tmp[i]));
}

static void     ft_get_image(int *pixels, const char *path)
{
    SDL_Surface     *sur;
    int             i;
    int             size;
    int             k;

    i = -1;
    size = texH * texW;
    k = 0;
    sur = IMG_Load(path);
    while (++i < size)
    {
        pixels[i] = get_col_by_i(sur->pixels, k);
        k += 4;
    }
    SDL_FreeSurface(sur);
}

int main(int ac, char **av)
{
    int done = 0;
    double posX = 22;
    double posY = 12;
    double dirX = -1;
    double dirY = 0;
    double planeX = 0;
    double planeY = 0.66;
    double time = 0;
    double oldtime = 0;
    double sideDistX;
    double sideDistY;
    SDL_Rect srcrect;
    SDL_Rect dstrect;
    SDL_Rect sHUD;
    SDL_Rect dHUD;
    SDL_Rect sWEAP;
    SDL_Rect dWEAP;
    int flag = 0;
    Uint32 buffer[mapHeight][mapWidth];
    int count = 0;
    int delimetr = 1;
    int texcolor = 0;
    int arr[800][600];
    int zxc[800*600];
    SDL_PixelFormat *formaat;

// SDL_BlitSurface(src, &srcrect, dst, &dstrect);

srcrect.x = 0;
srcrect.y = 0;
srcrect.w = 800;
srcrect.h = 600;
dstrect.x = 0;
dstrect.y = 0;
dstrect.w = 800;
dstrect.h = 600;

sHUD.x = 0;
sHUD.y = 100;
sHUD.w = 1000;
sHUD.h = 1000;
dHUD.x = 0;
dHUD.y = 500;
dHUD.w = 800;
dHUD.h = 100;

sWEAP.x = 0;
sWEAP.y = 0;
sWEAP.w = 1000;
sWEAP.h = 1000;
dWEAP.x = 200;
dWEAP.y = 150;
dWEAP.w = 400;
dWEAP.h = 500;

    int stepX;
    int stepY;
    int w = 800;
    int h = 600;
    
    int color;
    int x = 0;
    int drawStart;
    int drawEnd;
    int *texture[4];
    texture[0] = (int*)malloc(sizeof(int) * (int)texH * (int)texW);
    texture[1] = (int*)malloc(sizeof(int) * (int)texH * (int)texW);
    texture[2] = (int*)malloc(sizeof(int) * (int)texH * (int)texW);
    texture[3] = (int*)malloc(sizeof(int) * (int)texH * (int)texW);
    ft_get_image(texture[0], "pics/eagle.png");
    ft_get_image(texture[1], "pics/greystone.png");
    ft_get_image(texture[2], "pics/redbrick.png");
    ft_get_image(texture[3], "pics/wood.png");
    // ft_get_image(texture[1], "pics/redbrick.png");
    // ft_get_image(texture[2], "pics/bluestone.png");
    // ft_get_image(texture[3], "pics/wood.png");
    SDL_Window* win = SDL_CreateWindow("Hello, MY SEMPAI!",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        w, h, SDL_WINDOW_FULLSCREEN);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, render_flags);
    SDL_Surface* surface = IMG_Load("hud.png");
    SDL_Surface* weaponsurf = IMG_Load("sr.png");
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Texture* fillscreen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, 800, 600);
    SDL_Texture* weapon = SDL_CreateTextureFromSurface(renderer, weaponsurf);
    SDL_FreeSurface(surface);
    while (!done)
    {
        x = 0;
        count = 0;
        while (x < w)
        {
            color = 255;
            double cameraX = 2 * x / (double)(w) - 1;
            double rayDirX = dirX + planeX * cameraX;
            double rayDirY = dirY + planeY * cameraX;

            int mapX = (int)posX;
            int mapY = (int)posY;

            double deltaDistX = fabs(1 / rayDirX);
            double deltaDistY = fabs(1 / rayDirY);
            double perpWallDist;

            int hit = 0;
            int side;

            if (rayDirX < 0)
            {
                stepX = -1;
                sideDistX = (posX - mapX) * deltaDistX;
            }
            else
            {
                stepX = 1;
                sideDistX = (mapX + 1.0 - posX) * deltaDistX;
            }
            if (rayDirY < 0)
            {
                stepY = -1;
                sideDistY = (posY - mapY) * deltaDistY;
            }
            else
            {
                stepY = 1;
                sideDistY = (mapY + 1.0 - posY) * deltaDistY;
            }
            while (hit == 0)
            {
                if (sideDistX < sideDistY)
                {
                    sideDistX += deltaDistX;
                    mapX += stepX;
                    side = 0;
                }
                else
                {
                    sideDistY += deltaDistY;
                    mapY += stepY;
                    side = 1;
                }
                worldMap[mapX][mapY] > 0 ? hit = 1 : 0;
            }
            if (side == 0)
                perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
            else
                perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
            int lineHeight = (int)(h / perpWallDist);
            drawStart = -lineHeight / 2 + h / 2;
            drawStart < 0 ? drawStart = 0 : 0;
            drawEnd = lineHeight / 2 + h / 2;
            drawEnd >= h ? drawEnd = h - 1 : 0;
            int texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!

            //calculate value of wallX
            double wallX; //where exactly the wall was hit
            if (side == 0) wallX = posY + perpWallDist * rayDirY;
            else           wallX = posX + perpWallDist * rayDirX;
            wallX -= floor((wallX));
        
            //x coordinate on the texture
            int texX = (int)(wallX * (double)(texW));
            if(side == 0 && rayDirX > 0) texX = texW - texX - 1;
            if(side == 1 && rayDirY < 0) texX = texW - texX - 1;
            int z = drawStart;
            int xcount = count;
            int ttt = 0;
            while (ttt < h) {
                arr[x][ttt] = 0;
                ttt++;
            }
            while(z < drawEnd)
            {
                int d = z * 256 - h * 128 + lineHeight * 128;
                int texY = ((d * texH) / lineHeight) / 256;
                xcount = (texH * texY + texX);
                // if(side == 1)
                // {
                //  delimetr = 2;
                //  if (worldMap[mapX][mapY] == 3)
                //      delimetr = 30;
                // }
                // side == 0 ? delimetr = 1 : 0;
                if (worldMap[mapX][mapY] == 2)
                    texcolor = 0;
                // //   SDL_SetRenderDrawColor(renderer, texture[0][xcount+2]/(256*256) / delimetr, (texture[0][xcount+1]/(256)) / delimetr, (texture[0][xcount]) / delimetr, SDL_ALPHA_OPAQUE);
                if (worldMap[mapX][mapY] == 3)
                    texcolor = 1;
                // //   SDL_SetRenderDrawColor(renderer, texture[1][xcount+2]/(256*256) - delimetr, (texture[1][xcount+1]/(256)) - delimetr, (texture[1][xcount]) - delimetr, SDL_ALPHA_OPAQUE);
                if (worldMap[mapX][mapY] == 1)
                    texcolor = 2;
                //  SDL_SetRenderDrawColor(renderer, texture[2][xcount+2]/(256*256) / delimetr, (texture[2][xcount+1]/(256)) / delimetr, (texture[2][xcount]) / delimetr, SDL_ALPHA_OPAQUE);
                if (worldMap[mapX][mapY] == 4)
                    texcolor = 3;
                //  SDL_SetRenderDrawColor(renderer, texture[3][xcount+2]/(256*256) / delimetr, (texture[3][xcount+1]/(256)) / delimetr, (texture[3][xcount]) / delimetr, SDL_ALPHA_OPAQUE);
                // SDL_RenderDrawPoint(renderer, x, z);
                // printf("%d\n", arr[0][0]);
                
                arr[x][z] = ((texture[texcolor][xcount]));
                // (side == 0 && texcolor == 1) ? arr[x][z] = ((texture[texcolor][xcount]) + 50 ) : 0;
                // (side == 1 && texcolor == 1) ? arr[x][z] = ((texture[texcolor][xcount]) - 10) : 0;
                // side == 0 ? arr[x][z] = ((texture[texcolor][xcount])) : 0;//(texture[texcolor][count+2] + texture[texcolor][count+1] + texture[texcolor][count]);
                z++;
            }
            // printf("HELLO\n");
            x++;
            count++;
        }

        int sdasd = 0;
        int width = 0;
        int height = 0;
        while (height < 600)
        {
            width = 0;
            while(width < 800)
            {
                zxc[sdasd] = arr[width][height];
                arr[width][height] = 0;
                sdasd++;
                width++;
            }
            height++;
        }
        SDL_UpdateTexture(fillscreen, NULL, zxc, 800*4);
        bzero(zxc, 800*600);
        oldtime = time;
        time = SDL_GetTicks();
        double frameTime = (time - oldtime) / 1000.0;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

        SDL_RenderCopy(renderer, fillscreen, &srcrect, &dstrect);
                SDL_RenderCopy(renderer, weapon, &sWEAP, &dWEAP);
        SDL_RenderCopy(renderer, tex, &sHUD, &dHUD);
        SDL_RenderPresent(renderer);        
        SDL_RenderClear(renderer);
        double moveSpeed = frameTime * 7.0;
        double rotSpeed = frameTime * 3.0;
        SDL_Event event;
        SDL_PollEvent(&event);
        event.type == SDL_QUIT ? done = 1 : 0;
        event.key.keysym.scancode == SDL_SCANCODE_ESCAPE ? done = 1 : 0;
        
        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.scancode == SDL_SCANCODE_UP)
            {
                worldMap[(int)(posX + dirX * moveSpeed)][(int)(posY)] == false ? posX += dirX * moveSpeed : 0;
                worldMap[(int)(posX)][(int)(posY + dirY * moveSpeed)] == false ? posY += dirY * moveSpeed : 0;
                                if (flag == 1)
                {
                    dWEAP.y+=2;
                    dWEAP.w+=2;
                    if (dWEAP.y == 150)
                        flag = 0;
                }
                if (flag == 0)
                {
                    dWEAP.y-=2;
                    dWEAP.w-=2;
                    if (dWEAP.y == 120)
                        flag = 1;
                }
            }
            if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
            {
                worldMap[(int)(posX - dirX * moveSpeed)][(int)(posY)] == false ? posX -= dirX * moveSpeed : 0;
                worldMap[(int)(posX)][(int)(posY - dirY * moveSpeed)] == false ? posY -= dirY * moveSpeed : 0;
                if (flag == 1)
                {
                    dWEAP.y+=2;
                    dWEAP.w+=2;
                    if (dWEAP.y == 150)
                        flag = 0;
                }
                if (flag == 0)
                {
                    dWEAP.y-=2;
                    dWEAP.w-=2;
                    if (dWEAP.y == 120)
                        flag = 1;
                }
            }
            if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
            {
                double oldDirX = dirX;
                dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
                dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
                double oldPlaneX = planeX;
                planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
                planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
                                if (flag == 1)
                {
                    dWEAP.y+=2;
                    dWEAP.w+=2;
                    if (dWEAP.y == 150)
                        flag = 0;
                }
                if (flag == 0)
                {
                    dWEAP.y-=2;
                    dWEAP.w-=2;
                    if (dWEAP.y == 120)
                        flag = 1;
                }
            }
            if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
            {
                double oldDirX = dirX;
                dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
                dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
                double oldPlaneX = planeX;
                planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
                planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
                                if (flag == 1)
                {
                    dWEAP.y+=2;
                    dWEAP.w+=2;
                    if (dWEAP.y == 150)
                        flag = 0;
                }
                if (flag == 0)
                {
                    dWEAP.y-=2;
                    dWEAP.w-=2;
                    if (dWEAP.y == 120)
                        flag = 1;
                }
            }
        }
    }
}





                /* COLOR
                // int color = 255;
                // if (side == 1)
                //  color = color / 4;
                // if (pool->map[map_x][map_y] == 1 || pool->map[map_x][map_y] == 2)
                //  pool->map[map_x][map_y] == 1 ? SDL_SetRenderDrawColor(rend, color, 0, 0, SDL_ALPHA_OPAQUE) : SDL_SetRenderDrawColor(rend, 0, color, 0, SDL_ALPHA_OPAQUE);
                // if (pool->map[map_x][map_y] == 3 || pool->map[map_x][map_y] == 4)
                //  pool->map[map_x][map_y] == 3 ? SDL_SetRenderDrawColor(rend, 0, 0, color, SDL_ALPHA_OPAQUE) : SDL_SetRenderDrawColor(rend, color, 0, color, SDL_ALPHA_OPAQUE);
                // if (pool->map[map_x][map_y] == 5)
                //  pool->map[map_x][map_y] = SDL_SetRenderDrawColor(rend, 60, 0, color, SDL_ALPHA_OPAQUE);
                // if (pool->map[map_x][map_y] == 6)
                //  pool->map[map_x][map_y] = SDL_SetRenderDrawColor(rend, 30, 30, 40, SDL_ALPHA_OPAQUE);
                // if (pool->map[map_x][map_y] == 7)
                //  pool->map[map_x][map_y] = SDL_SetRenderDrawColor(rend, 60, 20, 20, SDL_ALPHA_OPAQUE);
                // if (pool->map[map_x][map_y] == 8)
                //  pool->map[map_x][map_y] = SDL_SetRenderDrawColor(rend, 20, 30, 80, SDL_ALPHA_OPAQUE);
                // SDL_RenderDrawLine(rend, x, draw_start, x, draw_end);
                */