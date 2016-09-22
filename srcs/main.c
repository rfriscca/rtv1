/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 13:52:19 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/22 15:43:46 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_camera	init_cam(double x, double y, double z)
{
	t_camera	cam;

	cam.campos.x = x;
	cam.campos.y = y;
	cam.campos.z = z;
	cam.vecdirx.x = 1;
	cam.vecdirx.y = 0;
	cam.vecdirx.z = 0;
	cam.vecdiry.x = 0;
	cam.vecdiry.y = 1;
	cam.vecdiry.z = 0;
	cam.vecdirz.x = 0;
	cam.vecdirz.y = 0;
	cam.vecdirz.z = 1;
	cam.vpul.x = x + VPHEIGHT / 2.0;
	cam.vpul.y = y - VPWIDTH / 2.0;
	cam.vpul.z = z + VPDIST;
	cam.xindent = VPHEIGHT / (double)HEIGHT;
	cam.yindent = VPWIDTH / (double)WIDTH;
	return (cam);
}

int			main(int argc, char **argv)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->mlx = mlx_init();
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_data = mlx_get_data_addr(env->img, &env->bits_per_pixel,
			&env->size_line, &env->endian);
	env->cam = init_cam(0, 0, -15);
	raycaster(env);
	mlx_loop(env->mlx);
	return (0);
}
