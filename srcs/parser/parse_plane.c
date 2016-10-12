/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:10:18 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/12 13:28:08 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_plane(t_env *env)
{
	t_vector	pos;
	t_vector	trans;
	t_color		color;
	t_vector	n;

	pos = default_pos();
	color = default_color();
	n = default_n();
	while (env->file->next && (LINENEXT[0] == 't' || LINENEXT[0] == 'c'
				|| LINENEXT[0] == 'r'))
	{
		env->file = env->file->next;
		if (LINE[0] == 't')
		{
			trans = get_vector(env);
			pos = translation(pos, trans);
		}
		else if (LINE[0] == 'r')
		{
			trans = get_vector(env);
			n = rotvec(n, trans);
		}
		else if (LINE[0] == 'c')
			color = get_color(env);
	}
	create_plan(env, pos, color, n);
}
