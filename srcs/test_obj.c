/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 12:24:29 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/07 14:16:43 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	test_sphere(t_env *env)
{
	double		a;
	double		b;
	double		c;
	t_vector	x;
	double		det;

	x = calc_vect(POS, CAMPOS);
	a = dotproduct(VDIR, VDIR);
	b = 2 * (dotproduct(VDIR, x));
	c = dotproduct(x, x) - RS * RS;
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
	double		a;
	double		b;
	double		c;
	t_vector	x;
	double		det;

	x = calc_vect(POS, pos);
	a = dotproduct(ray.vecdir, ray.vecdir);
	b = 2 * (dotproduct(ray.vecdir, x));
	c = dotproduct(x, x) - RS * RS;
	det = b * b - 4 * a * c;
	if (det >= 0)
	{
		if ((D1 = (-b + sqrt(det)) / (2 * a)) > 0.01 && D1 < ray.dist)
		{
			return (1);
		}
		if ((D2 = (-b - sqrt(det)) / (2 * a)) > 0.01 && D2 < ray.dist)
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
		else if (env->obj->type == 'p')
			test_plan(env);
		else if (env->obj->type == 'c')
			test_cylinder(env);
		else if (env->obj->type == 'k')
			test_cone(env);
		env->obj = env->obj->next;
	}
	if (env->obj->type == 's')
		test_sphere(env);
	else if (env->obj->type == 'p')
		test_plan(env);
	else if (env->obj->type == 'c')
		test_cylinder(env);
	else if (env->obj->type == 'k')
		test_cone(env);
	env->obj = env->obj->first;
}
