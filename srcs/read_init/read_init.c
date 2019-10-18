/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 00:45:29 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/18 22:13:44 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** init_sdl Return 0 if bad init
** init_sdl Return 1 if good init
*/

static uint8_t init_sdl(t_sdl **sdl)
{
  	if (SDL_Init( SDL_INIT_VIDEO ) < 0)
      return (put_error_sdl(SDL_ERROR,SDL_GetError()));
  	else
  	{
      if (!((*sdl)->win = SDL_CreateWindow( WIN_TITLE, SDL_WINDOWPOS_UNDEFINED,
          SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN )))
          return (put_error_sdl(WIN_ERROR,SDL_GetError()));
  		else
        if (!((*sdl)->screen = SDL_GetWindowSurface((*sdl)->win)))
          return (put_error_sdl(SUR_ERROR,SDL_GetError()));
  	}
  	return (1);
}

void      ft_init(t_sdl **sdl, uint8_t sc)
{
  if (!((*sdl) = ft_memalloc(sizeof(t_sdl))))
		ft_print_error_exit(&ft_putendl, "Error");
  (*sdl)->win = NULL;
  (*sdl)->screen = NULL;
  (*sdl)->image = NULL;
  (*sdl)->run_main = 1;
  (*sdl)->scene_num = sc;
  (*sdl)->num_obj = 0;
  (*sdl)->mater = NULL;
  (*sdl)->obj = NULL;
  (*sdl)->camera = vec_new(0,0,-10);
  (*sdl)->rot_ang = vec_new(0,0,0);
  if (!(init_sdl(sdl)))
    ft_print_error_exit(&ft_putendl, "Error_sdl");
  return ;
}

void      ft_close(t_sdl **sdl)
{
  SDL_DestroyWindow( (*sdl)->win );
	(*sdl)->win = NULL;
	IMG_Quit();
	SDL_Quit();
  return ;
}

void      read_init(t_sdl **sdl, char *av)
{
  uint8_t   scene;

  scene = 0;
	if (ft_strcmp(SCENE1, av) == 0)
		scene = 1;
	else if (ft_strcmp(SCENE2, av) == 0)
		scene = 2;
	else if (ft_strcmp(SCENE3, av) == 0)
		scene = 3;
	else if (ft_strcmp(SCENE4, av) == 0)
		scene = 4;
	else if (ft_strcmp(SCENE5, av) == 0)
		scene = 5;
	else
		how_to_use();
  ft_init(sdl, scene);
	return ;
}
