/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 12:24:29 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/12 12:29:28 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
