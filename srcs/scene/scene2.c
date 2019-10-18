/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:06:25 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/18 23:36:08 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**	Spheres_scene_2
*/
t_sphere      *exec_sphere_2(void)
{
  return (NULL);
}

/*
**	Cones_scene_2
*/
t_cone      *exec_cone_2(void)
{
  return (NULL);
}

/*
**	Planes_scene_2
*/
t_plane      *exec_plane_2(void)
{
  return (NULL);
}

/*
**	Cylinder_scene_2
*/
t_cylin      *exec_cylinder_2(void)
{
  t_cylin   *cylin;
  int       nbrs_cylin;
  t_vec3    v;

  if (!(nbrs_cylin = NUMB_CYLINDR_IN_SCENE2))
    return (NULL);
  cylin = create_null_list_cylinder(nbrs_cylin);
  if (!(cylin))
    ft_print_error_exit(&ft_putendl, "Error, no_cylinder");
  v = vec_new(0, 1, 0);
  v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
  cylin[0] = cylin_new(vec_new(0, 1, 4), v, 0.6, 250, vec_new(0,250,0));
  return (cylin);
}

void    scene2(t_sdl **sdl)
{
  SDL_Surface		*frame;

  frame = create_surface(WIN_WIDTH,WIN_HEIGHT);
  init_obj(&((*sdl)->obj), &((*sdl)->num_obj), SCENE2_IMG);
  //sdl->light = init_light_1;
  (*sdl)->lookfr = vec_new(0, 0, 0);
  (*sdl)->lookat = vec_op_sub(vec_new(0, 0, 1),(*sdl)->rot_ang);
  draw_scene1(frame, sdl);
  (*sdl)->image = frame;
  ft_putstr("Loading: scene2\n");
  return ;
}
