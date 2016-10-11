/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:52:49 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/11 17:51:43 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_atof(char *str)
{
	double	a;
	double	b;
	int		i;
	int		j;

	j = 0;
	i = 0;
	a = 0.0;
	b = 0.0;
	while (!ft_isdigit(str[i]) && str[i] != '-')
		++i;
	a = (double)ft_atoi(str + i);
	while (str[i] != '.' && (ft_isdigit(str[i]) || str[i] == ' '))
		++i;
	if (str[i] == '.')
	{
		++i;
		while (ft_isdigit(str[i + j]))
			++j;
		b = (double)ft_atoi(str + i) / (pow(10, j));
	}
	return (a + b);
}
