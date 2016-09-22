/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:05:46 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/22 13:09:39 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	translation(t_vector vec, double x, double y, double z)
{
	t_vector	vectrans;

	vectrans.x = vec.x + x;
	vectrans.y = vec.y + y;
	vectrans.z = vec.z + z;
	return (vectrans);
}
