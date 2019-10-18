/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 06:29:53 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/18 23:36:08 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**	Spheres_scene_3
*/
t_sphere      *exec_sphere_3(void)
{
  return (NULL);
}

/*
**	Cones_scene_3
*/
t_cone      *exec_cone_3(void)
{
  t_cone    *cone;
  int       nbrs_cone;
  t_vec3    v;

  if (!(nbrs_cone = NUMB_CONE_IN_SCENE3))
    return (NULL);
  cone = create_null_list_cone(nbrs_cone);
  if (!(cone))
    ft_print_error_exit(&ft_putendl, "Error, no_cone");
  v = vec_new(0, 1, 0);
  v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
  cone[0] = cone_new(vec_new(0, 1, 4), v, 250, vec_new(255,0,255), 0.6);
  return (cone);
}

/*
**	Planes_scene_3
*/
t_plane      *exec_plane_3(void)
{
  t_plane   *plane;
  int       nbrs_plane;
  t_vec3    v;

  if (!(nbrs_plane = NUMB_PLANE_IN_SCENE3))
    return (NULL);
  plane = create_null_list_plane(nbrs_plane);
  if (!(plane))
    ft_print_error_exit(&ft_putendl, "Error, no_plane");
  plane[0] = plane_new(vec_new(0, 1, 0), vec_new(0, -0.8, 0), 250, vec_new(0,200,0));
  return (plane);
}

/*
**	Cylinder_scene_3
*/
t_cylin      *exec_cylinder_3(void)
{
  return (NULL);
}

void    scene3(t_sdl **sdl)
{
  SDL_Surface   *frame;

  frame = create_surface(WIN_WIDTH,WIN_HEIGHT);
  init_obj(&((*sdl)->obj), &((*sdl)->num_obj), SCENE3_IMG);
  //sdl->light = init_light_1;
  (*sdl)->lookfr = vec_new(0, 0, 0);
  (*sdl)->lookat = vec_op_sub(vec_new(0, 0, 1),(*sdl)->rot_ang);
  draw_scene1(frame, sdl);
  (*sdl)->image = frame;
  ft_putstr("Loading: scene3\n");
  return ;
}
