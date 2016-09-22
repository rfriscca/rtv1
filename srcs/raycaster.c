/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:22:46 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/22 14:39:17 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray	init_ray(t_env *env)
{
	t_ray	ray;

	ray.vecdir.x = VPUL.x + env->x * XINDENT;
	ray.vecdir.y = VPUL.y + env->y * YINDENT;
	ray.vecdir.z = VPUL.z;
}

void	test_sphere(t_env *env, double x, double y, double z)
{
	double	a;
	double	b;
	double	c;

}

void	raycaster(t_env *env)
{
	env->y = 0;
	env->x = 0;
	while (env->x < HEIGHT)
	{
		while (env->y < WIDTH)
		{
			++env->y;
		}
		env->y = 0;
		++env->x;
	}
}
