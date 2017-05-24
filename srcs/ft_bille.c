/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pouet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:48:29 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/08 13:57:27 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_bille_help(t_t *t)
{
	t->c_r = (t->x / t->zoom + t->x1);
	t->c_i = (t->y / t->zoom + t->y1);
	t->z_r = 0;
	t->z_i = 0;
	t->i = 0;
	while (t->z_r * t->z_r + t->z_i * t->z_i < 4 && t->i < t->iteration_max)
	{
		t->tmp = t->z_r;
		t->z_r = t->z_r * t->z_r - t->z_i * t->z_i + t->c_r;
		t->z_i = -2 * t->z_i * t->tmp + t->c_i;
		t->i++;
	}
}

void	ft_bille(t_t *t)
{
	t->image_x = ((t->x2 - t->x1) * t->zoom);
	t->image_y = ((t->y2 - t->y1) * t->zoom);
	t->x = 0;
	while (t->x < t->image_x)
	{
		t->y = 0;
		while (t->y < t->image_y)
		{
			ft_bille_help(t);
			if (t->i == t->iteration_max)
				ft_put_pixel_to_img(0x000000, t, t->x, t->y);
			else
				ft_put_pixel_to_img(0x000000, t, t->x, t->y);
			t->y++;
		}
		t->x++;
	}
}
