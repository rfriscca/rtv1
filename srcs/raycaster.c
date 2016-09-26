/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:22:46 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/26 15:15:13 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		event(int n)
{
	if (n == 53)
	{
		exit(1);
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
	ray.color = 0;
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
			mlx_pixel_put_img(env, RCOLOR);
			RCOLOR = 0;
			++env->y;
		}
		env->y = 0;
		++env->x;
	}
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "RTv1");
	mlx_key_hook(env->win, event, env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
