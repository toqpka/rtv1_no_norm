/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:11:21 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/19 01:32:01 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		mask_byteorder(Uint32 *rmask, Uint32 *gmask, Uint32 *bmask, Uint32 *amask)
{
	if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
	{
		*rmask = 0xFF000000;
		*gmask = 0x00FF0000;
		*bmask = 0x0000FF00;
		*amask = 0x000000FF;
	}
	else
	{
		*rmask = 0x000000FF;
		*gmask = 0x0000FF00;
		*bmask = 0x00FF0000;
		*amask = 0xFF000000;
	}
	return ;
}

SDL_Surface		*create_surface(int width, int height)
{
	SDL_Surface		*surf;
	Uint32			rmask;
	Uint32			gmask;
	Uint32			bmask;
	Uint32			amask;

	mask_byteorder(&rmask, &gmask, &bmask, &amask);
	surf = SDL_CreateRGBSurface(0, width, height, 32, rmask, gmask, bmask, amask);
	if (surf == NULL)
	{
		ft_putstr("SDL_CreateRGBSurface() failed: ");
		ft_putstr(SDL_GetError());
		ft_putstr("\n");
		exit(1);
	}
	return (surf);
}

void			draw_filled_square(SDL_Surface *surf, const SDL_Rect *rect, const int color, void *param)
{
	register int		x;
	register int		y;

	(void)param;
	y = -1;
	while (++y < rect->h)
	{
		x = -1;
		while (++x < rect->w)
			put_pixel(surf, x + rect->x, y + rect->y, color);
	}
	return ;
}

void			clear_surface(SDL_Surface *surf, const SDL_Rect *rect, const int color, void *param)
{
	register int		x;
	register int		y;

	(void)rect;
	(void)param;
	y = -1;
	while (++y < surf->h)
	{
		x = -1;
		while (++x < surf->w)
			put_pixel(surf, x, y, color);
	}
	return ;
}
