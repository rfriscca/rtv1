/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 16:13:22 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/03 15:53:21 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		calc_shadow(t_color cobj, t_color clight)
{
	t_color		color;

	color.r = (cobj.r * clight.r) * 0.2;
	color.g = (cobj.g * clight.g) * 0.2;
	color.b = (cobj.b * clight.b) * 0.2;
	return (color);
}

t_color		calc_color(t_color cobj, t_color clight, double angle)
{
	t_color		color;

	if (angle > 0.2)
	{
		color.r = (cobj.r * clight.r * angle);
		color.g = (cobj.g * clight.g * angle);
		color.b = (cobj.b * clight.b * angle);
	}
	else
		color = calc_shadow(cobj, clight);
	return (color);
}
