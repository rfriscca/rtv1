/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:53:23 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/12 13:29:12 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	create_plan(t_env *env, t_vector pos, t_color color, t_vector n)
{
	t_obj	*obj;

	if ((obj = (t_obj*)malloc(sizeof(t_obj))) == NULL)
		error(1);
	obj->type = 'p';
	obj->vec1 = pos;
	obj->vec2 = n;
	obj->r = 0;
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

void	test_plan(t_env *env)
{
	double		dist;
	t_vector	x;

	x = calc_vect(POS, CAMPOS);
	dist = -dotproduct(x, N) / dotproduct(VDIR, N);
	if (dist > 0 && dist < RDIST)
	{
		RDIST = dist;
		OBJTOUCHED = env->obj;
	}
}

int		test_plan2(t_env *env, t_vector pos, t_ray ray)
{
	double		dist;
	t_vector	x;

	if (dotproduct(env->cam.vecdirz, env->obj->vec2) > 0)
	{
		env->obj->vec2.x = -env->obj->vec2.x;
		env->obj->vec2.y = -env->obj->vec2.y;
		env->obj->vec2.z = -env->obj->vec2.z;
	}
	x = calc_vect(POS, pos);
	dist = -dotproduct(x, N) / dotproduct(ray.vecdir, N);
	if (dist > 0.01 && dist < ray.dist)
		return (1);
	return (0);
}
