/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:41:47 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/27 15:51:24 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	my_mlx_pixel_put(t_var *var, int x, int y, int color)
{
	char	*dst;

	dst = var->addr + (y * var->line_l + x * (var->bpp / 8));
	*(unsigned int *)dst = color;
}

void    start_mlx(t_var *var)
{
    var->mlx = mlx_init();
    var->win = mlx_new_window(var->mlx, WIDTH, HEIGHT, "cub3d");
    var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
    var->addr = mlx_get_data_addr(var->img, &var->bpp, \
    &var->line_l, &var->endian);

    // draw_map

    // 매번 이미지 찍어주기
    mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
    
    
    // mlx key hook 추가

    mlx_loop(var->mlx);
}
