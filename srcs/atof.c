/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:52:49 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/10 15:11:09 by rfriscca         ###   ########.fr       */
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
	a = (double)ft_atoi(str);
	printf("%f\n", a);
	while (str[i] != '.')
		++i;
	++i;
	while (ft_isdigit(str[i + j]))
		++j;
	b = (double)ft_atoi(str + i) / (pow(10, j));
	printf("%f\n", b);
	return (a + b);
}
