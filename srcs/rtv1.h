/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 13:26:09 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/07 14:59:24 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define WIDTH 1000
# define HEIGHT 720
# define VPWIDTH 10.0
# define VPHEIGHT 7.2
# define VPDIST 20
# define PI 3.14159265

/*
** FOV = atan(VPWIDTH / 2 / VPDIST)
** With VPWIDTH = 6.4 and VPDIST = 12 FOV = 30
*/

# define CAMPOSX env->cam.campos.x
# define CAMPOSY env->cam.campos.y
# define CAMPOSZ env->cam.campos.z
# define CAMPOS env->cam.campos
# define XINDENT env->cam.xindent
# define YINDENT env->cam.yindent
# define VPUL env->cam.vpul
# define VDIR env->cam.ray.vecdir
# define VDIRX env->cam.ray.vecdir.x
# define VDIRY env->cam.ray.vecdir.y
# define VDIRZ env->cam.ray.vecdir.z
# define RDIST env->cam.ray.dist
# define OBJTOUCHED env->cam.ray.objtouched
# define RCOLOR env->cam.ray.color
# define OBJCOLOR env->obj->color
# define XS env->obj->vec1.x
# define YS env->obj->vec1.y
# define ZS env->obj->vec1.z
# define POS env->obj->vec1
# define NX env->obj->vec2.x
# define NY env->obj->vec2.y
# define NZ env->obj->vec2.z
# define N env->obj->vec2
# define RS env->obj->r
# define D1 env->obj->d1
# define D2 env->obj->d2

/*
**  define vec dir camera
*/

# define VDZX cam.vecdirz.x
# define VDZY cam.vecdirz.y
# define VDZZ cam.vecdirz.z
# define VDYX cam.vecdiry.x
# define VDYY cam.vecdiry.y
# define VDYZ cam.vecdiry.z
# define VDXX cam.vecdirx.x
# define VDXY cam.vecdirx.y
# define VDXZ cam.vecdirx.z


# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>

//test
# include <stdio.h>

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct		s_obj
{
	char			type;
	t_vector		vec1;
	t_vector		vec2;
	double			r;
	double			d1;
	double			d2;
	t_color			color;
	struct s_obj	*next;
	struct s_obj	*first;
}					t_obj;

typedef struct		s_ray
{
	t_vector		vecdir;
	t_obj			*objtouched;
	double			dist;
	t_color			color;
}					t_ray;

typedef struct		s_camera
{
	t_vector		campos;
	t_ray			ray;
	t_vector		vecdirx;
	t_vector		vecdiry;
	t_vector		vecdirz;
	t_vector		vpul;
	double			xindent;
	double			yindent;
}					t_camera;

typedef struct		s_spot
{
	t_vector		spotpos;
	t_color			color;
	t_ray			ray;
	struct s_spot	*first;
	struct s_spot	*next;
}					t_spot;

typedef struct		s_env
{
	void			*mlx;
	void			*img;
	void			*win;
	char			*img_data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	double			x;
	double			y;
	double			rotx;
	t_obj			*obj;
	t_camera		cam;
	t_spot			*spot;
}					t_env;

void				raycaster(t_env *env);
void				mlx_pixel_put_img(t_env *env, t_color color);
t_ray				init_ray(t_env *env);
t_color				calc_color(t_env *env, t_color cobj, t_color clight, double angle);
t_color				calc_shadow(t_env *env, t_color cobj, t_color clight);
t_color				extract_color(int color);
int					event(int n, t_env *env);
void				error(int n);

/*
** VECTOR FUNCTIONS
*/

t_vector			rotx(t_vector vec, double angle);
t_vector			roty(t_vector vec, double angle);
t_vector			rotz(t_vector vec, double angle);
t_vector			translation(t_vector vec, double x, double y, double z);
t_vector			normalize_vec(t_vector vec);
t_vector			calc_vect(t_vector p1, t_vector p2);
t_vector			ray_point(t_env *env);
t_vector			calc_ncylinder(t_env *env);
t_vector			calc_ncone(t_env *env);
double				dotproduct(t_vector vec1, t_vector vec2);


/*
** CAMERA FUNCTIONS
*/

t_camera			init_cam(double x, double y, double z);
void				rotcam(t_env *env, double rx, double ry, double rz);
void				camangle(t_env *env, double rx, double ry, double rz);


/*
** OBJECTS FUNCTIONS
*/

void				create_spot(t_env *env, t_vector pos, t_color color);
void				test_spot(t_env *env);
int					test_sphere2(t_env *env, t_vector pos, t_ray ray);
void				create_plan(t_env *env, t_vector pos, t_color color);
void				test_plan(t_env *env);
int					test_plan2(t_env *env, t_vector pos, t_ray ray);
void				create_cylinder(t_env *env, t_vector pos, t_color color);
void				test_cylinder(t_env *env);
int					test_cylinder2(t_env *env, t_vector pos, t_ray ray);
void				create_cone(t_env *env, t_vector pos, t_color color);
void				test_cone(t_env *env);
int					test_cone2(t_env *env, t_vector pos, t_ray ray);


void				test_obj(t_env *env);

#endif
