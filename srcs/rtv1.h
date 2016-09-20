/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 13:26:09 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/20 14:51:43 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define WIDTH 640
# define HEIGHT 480
# define VIEWPLANEDIST 1
# define VIEWPLANEWIDTH 0.5
# define VIEWPLANEHEIGHT 0.35

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	origin;
	t_vector	vecdir;
	float		dist;
}				t_ray;

typedef struct	s_camera
{
	t_vector	campos;
	t_ray		ray;
	float		viewplaneupleft;
	float		xindent;
	float		yindent;
}				t_camera;

typedef struct	s_mlxdata
{
	void		*mlx;
	void		*img;
	void		*win;
	char		*img_data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_mlxdata;

typedef struct	s_scene
{
	int			numobjects;
	char		**description;
}				t_scene;

void			raycaster(t_ray ray, t_scene scene);

#endif
