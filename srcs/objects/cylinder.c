/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:08:46 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/16 21:46:35 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cylin    *create_null_list_cylinder(int nbr)
{
  t_cylin    *n;
  int   i;

  if (nbr == 0)
    return (NULL);
  if (!(n = (t_cylin*)malloc(nbr * sizeof(t_cylin))))
    return (NULL);
  i = -1;
  while(++i < nbr)
  {
    n[i].radius = 0.0;
    n[i].center = vec_new(0.0,0.0,0.0);
    n[i].blesk = 0.0;
    n[i].color = vec_new(0.0,0.0,0.0);
	  n[i].vector = vec_new(0.0,0.0,0.0);
    //n[i].mater = mater_new();
  }
  return (n);
}

//t_sphere    sphere_new(t_vec3 center, double radius, t_mater mater)
t_cylin    cylin_new(t_vec3 center, t_vec3 vector, double radius, double blesk, t_vec3 color)
{
  t_cylin    new_cylin;

  new_cylin.center = center;
  new_cylin.radius = radius;
  new_cylin.blesk = blesk;
  new_cylin.color = color;
  new_cylin.vector = vector;
  return (new_cylin);
}
