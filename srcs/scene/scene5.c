/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:05:03 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/19 01:04:18 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**	Spheres_scene_5
*/
t_sphere      *exec_sphere_5(void)
{
  t_sphere  *spheres;
  int       nbrs_sph;

  if (!(nbrs_sph = NUMB_SPHERE_IN_SCENE5))
    return (NULL);
  spheres = create_null_list_spheres(nbrs_sph);
  if (!(spheres))
    ft_print_error_exit(&ft_putendl, "Error, no_spheres");
  spheres[0] = sphere_new(vec_new(0, -1, 10), 1, 250, vec_new(255,0,0));
  spheres[1] = sphere_new(vec_new(-4, -4, 18), 1, 10, vec_new(250,250,250));
  spheres[2] = sphere_new(vec_new(-4, -4, 10), 1, 10, vec_new(250,250,250));
  spheres[3] = sphere_new(vec_new(4, -4, 18), 1, 10, vec_new(250,250,250));
  spheres[4] = sphere_new(vec_new(4, -4, 10), 1, 10, vec_new(250,250,250));
  spheres[5] = sphere_new(vec_new(-4, 4, 18), 1, 10, vec_new(250,250,250));
  spheres[6] = sphere_new(vec_new(-4, 4, 10), 1, 10, vec_new(250,250,250));
  spheres[7] = sphere_new(vec_new(4, 4, 18), 1, 10, vec_new(250,250,250));
  spheres[8] = sphere_new(vec_new(4, 4, 10), 1, 10, vec_new(250,250,250));
  return (spheres);
}

/*
**	Cones_scene_5
*/
t_cone      *exec_cone_5(void)
{
  t_cone    *cone;
  int       nbrs_cone;
  t_vec3    v;

  if (!(nbrs_cone = NUMB_CONE_IN_SCENE5))
    return (NULL);
  cone = create_null_list_cone(nbrs_cone);
  if (!(cone))
    ft_print_error_exit(&ft_putendl, "Error, no_cone");
  v = vec_new(0, 2, 0);
  v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
  cone[0] = cone_new(vec_new(0, 0, 2), v, 250, vec_new(255,0,255), 0.6);
  return (cone);
}

/*
**	Planes_scene_5
*/
t_plane      *exec_plane_5(void)
{
  t_plane   *plane;
  int       nbrs_plane;
  t_vec3    v;

  if (!(nbrs_plane = NUMB_PLANE_IN_SCENE5))
    return (NULL);
  plane = create_null_list_plane(nbrs_plane);
  if (!(plane))
    ft_print_error_exit(&ft_putendl, "Error, no_plane");
  plane[0] = plane_new(vec_new(0, 1, 0), vec_new(0, -4, 0), 250, vec_new(200,200,200));  
  plane[1] = plane_new(vec_new(0, -1, 0), vec_new(0, 4, 0), 250, vec_new(200,200,200));
  plane[2] = plane_new(vec_new(0, 0, 1), vec_new(0, 0, 20), 250, vec_new(0,150,250));
  return (plane);
}

/*
**	Cylinder_scene_5
*/
t_cylin      *exec_cylinder_5(void)
{
  t_cylin   *cylin;
  int       nbrs_cylin;
  t_vec3    v;

  if (!(nbrs_cylin = NUMB_CYLINDR_IN_SCENE5))
    return (NULL);
  cylin = create_null_list_cylinder(nbrs_cylin);
  if (!(cylin))
    ft_print_error_exit(&ft_putendl, "Error, no_cylinder");
  v = vec_new(0, 1, 0);
  v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
  cylin[0] = cylin_new(vec_new(4, 0, 10), v, 0.6, 10, vec_new(250,250,250));
  v = vec_new(0, 1, 0);
  v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
  cylin[1] = cylin_new(vec_new(4, 0, 18), v, 0.6, 10, vec_new(250,250,250));
  v = vec_new(0, 1, 0);
  v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
  cylin[2] = cylin_new(vec_new(-4, 0, 10), v, 0.6, 10, vec_new(250,250,250));
  v = vec_new(0, 1, 0);
  v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
  cylin[3] = cylin_new(vec_new(-4, 0, 18), v, 0.6, 10, vec_new(250,250,250));
  return (cylin);
}

void    scene5(t_sdl **sdl)
{
  SDL_Surface   *frame;

  frame = create_surface(WIN_WIDTH,WIN_HEIGHT);
  init_obj(&((*sdl)->obj), &((*sdl)->num_obj), SCENE5_IMG);
  //sdl->light = init_light_1;
  (*sdl)->lookfr = vec_new(10, 3, 15);
  (*sdl)->lookat = vec_op_sub(vec_new(0, 0, 10),(*sdl)->rot_ang);
  draw_scene1(frame, sdl);
  (*sdl)->image = frame;
  ft_putstr("Loading: scene5\n");
  return ;
}
