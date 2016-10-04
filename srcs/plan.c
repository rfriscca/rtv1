/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:53:23 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/04 16:13:43 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	create_plan(t_env *env, t_vector pos, t_color color)
{
	t_obj	*obj;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = 'p';
	obj->vec1 = pos;
	obj->vec2.x = 1;
	obj->vec2.y = 0;
	obj->vec2.z = 0;
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

void	test_plan(t_env *env)
{
	double	dist;

	dist = -((NX * (CAMPOSX - XS) + NY * (CAMPOSY - YS) + NZ * (CAMPOSZ - ZS)) /
		   (NX * VDIRX + NY * VDIRY + NZ * VDIRZ));
	if (dist > 0 && dist < RDIST)
	{
		RDIST = dist;
		OBJTOUCHED = env->obj;
	}
}

int		test_plan2(t_env *env, t_vector pos, t_ray ray)
{
	double	dist;

	dist = -((NX * (pos.x - XS) + NY * (pos.y - YS) + NZ * (pos.z - ZS)) /
			(NX * ray.vecdir.x + NY * ray.vecdir.y + NZ * ray.vecdir.z));
	if (dist > 0.1 && dist < ray.dist)
		return (1);
	return (0);
}
