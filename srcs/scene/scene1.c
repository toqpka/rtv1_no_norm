/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:05:03 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/19 01:32:15 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**	Spheres_scene_1
*/
t_sphere      *exec_sphere_1(void)
{
  t_sphere  *spheres;
  int       nbrs_sph;

  if (!(nbrs_sph = NUMB_SPHERE_IN_SCENE1))
    return (NULL);
  spheres = create_null_list_spheres(nbrs_sph);
  if (!(spheres))
    ft_print_error_exit(&ft_putendl, "Error, no_spheres");
  spheres[0] = sphere_new(vec_new(0, 0, 2), 1, 250, vec_new(255,0,0));
  return (spheres);
}

/*
**	Cones_scene_1
*/
t_cone      *exec_cone_1(void)
{
  return (NULL);
}

/*
**	Planes_scene_1
*/
t_plane      *exec_plane_1(void)
{
  return (NULL);
}

/*
**	Cylinder_scene_1
*/
t_cylin      *exec_cylinder_1(void)
{
  return (NULL);
}

void    scene1(t_sdl **sdl)
{
  SDL_Surface   *frame;

  frame = create_surface(WIN_WIDTH,WIN_HEIGHT);
  init_obj(&((*sdl)->obj), &((*sdl)->num_obj), SCENE1_IMG);
  //(*sdl)->light = init_light_1;
  (*sdl)->lookfr = vec_new(0, 0, 0);
  (*sdl)->lookat = vec_op_sub(vec_new(0, 0, 1), (*sdl)->rot_ang);
  draw_scene1(frame, sdl);
  (*sdl)->image = frame;
  ft_putstr("Loading: scene1\n");
  return ;
}
