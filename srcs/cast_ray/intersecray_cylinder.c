/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecray_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:50:15 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/19 00:38:06 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		*intersec_cylinder(t_ray ray, t_cylin s, t_sdl *sdl)
{
	double	*t;
	t_vec3	c;
	t_vec3	v;
	t_vec3	x;
	double	r;

	if (!(t = (double *)malloc(sizeof(double) * 2)))
		return (NULL);
	sdl->f_center = s.center;
	sdl->f_blesk = s.blesk;
	sdl->f_color = s.color;
	c = s.center;
	v = s.vector;
	r =	s.radius;
	x = vec_op_sub(ray.origin,c);
	t_vec3 b = ray.direct;
	sdl->x = x;
	sdl->k1 = vec_dot(b, b) - vec_dot(b, v) * vec_dot(b, v);
	sdl->k2 = 2 * (vec_dot(b, x) - vec_dot(b, v) * vec_dot(x, v));
	sdl->k3 = vec_dot(x, x) - vec_dot(x, v) * vec_dot(x, v) - r * r;
	sdl->dis = sdl->k2 * sdl->k2 - 4 * sdl->k1 * sdl->k3;
	if (sdl->dis < 0)
	{
		t[0] = MAX_DIST;
		t[1] = MAX_DIST;
		return (t);
	}
	t[0] = (-sdl->k2 + sqrt(sdl->dis)) / (2 * sdl->k1);
	t[1] = (-sdl->k2 - sqrt(sdl->dis)) / (2 * sdl->k1);
	return (t);
}
