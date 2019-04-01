/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:47:09 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/04 12:17:53 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_rt_prototype.h"

int	sdl_loop(SDL_Event *event, SDL_Surface *img)
{
	int run;

	run = 1;
	while (run)
	{
		while (SDL_PollEvent(event))
		{
			if (event->type == SDL_QUIT)
				return (1);
			else if (event->type == SDL_KEYDOWN)
			{
				if (event->key.keysym.sym == SDLK_s)
				{
					ft_putstr("Saving image\n");
					SDL_SaveBMP(img, "img.bmp");
				}
				if (event->key.keysym.sym == SDLK_ESCAPE)
					return (1);
			}
		}
	}
	return (0);
}

int	sdl_render(t_colour **buff, t_options opts)
{
	SDL_Window	*win;
	SDL_Surface	*win_surf;
	SDL_Surface	*img;
	SDL_Event	event;

	if (0 > SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO))
		ft_putstr("error\n");
	win = SDL_CreateWindow("RayTracer", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, opts.pix_width, opts.pix_height,
			SDL_WINDOW_RESIZABLE);
	win_surf = SDL_GetWindowSurface(win);
	img = SDL_CreateRGBSurface(0, opts.pix_width, opts.pix_height,
			32, 0, 0, 0, 0);
	col_sdl_fill_surface(img, buff);
	SDL_BlitSurface(img, NULL, win_surf, NULL);
	SDL_UpdateWindowSurface(win);
	sdl_loop(&event, img);
	SDL_FreeSurface(img);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}
