/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 13:52:19 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/20 14:11:45 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <mlx.h>

int		main(int argc, char **argv)
{
	t_mlxdata	mlxdata;

	mlxdata.mlx = mlx_init();
	mlxdata.img = mlx_new_image(mlxdata.mlx, WIDTH, HEIGHT);
	mlxdata.img_data = mlx_get_data_addr(mlxdata.img, &mlxdata.bits_per_pixel,
			&mlxdata.size_line, &mlxdata.endian);
	return (0);
}
