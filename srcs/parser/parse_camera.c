/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 12:00:24 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/12 12:04:03 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_camera(t_env *env)
{
	t_vector	trans;

	env->cam = init_cam(0, 0, 0);
	while (env->file->next && (LINENEXT[0] == 't' || LINENEXT[0] == 'r'))
	{
		env->file = env->file->next;
		if (LINE[0] == 't' || LINE[0] == 'r')
		{
			trans = get_vector(env);
			if (LINE[0] == 't')
				transcam(env, trans);
			if (LINE[0] == 'r')
				camangle(env, PI * trans.x / 180, PI * trans.y / 180
						, PI * trans.z / 180);
		}
	}
}
