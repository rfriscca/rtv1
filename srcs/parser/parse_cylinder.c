/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:38:33 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/12 13:46:58 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_cylinder(t_env *env)
{
	t_vector	trans;
	t_parse		data;

	data.pos = default_pos();
	data.color = default_color();
	data.n = default_n();
	data.r = 1;
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
	create_cylinder(env, data);
}
