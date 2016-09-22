/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:22:46 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/22 15:42:54 by rfriscca         ###   ########.fr       */
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

	x = VPUL.x - env->x * XINDENT - CAMPOSX;
	y = VPUL.y + env->y * YINDENT - CAMPOSY;
	z = VPUL.z - CAMPOSZ;
	ray.vecdir.x = x / sqrt(x * x + y * y + z * z);
	ray.vecdir.y = y / sqrt(x * x + y * y + z * z);
	ray.vecdir.z = z / sqrt(x * x + y * y + z * z);
	ray.dist = 0;
	return (ray);
}

void	test_sphere(t_env *env, double x, double y, double z, double r)
{
	double	a;
	double	b;
	double	c;

	a = pow(VDIRX, 2) + pow(VDIRY, 2) + pow(VDIRZ, 2);
	b = 2 * (VDIRX * (CAMPOSX - x) + VDIRY * (CAMPOSY - y) +
			VDIRZ * (CAMPOSZ - z));
	c = pow(CAMPOSX - x, 2) + pow(CAMPOSY - y, 2) + pow(CAMPOSZ - z, 2) - r * r;
	if ((b * b - 4 * a * c) >= 0)
		mlx_pixel_put_img(env, 0xffffff);
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
			test_sphere(env, 0, 0, 0, 10);
			++env->y;
		}
		env->y = 0;
		++env->x;
	}
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "RTv1");
	mlx_key_hook(env->win, event, env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
