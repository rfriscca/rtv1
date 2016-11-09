/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 16:13:22 by rfriscca          #+#    #+#             */
/*   Updated: 2016/11/09 14:31:05 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		calc_shadow(t_env *env, t_color cobj, t_color clight)
{
	t_color		color;

	color.r = (cobj.r * clight.r) * 0.15;
	color.g = (cobj.g * clight.g) * 0.15;
	color.b = (cobj.b * clight.b) * 0.15;
	if (color.r < RCOLOR.r)
		color.r = RCOLOR.r;
	if (color.g < RCOLOR.g)
		color.g = RCOLOR.g;
	if (color.b < RCOLOR.b)
		color.b = RCOLOR.b;
	return (color);
}

t_color		calc_color(t_env *env, t_color cobj, t_color clight, double angle)
{
	t_color		color;
	double		x;

	x = dotproduct(VDIR, REFLECT);
	if (angle > 0.15)
	{
		color.r = (cobj.r * clight.r * angle) + clight.r * pow(x, SPEC);
		if (color.r > 255)
			color.r = 255;
		color.g = (cobj.g * clight.g * angle) + clight.g * pow(x, SPEC);
		if (color.g > 255)
			color.g = 255;
		color.b = (cobj.b * clight.b * angle) + clight.b * pow(x, SPEC);
		if (color.b > 255)
			color.b = 255;
	}
	else
		color = calc_shadow(env, cobj, clight);
	if (color.r < RCOLOR.r)
		color.r = RCOLOR.r;
	if (color.g < RCOLOR.g)
		color.g = RCOLOR.g;
	if (color.b < RCOLOR.b)
		color.b = RCOLOR.b;
	return (color);
}
