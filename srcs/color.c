/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 16:13:22 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/28 15:41:11 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		calc_color(t_color cobj, t_color clight, double angle)
{
	t_color		color;

	color.r = (cobj.r * clight.r * angle);
	color.g = (cobj.g * clight.g * angle);
	color.b = (cobj.b * clight.b * angle);
	return (color);
}
