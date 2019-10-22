/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_init_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:50:20 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/22 04:05:50 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

#include "rtv1.h"

// int			exec_1(t_all_obj *objs, t_sdl *sdl)
// {
// 	(*objs).new_sphere = exec_sphere_1(sdl);
// 	(*objs).new_cone = exec_cone_1(sdl);
// 	(*objs).new_plane = exec_plane_1(sdl);
// 	(*objs).new_cylinder = exec_cylinder_1(sdl);
// 	return (1);
// }

void			error(t_all_obj *objs)
{
	ft_bzero(objs, sizeof(t_all_obj));
	ft_print_error_exit(&ft_putendl, "Error, exec_scene");
}

t_all_obj		exec_obj(t_sdl *sdl)
{
	t_all_obj	objs;



	// if (!(exec_1(&objs, sdl)))
	// 	error(&objs);
	return (objs);
}

static void		fill_all(t_obj ***all_obj, t_all_obj objs, int *nmbr)
{
	int	i;

	i = 0;
	if (objs.new_sphere)
		fill_objs_sphere(all_obj, objs.new_sphere, &i, nmbr[0]);
	if (objs.new_cone)
		fill_objs_cone(all_obj, objs.new_cone, &i, nmbr[1]);
	if (objs.new_plane)
		fill_objs_plane(all_obj, objs.new_plane, &i, nmbr[2]);
	if (objs.new_cylinder)
		fill_objs_cylin(all_obj, objs.new_cylinder, &i, nmbr[3]);
	return ;
}

void			init_obj(t_obj ***all_obj, int *num, t_sdl *sdl)
{
	t_all_obj	objs;
	int			i;
	int			*nmbr;

	if (!(nmbr = (int*)malloc(sizeof(int) * 4)))
		ft_print_error_exit(&ft_putendl, "Error, no_alloc_nbr_obj");
	objs = exec_obj(sdl);
	*num = sdl->nbrs.num_obj;
	if (!((*all_obj) = (t_obj **)malloc(sizeof(t_obj*) * *num)))
		ft_print_error_exit(&ft_putendl, "Error, no_obj");
	i = -1;
	while (++i < *num)
	{
		if (!((*all_obj)[i] = (t_obj *)malloc(sizeof(t_obj))))
			ft_print_error_exit(&ft_putendl, "Error, no_obj_elem");
	}
	fill_all(all_obj, objs, nmbr);
	free(nmbr);
	return ;
}
