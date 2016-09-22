/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 13:26:09 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/22 16:51:30 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define WIDTH 640
# define HEIGHT 480
# define FOV 30
# define VPWIDTH 6.4
# define VPHEIGHT 4.8
# define VPDIST 3
# define CAMPOSX env->cam.campos.x
# define CAMPOSY env->cam.campos.y
# define CAMPOSZ env->cam.campos.z
# define XINDENT env->cam.xindent
# define YINDENT env->cam.yindent
# define VPUL env->cam.vpul
# define VDIRX env->cam.ray.vecdir.x
# define VDIRY env->cam.ray.vecdir.y
# define VDIRZ env->cam.ray.vecdir.z

# include <math.h>
# include "mlx.h"
# include <stdlib.h>

// delete it later
# include <stdio.h>

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
	t_vector		vec3;
	int				color;
	struct s_obj	*next;
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
	t_camera		cam;
}					t_env;

void				raycaster(t_env *env);
void				mlx_pixel_put_img(t_env *env, int color);
t_vector			rotx(t_vector vec, double angle);
t_vector			roty(t_vector vec, double angle);
t_vector			rotz(t_vector vec, double angle);
t_vector			translation(t_vector vec, double x, double y, double z);

#endif
