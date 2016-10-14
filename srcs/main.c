/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 13:52:19 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/14 14:39:47 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_spot(t_env *env, double x, double y, double z, t_color color)
{
	t_vector	pos;

	pos.x = x;
	pos.y = y;
	pos.z = z;
	create_spot(env, pos, color);
}

int			main(int argc, char **argv)
{
	t_env		*env;
	t_color		color;
	t_vector	pos;
	int			fd;

	if ((env = (t_env*)malloc(sizeof(t_env))) == NULL)
		error(1);
	if (argc != 2)
		error(2);
	fd = open(argv[1], O_RDONLY);
	env->file = save_file(fd);
	env->obj = NULL;
	env->spot = NULL;
	parse_file(env);
	if (env->obj == NULL)
		error(6);
	if (env->spot == NULL)
		error(4);
	env->mlx = mlx_init();
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_data = mlx_get_data_addr(env->img, &env->bits_per_pixel,
			&env->size_line, &env->endian);
	raycaster(env);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "RTv1");
	mlx_key_hook(env->win, event, env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_loop(env->mlx);
	return (0);
}
