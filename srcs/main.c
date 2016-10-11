/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 13:52:19 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/11 15:33:24 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		create_sphere(t_env *env, t_vector pos, t_color color)
{
	t_obj	*obj;

	if ((obj = (t_obj*)malloc(sizeof(t_obj))) == NULL)
		error(1);
	obj->type = 's';
	obj->vec1 = pos;
	obj->vec2 = pos;
	obj->r = 2;
	obj->d1 = 0;
	obj->d2 = 0;
	obj->color = color;
	if (env->obj == NULL)
	{
		obj->first = obj;
		obj->next = NULL;
		env->obj = obj;
	}
	else
	{
		obj->first = env->obj->first;
		while (env->obj->next != NULL)
			env->obj = env->obj->next;
		env->obj->next = obj;
	}
	env->obj = env->obj->first;
}

void		init_spot(t_env *env, double x, double y, double z, t_color color)
{
	t_vector	pos;

	pos.x = x;
	pos.y = y;
	pos.z = z;
	create_spot(env, pos, color);
}

int			main(int argc, char **argv)
{
	t_env		*env;
	t_color		color;
	t_vector	pos;
	int			fd;

	if ((env = (t_env*)malloc(sizeof(t_env))) == NULL)
		error(1);
	if (argc != 2)
		error(2);
	fd = open(argv[1], O_RDONLY);
	env->file = save_file(fd);
	env->obj = NULL;
	env->spot = NULL;
	pos.x = 0; pos.y = 0; pos.z = 0;
	color.r = 1; color.g = 1; color.b = 1;
	create_sphere(env, pos, color);
	pos.x = 1; pos.y = 4; pos.z = -7;
	color.r = 255; color.g = 0; color.b = 0;
	create_spot(env, pos, color);
	pos.x = 1; pos.y = -4; pos.z = -7;
	color.r = 0; color.g = 0; color.b = 255;
	create_spot(env, pos, color);
	env->cam = init_cam(0, 0, -20);
	env->mlx = mlx_init();
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_data = mlx_get_data_addr(env->img, &env->bits_per_pixel,
			&env->size_line, &env->endian);
	raycaster(env);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "RTv1");
	mlx_key_hook(env->win, event, env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_loop(env->mlx);
	return (0);
}
