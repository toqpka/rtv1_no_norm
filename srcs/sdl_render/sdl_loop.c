/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:30:14 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/24 23:38:14 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		sdl_loop(t_sdl *sdl)
{
	while (sdl->run_main)
	{
		while (SDL_PollEvent(&(sdl->event)) != 0)
		{
			if ((SDL_QUIT == sdl->event.type) ||
					(SDL_KEYDOWN == sdl->event.type &&
						SDL_SCANCODE_ESCAPE == sdl->event.key.keysym.scancode))
				sdl->run_main = 0;
			if (SDL_KEYDOWN == sdl->event.type && SDLK_w == sdl->event.key.keysym.sym)
			{
				get_list_objs(sdl, sdl->av);
				sdl_render(sdl);
			}
		}
	}
	return ;
}
