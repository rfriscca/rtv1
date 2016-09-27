/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_spot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 15:15:57 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/27 16:55:46 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	test_spot2(t_env *env)
{
	t_vector	point;
	t_vector	vec_otol;
	t_vector	vec_ctoo;
	double		angle;

	point = ray_point(env);
	vec_otol = normalize_vec(calc_vect(point, env->spot->spotpos));
	vec_ctoo = normalize_vec(calc_vect(OBJTOUCHED->vec1, point));
	angle = dotproduct(vec_otol, vec_ctoo);
	RCOLOR = calc_color(env->obj->color, env->spot->color, angle);
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
