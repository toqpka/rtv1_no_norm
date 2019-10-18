/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_prototypes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:20:57 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/19 01:29:42 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_PROTOTYPES_H
# define RTV1_PROTOTYPES_H

/*
** Main functions
*/
void          ft_close(t_sdl **sdl);
void          ft_init(t_sdl **sdl, uint8_t sc);
void		      sdl_loop(t_sdl *sdl);
void          how_to_use(void);

/*
** Read functions
*/
void          read_init(t_sdl **sdl, char *argv);
int           put_error_sdl(char *str, const char *err);

/*
** Render functions
*/
void          sdl_render(t_sdl *sdl);
t_vec3        cast_ray(t_ray ray, t_sdl *sdl);
t_ray         new_ray(t_vec3 orig, t_vec3 dir);

/*
** SDL functions
*/
SDL_Surface		*create_surface(int width, int height);

/*
** Object functions
*/
t_sphere      *create_null_list_spheres(int nbr);
t_cone        *create_null_list_cone(int nbr);
t_plane       *create_null_list_plane(int nbr);
t_cylin       *create_null_list_cylinder(int nbr);
//t_sphere    sphere_new(t_vec3 center, double radius, t_mater mater); // using blesk <<<<<<<<<< !!!!
t_sphere      sphere_new(t_vec3 center, double radius, double blesk, t_vec3 color);
t_cone        cone_new(t_vec3 center, t_vec3 vector, double blesk, t_vec3 color, double ang);
t_plane       plane_new(t_vec3 norm, t_vec3 line, double blesk, t_vec3 color);
t_cylin       cylin_new(t_vec3 center, t_vec3 vector, double radius, double blesk, t_vec3 color);
void          fill_objs_sphere(t_obj   ***all_obj, t_sphere *sphere, int *i, int max);
void          fill_objs_cone(t_obj ***all_obj, t_cone *cone, int *i, int max);
void          fill_objs_plane(t_obj ***all_obj, t_plane *plane, int *i, int max);
void          fill_objs_cylin(t_obj ***all_obj, t_cylin *cylindr, int *i, int max);      // need ADD t_cylindr
void          init_obj(t_obj    ***all_obj, int *num, int scene_num);

/*
** Camera functions
*/
t_ray         get_camera_ray(t_sdl  *sdl, SDL_Surface *surf, int x, int y);

/*
** Color pack functions
*/
uint32_t      pack_color(const uint8_t r, const uint8_t g, const uint8_t b);
void          unpack_color( uint32_t color, uint8_t *r, uint8_t *g, uint8_t *b);

/*
** Set_pixel on surface SDL
*/
void          put_pixel(SDL_Surface *surf, const int x, const int y, const int color);

/*
** Some scene function
*/
void          scene1(t_sdl **sdl);
void          scene2(t_sdl **sdl);
void          scene3(t_sdl **sdl);
void          scene4(t_sdl **sdl);
void          scene5(t_sdl **sdl);
void          exec_1(t_all_obj  *objs);
void          exec_2(t_all_obj  *objs);
void          exec_3(t_all_obj  *objs);
void          exec_4(t_all_obj  *objs);
void          exec_5(t_all_obj  *objs);
void          load_1(int *i, int **nbr);
void          load_2(int *i, int **nbr);
void          load_3(int *i, int **nbr);
void          load_4(int *i, int **nbr);
void          load_5(int *i, int **nbr);

/*
** scene1
*/
t_sphere      *exec_sphere_1(void);
t_cone        *exec_cone_1(void);
t_cylin       *exec_cylinder_1(void);
t_plane       *exec_plane_1(void);

/*
** scene2
*/
t_sphere      *exec_sphere_2(void);
t_cone        *exec_cone_2(void);
t_cylin       *exec_cylinder_2(void);
t_plane       *exec_plane_2(void);

/*
** scene3
*/
t_sphere      *exec_sphere_3(void);
t_cone        *exec_cone_3(void);
t_cylin       *exec_cylinder_3(void);
t_plane       *exec_plane_3(void);

/*
** scene4
*/
t_sphere      *exec_sphere_4(void);
t_cone        *exec_cone_4(void);
t_cylin       *exec_cylinder_4(void);
t_plane       *exec_plane_4(void);

/*
** scene5
*/
t_sphere      *exec_sphere_5(void);
t_cone        *exec_cone_5(void);
t_cylin       *exec_cylinder_5(void);
t_plane       *exec_plane_5(void);

/*
** Drawer functions for scenes
*/
void          draw_scene1(SDL_Surface *surf, t_sdl  **sdl);

/*
** Cast ray for objects
*/
double			*intersec_sphere(t_ray ray, t_sphere s, t_sdl *sdl);
double			*intersec_conus(t_ray ray, t_cone s, t_sdl *sdl);
double      *intersec_plane(t_ray ray, t_plane s, t_sdl *sdl);
double      *intersec_cylinder(t_ray ray, t_cylin s, t_sdl *sdl);

/*
** Find normal for objects
*/
t_vec3      normal_cone(t_vec3 p, int i, t_sdl *sdl);
t_vec3      normal_cylinder(t_vec3 p, int i, t_sdl *sdl);
t_vec3      normal_plane(t_vec3 p, int i, t_sdl *sdl);
t_vec3      normal_sphere(t_vec3 p, int i, t_sdl *sdl);

/*
** Memory func for search type obj
*/
t_sphere			get_sph(void *sdl_sph);
t_cone				get_con(void *sdl_o);
t_plane				get_pla(void *sdl_p);
t_cylin				get_cyl(void *sdl_c);

#endif
