/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 12:17:11 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/13 13:32:33 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	create_sphere(t_env *env, t_vector pos, t_color color, double r)
{
	t_obj	*obj;

	if ((obj = (t_obj*)malloc(sizeof(t_obj))) == NULL)
		error(1);
	obj->type = 's';
	obj->vec1 = pos;
	obj->vec2 = pos;
	obj->r = r;
	obj->d1 = 0;
	obj->d2 = 0;
	obj->color = color;
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
			return (1);
		if ((D2 = (-b - sqrt(det)) / (2 * a)) > 0.01 && D2 < ray.dist)
			return (1);
	}
	return (0);
}
