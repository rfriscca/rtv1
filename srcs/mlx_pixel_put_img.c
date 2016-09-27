/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 14:59:45 by rfriscca          #+#    #+#             */
/*   Updated: 2016/09/27 16:50:10 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	mlx_pixel_put_img(t_env *env, int color)
{
	int		goto_pixel;

	goto_pixel = env->x * env->size_line + env->y * 4;
	env->img_data[goto_pixel] = ((color & 0xff0000) >> 16);
	env->img_data[goto_pixel + 1] = ((color & 0x00ff00) >> 8);
	env->img_data[goto_pixel + 2] = (color & 0x0000ff);
	env->img_data[goto_pixel + 3] = 0;
}
