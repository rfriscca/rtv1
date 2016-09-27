/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 16:13:22 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/27 16:58:49 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		extract_color(int color)
{
	t_color		c;

	c.r = (color & 0x0000ff) / 256;
	c.g = ((color & 0x00ff00) >> 8) / 256;
	c.b = ((color & 0xff0000) >> 16) / 256;
	return (c);
}

int			calc_color(t_color cobj, t_color clight, double angle)
{
	int		color;
	double	r;
	double	g;
	double	b;

	r = (cobj.r * clight.r * angle);
	g = (cobj.g * clight.g * angle);
	b = (cobj.b * clight.b * angle);
	color = (int)r + ((int)g << 8) + ((int)b << 16);
	return (color);
}
