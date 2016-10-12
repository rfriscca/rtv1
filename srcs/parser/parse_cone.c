/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:47:36 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/12 13:53:07 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_cone(t_env *env)
{
	t_parse		data;
	t_vector	trans;

	data.pos = default_pos();
	data.n = default_n();
	data.color = default_color();
	data.r = 0.5;
	while (env->file->next && (LINENEXT[0] == 'r' || LINENEXT[0] == 't'
				|| LINENEXT[0] == 'o' || LINENEXT[0] == 'c'))
	{
		env->file = env->file->next;
		if (LINE[0] == 't')
		{
			trans = get_vector(env);
			data.pos = translation(data.pos, trans);
		}
		else if (LINE[0] == 'r')
		{
			trans = get_vector(env);
			data.n = rotvec(data.n, trans);
		}
		else if (LINE[0] == 'c')
			data.color = get_color(env);
		else if (LINE[0] == 'o')
			data.r = ft_atof(LINE);
	}
	create_cone(env, data);
}
