/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_spot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 15:15:57 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/04 14:07:13 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		lightcaster(t_env *env, t_vector pos, t_ray ray, t_obj *obj)
{
	env->obj = env->obj->first;
	while (env->obj->next)
	{
		if (test_sphere2(env, pos, ray) == 1)
		{
			env->obj = obj;
			return (1);
		}
		env->obj = env->obj->next;
	}
	if (test_sphere2(env, pos, ray) == 1)
	{
		env->obj = obj;
		return (1);
	}
	env->obj = obj;
	return (0);
}

t_ray	init_lightray(t_env *env, t_vector vec, t_vector point)
{
	t_vector	len;
	t_ray		ray;

	len = calc_vect(point, env->spot->spotpos);
	ray.vecdir = vec;
	ray.dist = sqrt(len.x * len.x + len.y * len.y + len.z * len.z);
	return (ray);
}

void	test_spot2(t_env *env)
{
	t_vector	point;
	t_vector	vec_ltoo;
	t_vector	vec_otol;
	t_vector	vec_ctoo;
	double		angle;

	point = ray_point(env);
	vec_ctoo = normalize_vec(calc_vect(OBJTOUCHED->vec1, point));
	vec_ltoo = normalize_vec(calc_vect(env->spot->spotpos, point));
	vec_otol = normalize_vec(calc_vect(point, env->spot->spotpos));
	angle = dotproduct(vec_otol, vec_ctoo);
	env->spot->ray = init_lightray(env, vec_otol, point);
	if (lightcaster(env, point, env->spot->ray, env->obj) == 0)
		RCOLOR = calc_color(env, OBJTOUCHED->color, env->spot->color, angle);
	else
		RCOLOR = calc_shadow(env, OBJTOUCHED->color, env->spot->color);

}

void	test_spot(t_env *env)
{
	while (env->spot->next)
	{
		test_spot2(env);
		env->spot = env->spot->next;
	}
	test_spot2(env);
	env->spot = env->spot->first;
}
