/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput_lighting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 03:08:11 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/21 22:31:41 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			calc_blesk(t_calc_light me, t_sdl *rt)
{
	t_vec3	li;
	t_vec3	r;

	li = unit_vector(vec_op_sub(me.l.pos, me.p));
	rt->n_dot_l = vec_dot(li, me.n);
	if (rt->n_dot_l > 0)
		rt->intens += me.l.intens * rt->n_dot_l / vec_length(li);
	if (rt->f_blesk != -1)
	{
		r = vec_op_sub(vec_scale(me.n, 2.f * vec_dot(me.n, li)), li);
		rt->r_dot_v = vec_dot(r, me.v);
		if (rt->r_dot_v > 0)
			rt->intens += me.l.intens * pow(rt->r_dot_v /
					(vec_length(r) * vec_length(me.v)), rt->f_blesk);
	}
	return ;
}

double			computer_lighting(t_vec3 p, t_vec3 n, t_sdl *rt, t_vec3 v)
{
	t_light			*l;
	t_calc_light	me;
	int				k;

	me.n = n;
	me.p = p;
	me.v = v;
	l = rt->light;
	rt->intens = 0.2;
	k = -1;
	while (++k < rt->nbrs.num_lig)
	{
		me.l = l[k];
		if (calc_shadow(me, rt))
			continue;
		calc_blesk(me, rt);
	}
	return (rt->intens);
}
