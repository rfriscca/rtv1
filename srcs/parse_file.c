/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:33:07 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/11 17:51:15 by rfriscca         ###   ########.fr       */
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

t_color		get_color(t_env *env)
{
	t_color		c;
	int			i;

	i = 0;
	while (LINE[i])
	{
		if (ft_isdigit(LINE[i]) || LINE[i] == '-')
		{
			c.r = ft_atof(LINE + i);
			while (LINE[i] && LINE[i] != ',')
				++i;
			if (!LINE[i])
				error(5);
			++i;
			c.g = ft_atof(LINE + i);
			while (LINE[i] && LINE[i] != ',')
				++i;
			if (!LINE[i])
				error(5);
			++i;
			c.b = ft_atof(LINE + i);
			while (LINE[i] && LINE[i] != ')')
				++i;
		}
		++i;
	}
	return (c);
}

void		parse_camera(t_env *env)
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
			else if (LINE[0] == 'r')
				camangle(env, PI * trans.x / 180, PI * trans.y / 180
						, PI * trans.z / 180);
		}
	}
}

void		parse_sphere(t_env *env)
{
	t_vector	pos;
	t_vector	trans;
	t_color		color;
	double		r;

	color = default_color();
	pos = default_pos();
	r = 1;
	while (env->file->next && (LINENEXT[0] == 't' || LINENEXT[0] == 'c'
				|| LINENEXT[0] == 'o'))
	{
		env->file = env->file->next;
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

void		parse_file(t_env *env)
{
	while (env->file)
	{
		if (!ft_strcmp(LINE, "camera"))
			parse_camera(env);
		else if (!ft_strcmp(LINE, "sphere"))
			parse_sphere(env);
		if (env->file)
			env->file = env->file->next;
	}
}
