/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 13:52:19 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/26 15:38:36 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_camera	init_cam(double x, double y, double z, double rotax)
{
	t_camera	cam;

	cam.campos.x = x;
	cam.campos.y = y;
	cam.campos.z = z;
	cam.campos = rotx(cam.campos, rotax);
	cam.vecdirx.x = 1;
	cam.vecdirx.y = 0;
	cam.vecdirx.z = 0;
	cam.vecdiry.x = 0;
	cam.vecdiry.y = 1;
	cam.vecdiry.z = 0;
	cam.vecdirz.x = 0;
	cam.vecdirz.y = 0;
	cam.vecdirz.z = 1;
	cam.vecdirx = rotx(cam.vecdirx, rotax);
	cam.vecdiry = rotx(cam.vecdiry, rotax);
	cam.vecdirz = rotx(cam.vecdirz, rotax);
	cam.vpul.x = cam.campos.x + VDZX * VPDIST + VDXX * VPHEIGHT / 2.0 - VDYX * VPWIDTH / 2.0;
	cam.vpul.y = cam.campos.y + VDZY * VPDIST + VDXY * VPHEIGHT / 2.0 - VDYY * VPWIDTH / 2.0;
	cam.vpul.z = cam.campos.z + VDZZ * VPDIST + VDXZ * VPHEIGHT / 2.0 - VDYZ * VPWIDTH / 2.0;
	cam.xindent = VPHEIGHT / (double)HEIGHT;
	cam.yindent = VPWIDTH / (double)WIDTH;
	return (cam);
}

void		create_obj(t_env *env, double x, double y, double z, int color)
{
	t_obj	*obj;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = 's';
	obj->vec1.x = x;
	obj->vec1.y = y;
	obj->vec1.z = z;
	obj->r = 1;
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

int			main(int argc, char **argv)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->obj = NULL;
	create_obj(env, 0, 0, 0, 0x00ff00);
	create_obj(env, 3, 0, 3, 0xff0000);
	create_obj(env, 0, 0, -3, 0x0000ff);
	env->mlx = mlx_init();
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_data = mlx_get_data_addr(env->img, &env->bits_per_pixel,
			&env->size_line, &env->endian);
	env->cam = init_cam(0, 0, -30, 90);
	raycaster(env);
	mlx_loop(env->mlx);
	return (0);
}
