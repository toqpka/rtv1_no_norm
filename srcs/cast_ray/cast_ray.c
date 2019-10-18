/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:20:44 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/19 01:15:00 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double    *cast_ray_for_obj(t_sdl *sdl, t_ray ray, int i)
{
  double      *t;

	if (ft_strcmp(sdl->obj[i]->c_type, STR_SPHERE) == 0)
    t = intersec_sphere(ray, get_sph(sdl->obj[i]->type), sdl);
  else if (ft_strcmp(sdl->obj[i]->c_type, STR_CONE) == 0)
    t = intersec_conus(ray, get_con(sdl->obj[i]->type), sdl);
  else if (ft_strcmp(sdl->obj[i]->c_type, STR_PLANE) == 0)
		t = intersec_plane(ray, get_pla(sdl->obj[i]->type), sdl);
  else if (ft_strcmp(sdl->obj[i]->c_type, STR_CYLINDR) == 0)
		t = intersec_cylinder(ray, get_cyl(sdl->obj[i]->type), sdl);
  return (t);
}

double		computer_lighting(t_vec3 p, t_vec3 n, t_sdl *rt, t_vec3 v)
{
	t_light l[2];
	t_vec3 li;
	t_vec3 r;
  double t;

  l[0].pos = vec_new(-20, 0, -4);
	//l[0].pos = vec_new(0, 0, -10);
	l[0].intens = 0.4;
  l[1].pos = vec_new(20, 0, -4);
  //l[1].pos = vec_new(0, 0, 10);
	l[1].intens = 0.4;
	rt->intens = 0.2;
	//return (rt->intens);
  int k = -1;
  while (++k < 2)
{
	t_vec3 dist = vec_op_sub(l[k].pos, p);
	double check = sqrtf(vec_dot(dist, dist));
	dist = unit_vector(dist);

	t_vec3 light_dir = unit_vector(vec_op_sub(l[k].pos, p));
	t_vec3 shadow_orig = ((vec_dot(light_dir,n) < 0) ? vec_op_sub(p,vec_scale(n,0.001)) : vec_op_add(p,vec_scale(n,0.001)));
	t_vec3 hit;

	t_ray ray = new_ray(shadow_orig, dist);
	double		close_t = MAX_DIST;
	double *t_sh;


	double buf_blesk = rt->f_blesk;
	t_vec3 buf_color = rt->f_color;
	t_vec3 buf_centr = rt->f_center;
	int i = -1;
	while (++i < rt->num_obj)
	{
		if (!(t_sh = cast_ray_for_obj(rt, ray, i)))
			ft_print_error_exit(&ft_putendl, "Error, no_memalloc_for_t");
		if (t_sh[0] >= MIN_DIST && t_sh[0] <= MAX_DIST && t_sh[0] < close_t)
			close_t = t_sh[0];
		if (t_sh[1] >= MIN_DIST && t_sh[1] <= MAX_DIST && t_sh[1] < close_t)
		 close_t = t_sh[1];
		rt->f_blesk = buf_blesk;
 		rt->f_color = buf_color;
 		//rt->f_center = buf_centr;
		//p = vec_op_add(ray.origin,vec_scale(ray.direct,close_t));
		if (close_t < MAX_DIST && close_t < check)
 		{
 			rt->intens *= 0.7f;
      break;
 		}
	}
  if (close_t < MAX_DIST && close_t < check)
    continue;

	//li = unit_vector(vec_op_sub(l.pos, p));
		li = vec_op_sub(l[k].pos, p);
		rt->n_dot_l = vec_dot(li, n);
		if (rt->n_dot_l > 0)
			rt->intens += l[k].intens * rt->n_dot_l / vec_length(li);
		if (rt->f_blesk != -1)
		{
			r =vec_op_sub(vec_scale(n, 2.f * vec_dot(n, li)),li);
			rt->r_dot_v = vec_dot(r, v);
			if (rt->r_dot_v > 0)
				rt->intens += l[k].intens * pow(rt->r_dot_v /
				(vec_length(r) * vec_length(v)), rt->f_blesk);
		}
}
	return (rt->intens);
}

t_vec3      calc_color(double close_t, t_ray ray, t_sdl *sdl, int i)
{
  t_vec3  col_out;
  t_vec3  p;
  t_vec3  n;
  double	m;

  p = vec_op_add(ray.origin, vec_scale(ray.direct, close_t));
  if (ft_strcmp(sdl->obj[i]->c_type, STR_SPHERE) == 0)
		n = normal_sphere(p, i, sdl);
  else if (ft_strcmp(sdl->obj[i]->c_type, STR_CONE) == 0)
    n = normal_cone(p, i, sdl);
  else if (ft_strcmp(sdl->obj[i]->c_type, STR_PLANE) == 0)
    n = normal_plane(p, i, sdl);
  else if (ft_strcmp(sdl->obj[i]->c_type, STR_CYLINDR) == 0)
    n = normal_cylinder(p, i, sdl);
  col_out = vec_scale(sdl->f_color, computer_lighting(p, n, sdl, vec_scale(ray.direct, -1)));
  //col_out = sdl->f_color;
  return (col_out);
}

t_vec3    cast_ray(t_ray ray, t_sdl *sdl)
{
  t_vec3		color;
  int				i;
  double		close_t;
  double		*t;
  double    max_f;

  i = -1;
  close_t = MAX_DIST;
	color = vec_new(0, 0, 0);
  while (++i < sdl->num_obj)
  {
		if (!(t = cast_ray_for_obj(sdl, ray, i)))
			ft_print_error_exit(&ft_putendl, "Error, no_memalloc_for_t");
    if (t[0] >= MIN_DIST && t[0] <= MAX_DIST && t[0] < close_t)
    {
     close_t = t[0];
     color = calc_color(close_t, ray, sdl, i);
    }
    if (t[1] >= MIN_DIST && t[1] <= MAX_DIST && t[1] < close_t)
    {
     close_t = t[1];
     color = calc_color(close_t, ray, sdl, i);
    }
		free(t);
  }
  max_f = fmax(color.x,(fmax(color.y,color.z)));
  if (max_f > 255) color = vec_scale(color,255.0/max_f);
	return (color);
}
