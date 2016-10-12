/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 12:50:46 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/12 13:03:57 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_spot(t_env *env)
{
	t_vector	pos;
	t_vector	trans;
	t_color		color;

	color = default_color();
	pos = default_pos();
	while (env->file->next && (LINENEXT[0] == 't' || LINENEXT[0] == 'c'))
	{
		env->file = env->file->next;
		if (LINE[0] == 't')
		{
			trans = get_vector(env);
			pos = translation(pos, trans);
		}
		else if (LINE[0] == 'c')
			color = get_color_spot(env);
	}
	create_spot(env, pos, color);
}
