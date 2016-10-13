/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:33:07 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/13 13:49:31 by rfriscca         ###   ########.fr       */
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
	color_correc_obj(c);
	return (c);
}

t_color		get_color_spot(t_env *env)
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
	color_correc_spot(c);
	return (c);
}

void		free_file(t_env *env)
{
	if (env->file->line)
		free(env->file->line);
	if (env->file)
		free(env->file);
}

void		parse_file(t_env *env)
{
	t_line	*file;

	env->i = 0;
	while (env->file)
	{
		if (!ft_strcmp(LINE, "camera"))
			parse_camera(env);
		else if (!ft_strcmp(LINE, "sphere"))
			parse_sphere(env);
		else if (!ft_strcmp(LINE, "spot"))
			parse_spot(env);
		else if (!ft_strcmp(LINE, "plane"))
			parse_plane(env);
		else if (!ft_strcmp(LINE, "cylinder"))
			parse_cylinder(env);
		else if (!ft_strcmp(LINE, "cone"))
			parse_cone(env);
		else
			error(5);
		if (env->file)
		{
			file = env->file->next;
			free_file(env);
			env->file = file;
		}
	}
}
