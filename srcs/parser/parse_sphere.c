/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 12:45:49 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/13 15:18:58 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_sphere(t_env *env)
{
	t_vector	pos;
	t_vector	trans;
	t_color		color;
	t_line		*file;
	double		r;

	color = default_color();
	pos = default_pos();
	r = 1;
	while (env->file->next && (LINENEXT[0] == 't' || LINENEXT[0] == 'c'
				|| LINENEXT[0] == 'o') && !ft_isalpha(LINENEXT[1]))
	{
		file = env->file->next;
		free_file(env);
		env->file = file;
		if (LINE[0] == 't')
		{
			trans = get_vector(env);
			pos = translation(pos, trans);
		}
		else if (LINE[0] == 'c')
			color = get_color(env);
		else if (LINE[0] == 'o')
			r = ft_atof(LINE);
	}
	create_sphere(env, pos, color, r);
}
