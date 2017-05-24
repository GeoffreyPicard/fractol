/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:21:36 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/09 10:48:21 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	ft_key2(int key_code, t_t *t)
{
	if (key_code == 124)
	{
		t->x1 += 1 / (float)t->zoom * 25;
		t->x2 += 1 / (float)t->zoom * 25;
	}
	else if (key_code == 123)
	{
		t->x1 -= 1 / (float)t->zoom * 25;
		t->x2 -= 1 / (float)t->zoom * 25;
	}
	else if (key_code == 125)
	{
		t->y1 += 1 / (float)t->zoom * 25;
		t->y2 += 1 / (float)t->zoom * 25;
	}
	else if (key_code == 126)
	{
		t->y1 -= 1 / (float)t->zoom * 25;
		t->y2 -= 1 / (float)t->zoom * 25;
	}
}

static	void	ft_key3(int key_code, t_t *t)
{
	if (key_code == 49)
	{
		if (t->fractal == 1)
			ft_init_value_mandelrot(t);
		else if (t->fractal == 2)
			ft_init_value_julia(t);
		else if (t->fractal == 3)
			ft_init_value_carre(t);
		else if (t->fractal == 4)
			ft_init_value_bille(t);
		else if (t->fractal == 5)
			ft_init_value_burnship(t);
	}
}

int				ft_key(int key_code, t_t *t)
{
	if (key_code == 53)
		ft_close(t);
	else if (key_code == 91 && t->iteration_max < 300)
		t->iteration_max++;
	else if (key_code == 87 && t->iteration_max > 1)
		t->iteration_max--;
	else if (key_code == 12)
		t->b_color += 20;
	else if (key_code == 0)
		t->b_color -= 20;
	else if (key_code == 13)
		t->g_color += 20;
	else if (key_code == 1)
		t->g_color -= 20;
	else if (key_code == 14)
		t->r_color += 20;
	else if (key_code == 2)
		t->r_color -= 20;
	ft_key2(key_code, t);
	ft_key3(key_code, t);
	if (key_code == 46)
		t->julia += 0.1;
	ft_put_img(t);
	return (0);
}
