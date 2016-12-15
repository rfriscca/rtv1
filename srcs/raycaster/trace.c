/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:36:02 by rfriscca          #+#    #+#             */
/*   Updated: 2016/12/15 15:05:16 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	calc_point(t_ray *ray)
{
	t_vector	point;

	point.x = VDIR.x * RDIST + ray->pos.x;
	point.y = VDIR.y * RDIST + ray->pos.y;
	point.z = VDIR.z * RDIST + ray->pos.z;
	return (point);
}

t_color		trace(t_env *env, t_ray *ray, int i)
{
	t_color		color;
	t_obj		*obj;
	t_vector	point;

	obj = NULL;
	color = init_color_black();
	if (i > MAX_DEPTH)
		return (color);
	if ((obj = test_obj(env, ray)) == NULL)
		return (color);
	point = calc_point(ray);
	if (obj->reflect == 1)
	{
		VDIR = reflect_vect(VDIR, obj->vec2);
		ray->pos = point;
		color = trace(env, ray, i + 1);
		return (color);
	}
	color = test_spot(env, ray, obj, point);
	return (color);
}
