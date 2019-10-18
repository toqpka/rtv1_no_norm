/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:30:14 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/19 00:29:37 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		sdl_loop(t_sdl *sdl)
{
	while (sdl->run_main)
	{
		while ( SDL_PollEvent( &(sdl->event) ) != 0 )
		{
			if ((SDL_QUIT == sdl->event.type) ||
					(SDL_KEYDOWN == sdl->event.type &&
						SDL_SCANCODE_ESCAPE == sdl->event.key.keysym.scancode))
				sdl->run_main = 0;
			if (sdl->event.type == SDL_KEYDOWN)
			{
				if (SDLK_LEFT == sdl->event.key.keysym.sym)
				{
					sdl->rot_ang = vec_op_sub(sdl->rot_ang,vec_new(-5,0,0));
					sdl_render(sdl);
				}
				if (SDLK_RIGHT == sdl->event.key.keysym.sym)
				{
					sdl->rot_ang = vec_op_sub(sdl->rot_ang,vec_new(5,0,0));
					sdl_render(sdl);
				}
				if (SDLK_UP == sdl->event.key.keysym.sym)
				{
					sdl->rot_ang = vec_op_sub(sdl->rot_ang,vec_new(0,0.5,0));
					sdl_render(sdl);
				}
				if (SDLK_DOWN == sdl->event.key.keysym.sym)
				{
					sdl->rot_ang = vec_op_sub(sdl->rot_ang,vec_new(0,-0.5,0));
					sdl_render(sdl);
				}
				if (SDLK_a == sdl->event.key.keysym.sym)
				{
					ft_putstr("Pressed_a  rotate z-1\n");
					sdl->rot_ang = vec_op_sub(sdl->rot_ang,vec_new(0,0,-10));
					sdl_render(sdl);
				}
				if (SDLK_z == sdl->event.key.keysym.sym)
				{
					ft_putstr("Pressed_z  rotate z+1\n");
					sdl->rot_ang = vec_op_sub(sdl->rot_ang,vec_new(0,0,10));
					sdl_render(sdl);
				}

			}
		}

	}
	return ;
}
