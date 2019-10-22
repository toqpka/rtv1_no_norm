/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 03:26:26 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/22 04:13:28 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*exec_sphere_1(t_sdl *sdl)
{
	t_sphere	*spheres;
	int			nbrs_sph;
	int			k;


	// t_sphere sp;
	// sp.center;
	// sp.radius;
	// sp.blesk;
	// sp.color;

	if (!(nbrs_sph = sdl->nbrs.num_sph))
		return (NULL);
	spheres = create_null_list_spheres(nbrs_sph);
	if (!(spheres))
		ft_print_error_exit(&ft_putendl, "Error, no_spheres");
	// k = -1;
	// while (++k < sdl->nbrs.num_sph)
	// {
	// 	spheres[k] = sphere_new(sp.center, sp.radius, sp.blesk, sp.color);
	// }
	return (spheres);
}

t_cone		*exec_cone_1(t_sdl *sdl)
{
	t_cone	*cone;
	int		nbrs_cone;
	t_vec3	v;

	if (!(nbrs_cone = sdl->nbrs.num_con))
		return (NULL);
	cone = create_null_list_cone(nbrs_cone);
	if (!(cone))
		ft_print_error_exit(&ft_putendl, "Error, no_cone");
	// v = vec_new(0, 2, 0);
	// v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
	// cone[0] = cone_new(vec_new(0, 0, 2), v, vec_new(255, 0, 255), 0.6);
	return (cone);
}

t_plane		*exec_plane_1(t_sdl *sdl)
{
	t_plane	*plane;
	int		nbrs_plane;

	if (!(nbrs_plane = sdl->nbrs.num_pla))
		return (NULL);
	plane = create_null_list_plane(nbrs_plane);
	if (!(plane))
		ft_print_error_exit(&ft_putendl, "Error, no_plane");
	// plane[0] = plane_new(vec_new(0, 1, 0), vec_new(0, -3, -10), 250, vec_new(200, 200, 200));
	return (plane);
}

t_cylin		*exec_cylinder_1(t_sdl *sdl)
{
	t_cylin		*cylin;
	int			nbrs_cylin;
	t_vec3		v;

	if (!(nbrs_cylin = sdl->nbrs.num_cyl))
		return (NULL);
	cylin = create_null_list_cylinder(nbrs_cylin);
	if (!(cylin))
		ft_print_error_exit(&ft_putendl, "Error, no_cylinder");
	// v = vec_new(0, 1, 0);
	// v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
	// cylin[0] = cylin_new(vec_new(4, 1, 0), v, 0.6, vec_new(250, 250, 250));
	return (cylin);
}

void    get_list_objs(t_sdl *sdl, char *path)
{
  //init_obj(&(sdl->obj), &(sdl->num_obj), *sdl);
	int		fd;
	char	*line;
	t_sphere	*new_sphere;
	t_cone		*new_cone;
	t_plane		*new_plane;
	t_cylin		*new_cylinder;
	t_light		*new_light;
	int	nbr_light;
	char **split;

	t_nbr_all all_n;

	new_sphere = exec_sphere_1(sdl);
	new_cone = exec_cone_1(sdl);
	new_plane = exec_plane_1(sdl);
	new_cylinder = exec_cylinder_1(sdl);
	//new_light = exec_light(sdl);;


	nbr_light = sdl->nbrs.num_lig;
	if (!(new_light = create_null_list_lights(nbr_light)) && nbr_light)
		ft_print_error_exit(&ft_putendl, "Error, no_alloc_for_light");



	all_n = sdl->nbrs;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
    printf("gnl tmp_string_full=%s\n",line);
    split = ft_strsplit(line, ' ');
		sdl->block_1 = split[0];
    if (ft_strcmp(STR_CAMERA, sdl->block_1) == 0)
      fill_camera(split, &sdl->lookfr, &sdl->lookat);
    else if (ft_strcmp(STR_LIGHT, sdl->block_1) == 0)
      fill_light(split, new_light, &(all_n.num_lig));
    else if (ft_strcmp(STR_SPHERE, sdl->block_1) == 0)
      fill_sphere(split, new_sphere, &(all_n.num_sph));
    else if (ft_strcmp(STR_PLANE, sdl->block_1) == 0)
      fill_plane(split, new_plane, &(all_n.num_pla));
    else if (ft_strcmp(STR_CONE, sdl->block_1) == 0)
      fill_cone(split, new_cone, &(all_n.num_con));
    else if (ft_strcmp(STR_CYLINDR, sdl->block_1) == 0)
      fill_cylin(split, new_cylinder, &(all_n.num_cyl));
    else
    {
      printf("error oops second\n");
      close(fd);
      free(line);
			exit(1);
      return ;
    }
		free(line);
	}
  close(fd);
}
