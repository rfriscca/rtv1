/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:33:07 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/11 17:04:46 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	get_vector(t_env *env)
{
	t_vector	v;
	int			i;

	i = 0;
	while (LINE[i])
	{
		if (ft_isdigit(LINE[i]) || LINE[i] == '-')
		{
			v.x = ft_atof(LINE + i);
			while (LINE[i] && LINE[i] != ',')
				++i;
			if (!LINE[i])
				error(5);
			++i;
			v.y = ft_atof(LINE + i);
			while (LINE[i] && LINE[i] != ',')
				++i;
			if (!LINE[i])
				error(5);
			++i;
			v.z = ft_atof(LINE + i);
			while (LINE[i] && LINE[i] != ')')
				++i;
		}
		++i;
	}
	return (v);
}

void		parse_file(t_env *env)
{
	t_vector	trans;

	while (env->file)
	{
		if (!ft_strcmp(LINE, "camera"))
		{
			env->cam = init_cam(0, 0, 0);
			while (env->file->next && (LINENEXT[0] == 't' || LINENEXT[0] == 'r'))
			{
				env->file = env->file->next;
				if (env->file && (LINE[0] == 't' || LINE[0] == 'r'))
				{
					trans = get_vector(env);
					if (LINE[0] == 't')
						transcam(env, trans);
					else if (LINE[0] == 'r')
						camangle(env, PI * trans.x / 180, PI * trans.y / 180
								, PI * trans.z / 180);
				}
			}
		}
		if (env->file)
			env->file = env->file->next;
	}
}
