/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 18:32:56 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/22 07:24:58 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			how_to_use(void)
{
	ft_print_error_exit(&ft_putendl, "Usage: ./RTv1 scene1");
}

int				main(int argc, char **argv)
{
	t_sdl		*sdl;

	if (argc != 2)
		how_to_use();
	read_init(&sdl, argv[1]);
	printf("After parsing =========================\n");
	printf("=======================================\n");
	printf("vec_from=%f,%f,%f vec_looat=%f,%f,%f\n",sdl->lookfr.x,sdl->lookfr.y,sdl->lookfr.z,sdl->lookat.x,sdl->lookat.y,sdl->lookat.z);

	printf("SDL_NBRS cam=%d sphere=%d plane=%d\n",sdl->nbrs.num_cam, sdl->nbrs.num_sph,sdl->nbrs.num_pla);
	printf("SDL_NBRS con=%d cylindr=%d light=%d\n",sdl->nbrs.num_con, sdl->nbrs.num_cyl,sdl->nbrs.num_lig);
	printf("SDL_ALL=%d\n",sdl->nbrs.num_obj);

	printf("\n==========LIGHT========\n");
	printf("#0 x=%f y=%f z=%f",sdl->light[0].pos.x,sdl->light[0].pos.y,sdl->light[0].pos.z);
	sdl_render(sdl);
	sdl_loop(sdl);
	ft_close(&sdl);
	return (0);
}
