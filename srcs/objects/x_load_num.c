/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_load_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:05:06 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/21 22:38:27 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	load_1(int *i, int **nbr, t_sdl	*sdl)
{
	*i = sdl->nbrs.num_obj;
	(*nbr)[0] = sdl->nbrs.num_sph;
	(*nbr)[1] = sdl->nbrs.num_con;
	(*nbr)[2] = sdl->nbrs.num_pla;
	(*nbr)[3] = sdl->nbrs.num_cyl;
	return ;
}
