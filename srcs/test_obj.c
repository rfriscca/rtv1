/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 12:24:29 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/27 16:05:33 by rfriscca         ###   ########.fr       */
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
		if (D1 < RDIST && (D1 = (-b + sqrt(det)) / (2 * a)) > 0)
		{
			RDIST = D1;
			OBJTOUCHED = env->obj;
		}
		if (D2 < RDIST && (D2 = (-b - sqrt(det)) / (2 * a)) > 0)
		{
			RDIST = D2;
			OBJTOUCHED = env->obj;
		}
	}
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
