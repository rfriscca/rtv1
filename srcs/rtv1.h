/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 13:26:09 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/26 16:27:10 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define WIDTH 640
# define HEIGHT 480
# define VPWIDTH 6.4
# define VPHEIGHT 4.8
# define VPDIST 12

/*
** FOV = atan(VPWIDTH / 2 / VPDIST)
** With VPWIDTH = 6.4 and VPDIST = 12 FOV = 30
*/

# define CAMPOSX env->cam.campos.x
# define CAMPOSY env->cam.campos.y
# define CAMPOSZ env->cam.campos.z
# define XINDENT env->cam.xindent
# define YINDENT env->cam.yindent
# define VPUL env->cam.vpul
# define VDIRX env->cam.ray.vecdir.x
# define VDIRY env->cam.ray.vecdir.y
# define VDIRZ env->cam.ray.vecdir.z
# define RDIST env->cam.ray.dist
# define RCOLOR env->cam.ray.color
# define OBJCOLOR env->obj->color
# define XS env->obj->vec1.x
# define YS env->obj->vec1.y
# define ZS env->obj->vec1.z
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

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_ray
{
	t_vector		vecdir;
	double			dist;
	int				color;
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

typedef struct		s_obj
{
	char			type;
	t_vector		vec1;
	t_vector		vec2;
	double			r;
	double			d1;
	double			d2;
	int				color;
	struct s_obj	*next;
	struct s_obj	*first;
}					t_obj;

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
}					t_env;

void				raycaster(t_env *env);
void				mlx_pixel_put_img(t_env *env, int color);
t_camera			init_cam(double x, double y, double z, double rotax);
t_vector			rotx(t_vector vec, double angle);
t_vector			roty(t_vector vec, double angle);
t_vector			rotz(t_vector vec, double angle);
t_vector			translation(t_vector vec, double x, double y, double z);

int					event(int n, t_env *env);

void				test_obj(t_env *env);

#endif
