/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 12:24:29 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/04 13:39:05 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	test_sphere(t_env *env)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a = pow(VDIRX, 2) + pow(VDIRY, 2) + pow(VDIRZ, 2);
	b = 2 * (VDIRX * (CAMPOSX - XS) + VDIRY * (CAMPOSY - YS) +
			VDIRZ * (CAMPOSZ - ZS));
	c = pow(CAMPOSX - XS, 2) + pow(CAMPOSY - YS, 2) + pow(CAMPOSZ - ZS, 2)
		- RS * RS;
	det = b * b - 4 * a * c;
	if (det >= 0)
	{
		if ((D1 = (-b + sqrt(det)) / (2 * a)) > 0 && D1 < RDIST)
		{
			RDIST = D1;
			OBJTOUCHED = env->obj;
		}
		if ((D2 = (-b - sqrt(det)) / (2 * a)) > 0 && D2 < RDIST)
		{
			RDIST = D2;
			OBJTOUCHED = env->obj;
		}
	}
}

int		test_sphere2(t_env *env, t_vector pos, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a = pow(ray.vecdir.x, 2) + pow(ray.vecdir.y, 2) + pow(ray.vecdir.z, 2);
	b = 2 * (ray.vecdir.x * (pos.x - XS) + ray.vecdir.y * (pos.y - YS) +
			ray.vecdir.z * (pos.z - ZS));
	c = pow(pos.x - XS, 2) + pow(pos.y - YS, 2) + pow(pos.z - ZS, 2)
		- RS * RS;
	det = b * b - 4 * a * c;
	if (det >= 0)
	{
		if ((D1 = (-b + sqrt(det)) / (2 * a)) > 0.1 && D1 < ray.dist)
		{
			return (1);
		}
		if ((D2 = (-b - sqrt(det)) / (2 * a)) > 0.1 && D2 < ray.dist)
		{
			return (1);
		}
	}
	return (0);
}

void	test_obj(t_env *env)
{
	while (env->obj->next)
	{
		if (env->obj->type == 's')
			test_sphere(env);
		env->obj = env->obj->next;
	}
	test_sphere(env);
	env->obj = env->obj->first;
}
