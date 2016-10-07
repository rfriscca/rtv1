/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 14:23:39 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/07 13:24:12 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		create_spot(t_env *env, t_vector pos, t_color color)
{
	t_spot	*spot;

	if ((spot = (t_spot*)malloc(sizeof(t_spot))) == NULL)
		error(1);
	spot->spotpos = pos;
	spot->color = color;
	if (env->spot == NULL)
	{
		spot->first = spot;
		spot->next = NULL;
		env->spot = spot;
	}
	else
	{
		spot->first = env->spot->first;
		spot->next = NULL;
		while (env->spot->next)
			env->spot = env->spot->next;
		env->spot->next = spot;
	}
	env->spot = env->spot->first;
}
