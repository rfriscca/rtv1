/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:33:07 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/10 14:52:20 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	test_line(t_env *env)
{
	t_vector	transfo[258];

	if (env->file->line[0] == 'c')
}

void	parse_file(t_env *env)
{
	while (env->file)
	{
		test_line(env);
		env->file = env->file->next;
	}
}
