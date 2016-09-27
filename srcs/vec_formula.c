/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_formula.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 14:06:46 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/27 14:14:47 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	normalize_vec(t_vector vec)
{
	t_vector	vecnorm;

	vecnorm.x = vec.x / sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	vecnorm.y = vec.y / sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	vecnorm.z = vec.z / sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return (vecnorm);
}
