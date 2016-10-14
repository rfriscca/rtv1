/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 13:59:20 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/13 15:48:00 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	create_cone(t_env *env, t_parse data)
{
	t_obj	*obj;

	if ((obj = (t_obj*)malloc(sizeof(t_obj))) == NULL)
		error(1);
	obj->type = 'k';
	obj->vec1 = data.pos;
	obj->vec2 = data.n;
	obj->r = data.r;
	obj->d1 = 0;
	obj->d2 = 0;
	obj->color = data.color;
	obj->next = NULL;
	if (env->obj == NULL)
	{
		obj->first = obj;
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

void	test_cone(t_env *env)
{
	double		a;
	double		b;
	double		c;
	t_vector	x;
	double		det;

	x = calc_vect(POS, CAMPOS);
	a = dotproduct(VDIR, VDIR) - (1 + RS * RS) * pow(dotproduct(VDIR, N), 2);
	b = 2 * (dotproduct(VDIR, x) - (1 + RS * RS) * dotproduct(VDIR, N) *
			dotproduct(x, N));
	c = dotproduct(x, x) - (1 + RS * RS) * pow(dotproduct(x, N), 2);
	det = b * b - 4 * a * c;
	if (det > 0)
	{
		if ((D1 = (-b - sqrt(det)) / (2 * a)) > 0 && D1 < RDIST)
		{
			RDIST = D1;
			OBJTOUCHED = env->obj;
		}
		if ((D2 = (-b + sqrt(det)) / (2 * a)) > 0 && D1 < RDIST)
		{
			RDIST = D2;
			OBJTOUCHED = env->obj;
		}
	}
}

int		test_cone2(t_env *env, t_vector pos, t_ray ray)
{
	double		a;
	double		b;
	double		c;
	t_vector	x;
	double		det;

	x = calc_vect(POS, pos);
	a = dotproduct(ray.vecdir, ray.vecdir) - (1 + RS * RS) *
		pow(dotproduct(ray.vecdir, N), 2);
	b = 2 * (dotproduct(ray.vecdir, x) - (1 + RS * RS) *
			dotproduct(ray.vecdir, N) * dotproduct(x, N));
	c = dotproduct(x, x) - (1 + RS * RS) * pow(dotproduct(x, N), 2);
	det = b * b - 4 * a * c;
	if (det >= 0)
	{
		if ((D1 = (-b - sqrt(det)) / (2 * a)) > 0.01 && D1 < ray.dist)
			return (1);
		if ((D2 = (-b + sqrt(det)) / (2 * a)) > 0.01 && D1 < ray.dist)
			return (1);
	}
	return (0);
}
