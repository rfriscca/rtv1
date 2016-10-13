/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:22:46 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/13 13:15:28 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		event(int n, t_env *env)
{
	if (n == 53)
		exit(1);
	else if (n == 124)
	{
		rotcam(env, 0.1, 0, 0);
		camangle(env, 0.1, 0, 0);
		raycaster(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	}
	else if (n == 123)
	{
		rotcam(env, -0.1, 0, 0);
		camangle(env, -0.1, 0, 0);
		raycaster(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	}
	else if (n == 126)
	{
		rotcam(env, 0, 0.1, 0);
		camangle(env, 0, 0.1, 0);
		raycaster(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	}
	else if (n == 125)
	{
		rotcam(env, 0, -0.1, 0);
		camangle(env, 0, -0.1, 0);
		raycaster(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	}
	return (0);
}

t_ray	init_ray(t_env *env)
{
	t_ray	ray;
	double	x;
	double	y;
	double	z;

	x = VPUL.x + env->VDYX * env->y * YINDENT - env->VDXX * env->x * XINDENT - CAMPOSX;
	y = VPUL.y + env->VDYY * env->y * YINDENT - env->VDXY * env->x * XINDENT - CAMPOSY;
	z = VPUL.z + env->VDYZ * env->y * YINDENT - env->VDXZ * env->x * XINDENT - CAMPOSZ;
	ray.vecdir.x = x / sqrt(x * x + y * y + z * z);
	ray.vecdir.y = y / sqrt(x * x + y * y + z * z);
	ray.vecdir.z = z / sqrt(x * x + y * y + z * z);
	ray.dist = 1000000;
	ray.color.r = 0;
	ray.color.g = 0;
	ray.color.b = 0;
	ray.objtouched = NULL;
	return (ray);
}

void	raycaster(t_env *env)
{
	env->y = 0;
	env->x = 0;
	while (env->x < HEIGHT)
	{
		while (env->y < WIDTH)
		{
			env->cam.ray = init_ray(env);
			test_obj(env);
			if (OBJTOUCHED)
				test_spot(env);
			mlx_pixel_put_img(env, RCOLOR);
			++env->y;
		}
		env->y = 0;
		++env->x;
	}
}
