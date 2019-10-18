/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecray_plane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:01:27 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/19 00:37:57 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		*intersec_plane(t_ray ray, t_plane s, t_sdl *sdl)
{
	double	*t;
	t_vec3	c;
	t_vec3	v;
	t_vec3	x;
	double		k;

	if (!(t = (double *)malloc(sizeof(double) * 2)))
		return (NULL);
	t[0] = 0;
	t[1] = 0;
	sdl->f_blesk = s.blesk;
	sdl->f_color = s.color;
	sdl->f_center = s.norm;
	c = s.line;
	v = s.norm;
	x = vec_op_sub(ray.origin,c);
	t_vec3 b = ray.direct;
	if (vec_dot(b, v) == 0)
		return (t);
	t[0] = - vec_dot(x, v) / vec_dot(b, v);
	t[1] = - vec_dot(x, v) / vec_dot(b, v);
	return (t);
}
