/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 13:19:38 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/10 14:01:09 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	error(int n)
{
	if (n == 1)
	{
		write(1, "Malloc failed", 13);
		exit(1);
	}
	else if (n == 2)
	{
		write(1, "Need 2 arguments", 16);
		exit(1);
	}
	else if (n == 3)
	{
		write(1, "get next line error", 19);
		exit(1);
	}
}