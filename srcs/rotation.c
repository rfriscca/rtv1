/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 12:54:01 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/26 13:43:00 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	rotx(t_vector vec, double angle)
{
	t_vector	vecrot;

	vecrot.x = vec.x;
	vecrot.y = vec.y * cos(angle) - vec.z * sin(angle);
	vecrot.z = vec.y * sin(angle) + vec.z * cos (angle);
	return (vecrot);
}

t_vector	roty(t_vector vec, double angle)
{
	t_vector	vecrot;

	vecrot.x = vec.x * cos(angle) + vec.z * sin(angle);
	vecrot.y = vec.y;
	vecrot.z = vec.z * cos(angle) - vec.x * sin(angle);
	return (vecrot);
}

t_vector	rotz(t_vector vec, double angle)
{
	t_vector	vecrot;

	vecrot.x = vec.x * cos(angle) - vec.y * sin(angle);
	vecrot.y = vec.x * sin(angle) + vec.y * cos(angle);
	vecrot.z = vec.z;
	return (vecrot);
}
