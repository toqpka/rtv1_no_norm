/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_objs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 01:13:18 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/19 08:18:38 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3		normal_cone(t_vec3 p, int i, t_sdl *sdl)
{
	double	side_len;
	t_vec3	normal;
	t_cone	cone;
	double	rad;

	rad = cone.ang * PI / 180.0;
	cone = get_con(sdl->obj[i]->type);
	normal = vec_op_sub(p, cone.center);
	side_len = sqrt(vec_dot(normal, normal));
	side_len /= cos(rad);
	if (vec_dot(normal, cone.vector) < 0)
		side_len = -side_len;
	normal = vec_op_add(cone.center, vec_scale(cone.vector, side_len));
	normal = vec_op_sub(p, normal);
	normal = unit_vector(normal);
	return (normal);
}

t_vec3		normal_cylinder(t_vec3 p, int i, t_sdl *sdl)
{
	t_vec3	normal;
	double	dis;
	t_cylin	cyl;

	cyl = get_cyl(sdl->obj[i]->type);
	normal = vec_op_sub(p, cyl.center);
	dis = vec_dot(normal, cyl.vector);
	normal = vec_op_add(cyl.center, vec_scale(cyl.vector, dis));
	normal = vec_op_sub(p, cyl.center);
	normal = unit_vector(normal);
	return (normal);
}

t_vec3		normal_plane(t_vec3 p, int i, t_sdl *sdl)
{
	t_plane	pl;

	(void)p;
	pl = get_pla(sdl->obj[i]->type);
	return (pl.norm);
}

t_vec3		normal_sphere(t_vec3 p, int i, t_sdl *sdl)
{
	t_vec3		normal;
	t_sphere	sph;

	sph = get_sph(sdl->obj[i]->type);
	normal = vec_op_sub(p, sph.center);
	normal = unit_vector(normal);
	return (normal);
}
