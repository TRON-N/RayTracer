/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 11:37:28 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/10/04 16:24:23 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_rt_prototype.h"

t_colour	quant(t_colour c)
{
	return (col_split_int(col_to_int(c)));
}

int		error_checks(t_thread_info *main_info, int argc, char **argv,
		t_colour ***buff2)
{
	int i;

	i = -1;
	if (argc != 2)
	{
		ft_putendl("No file given, usage: ./RT file");
		return (-1);
	}
	if ((init_scene_info(argv[1], &main_info->scene_info)) == -1)
		return (-1);
	main_info->opts = main_info->scene_info.opts;
	if (init_buff(&(main_info->opts), &(main_info->buff)))
	{
		ft_putendl("Could not initalize buffer.");
		return (-1);
	}
	if ((*buff2 = (t_colour **)malloc(main_info->opts.pix_height *
		sizeof(t_colour *))) == NULL)
	{
		ft_putendl("Could not initalize buffer2.");
		return (-1);
	}
	while (++i < main_info->opts.pix_height)
			if ((*(*buff2 + i) = (t_colour *)malloc(sizeof(t_colour) *
				main_info->opts.pix_width)) == NULL)
			{
				ft_putendl("Could not initalize buffer2.");
				return (-1);
			}
	return (1);
}

int		main(int argc, char **argv) {
	SDL_sem			*sem;
	t_thread_info	main_info;
	t_thread_info	thread_info[THREAD_NUM];
	SDL_Thread		*thread[THREAD_NUM];
	t_colour		**buff2;
	int				indx;

	sem = SDL_CreateSemaphore(0);

	indx = -1;
	ft_putendl("Initilizing Ray Tracer");
	if (error_checks(&main_info, argc, argv, &buff2) == -1)
		return (0);
	if (init_thread_info(thread_info, main_info, argv[1]) == -1)
		return (0);
	
	printf("Creating %i threads\n", THREAD_NUM);
	while (++indx < THREAD_NUM) {
		// Increment Semaphore
		SDL_SemPost(sem);
		// Add Semaphore information so we can remove this thread from it later
		(thread_info[indx]).sem = sem;
		thread[indx] = SDL_CreateThread( start_primary_rays, ft_itoa(indx), &thread_info[indx] );
	}

	show_render_progress(thread_info, main_info.opts);
	int *ret[THREAD_NUM];
	indx = -1;
	
	// Wait until Semaphore value is 0 before moving on
	while ( SDL_SemValue(sem) > 0) {
		SDL_Delay(1);
	}
	
	buff2 = main_info.buff;
	if (main_info.opts.aa > 1)
		col_apply_aa_blend(main_info.buff, main_info.opts, buff2);
	dither_buff(main_info.opts, buff2, &quant);
	ft_putstr("\nFinished\n");
	
	SDL_DestroySemaphore(sem);
	sdl_render(buff2, main_info.opts);
	return 0;
}
