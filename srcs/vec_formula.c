/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_formula.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 14:06:46 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/06 16:54:08 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		dotproduct(t_vector vec1, t_vector vec2)
{
	double	res;

	res = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	return (res);
}

t_vector	ray_point(t_env *env)
{
	t_vector	point;

	point.x = VDIRX * RDIST + CAMPOSX;
	point.y = VDIRY * RDIST + CAMPOSY;
	point.z = VDIRZ * RDIST + CAMPOSZ;
	return (point);
}

t_vector	calc_vect(t_vector p1, t_vector p2)
{
	t_vector	new;

	new.x = p2.x - p1.x;
	new.y = p2.y - p1.y;
	new.z = p2.z - p1.z;
	return (new);
}

t_vector	calc_ncylinder(t_env *env)
{
	t_vector	n;
	double		m;
	t_vector	x;

	x = calc_vect(POS, CAMPOS);
	m = dotproduct(VDIR, N) * RDIST + dotproduct(x, N);
	n.x = (VDIRX * RDIST + CAMPOSX) - XS - N.x * m;
	n.y = (VDIRY * RDIST + CAMPOSY) - YS - N.y * m;
	n.z = (VDIRZ * RDIST + CAMPOSZ) - ZS - N.z * m;
	return (n);
}

t_vector	normalize_vec(t_vector vec)
{
	t_vector	vecnorm;

	vecnorm.x = vec.x / sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	vecnorm.y = vec.y / sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	vecnorm.z = vec.z / sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return (vecnorm);
}
