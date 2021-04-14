/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/06 08:42:09 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_ne_vert_inte(t_all *vars, float angle, int *xdm, int i)
{
	int	y;
	int	x;
	int	j;
	int	xmax;
	float	tmp;
	float	len;

	y = (vars->map.cam.posy * 64);
	x = (vars->map.cam.posx * 64) + 32 + (32 * (sin(angle) / cos(angle)));
	j = 0;
        while (vars->map.box[j])
                j++;
        if (y / 64 > j || y / 64 < 0)
                return (0);
        xmax = ft_lenmax_mpline(vars->map.box);
        if (x / 64 < 0 || x / 64 > xmax)
                return (0);
	while (vars->map.box[y / 64][x / 64] == '0')
	{
		y = y - 64;
		x = x + (64 / (sin(angle) / cos(angle)));
		if (y / 64 > j || y / 64 < 0)
                        return (0);
                if (x / 64 < 0 || x / 64 > xmax)
                        return (0);
	}
	xdm[i] = x % 64;
	tmp = pow((vars->map.cam.posy * 64) + 32 - y, 2) + 
		pow((vars->map.cam.posx * 64) + 32 - x, 2);
	len = sqrt(tmp);
	return (len);
}

float	ft_nw_vert_inte(t_all *vars, float angle, int *xdm, int i)
{
	int	y;
	int	x;
	int	j;
	int	xmax;
	float	tmp;
	float	len;

	y = (vars->map.cam.posy * 64);
	x = (vars->map.cam.posx * 64) + 32 - (32 * (sin(angle) / cos(angle)));
	j = 0;
        while (vars->map.box[j])
                j++;
        if (y / 64 > j || y / 64 < 0)
                return (0);
        xmax = ft_lenmax_mpline(vars->map.box);
        if (x / 64 < 0 || x / 64 > xmax)
                return (0);
	while (vars->map.box[y / 64][x / 64] == '0')
	{
		y = y - 64;
		x = x - (64 / (sin(angle) / cos(angle)));
		if (y / 64 > j || y / 64 < 0)
                        return (0);
                if (x / 64 < 0 || x / 64 > xmax)
                        return (0);
	}
	xdm[i] = x % 64;
	tmp = pow((vars->map.cam.posy * 64) + 32 - y, 2) + 
		pow((vars->map.cam.posx * 64) + 32 - x, 2);
	len = sqrt(tmp);
	return (len);
}

float	ft_sw_vert_inte(t_all *vars, float angle, int *xdm, int i)
{
	int	y;
	int	x;
	int	j;
	int	xmax;
	float	tmp;
	float	len;

	y = (vars->map.cam.posy * 64) + 64;
	x = (vars->map.cam.posx * 64) + 32 - (32 * (sin(angle) / cos(angle)));
	j = 0;
        while (vars->map.box[j])
                j++;
        if (y / 64 > j || y / 64 < 0)
                return (0);
        xmax = ft_lenmax_mpline(vars->map.box);
        if (x / 64 < 0 || x / 64 > xmax)
                return (0);
	while (vars->map.box[y / 64][x / 64] == '0')
	{
		y = y + 64;
		x = x - (64 / (sin(angle) / cos(angle)));
		if (y / 64 > j || y / 64 < 0)
                        return (0);
                if (x / 64 < 0 || x / 64 > xmax)
                        return (0);
	}
	xdm[i] = x % 64;
	tmp = pow((vars->map.cam.posy * 64) + 32 - y, 2) + 
		pow((vars->map.cam.posx * 64) + 32 - x, 2);
	len = sqrt(tmp);
	return (len);
}

float	ft_se_vert_inte(t_all *vars, float angle, int *xdm, int i)
{
	int	y;
	int	x;
	int	j;
	int	xmax;
	float	tmp;
	float	len;

	y = (vars->map.cam.posy * 64) + 64;
	x = (vars->map.cam.posx * 64) + 32 + (32 * (sin(angle) / cos(angle)));
	j = 0;
	while (vars->map.box[j])
		j++;
	if (y / 64 > j || y / 64 < 0)
		return (0);
	xmax = ft_lenmax_mpline(vars->map.box);
	if (x / 64 < 0 || x / 64 > xmax)
		return (0);
	while (vars->map.box[y / 64][x / 64] == '0')
	{
		y = y + 64;
		x = x + (64 / (sin(angle) / cos(angle)));
		if (y / 64 > j || y / 64 < 0)
			return (0);
		if (x / 64 < 0 || x / 64 > xmax)
			return (0);
	}
	xdm[i] = x % 64;
	tmp = pow((vars->map.cam.posy * 64) + 32 - y, 2) + 
		pow((vars->map.cam.posx * 64) + 32 - x, 2);
	len = sqrt(tmp);
	return (len);
}

float	ft_vert_intersect(t_all *vars, float angle, int *xdm, int i)
{
	float	res;

	res = 0;
	if (angle > 0 && angle < (M_PI / 2))
		res = ft_ne_vert_inte(vars, angle, xdm, i);
	else if (angle > (M_PI / 2) && angle < M_PI)
		res = ft_nw_vert_inte(vars, angle, xdm , i);
	else if (angle > M_PI && angle < (3 * M_PI / 2))
		res = ft_sw_vert_inte(vars, angle, xdm , i);
	else
		res = ft_se_vert_inte(vars, angle, xdm , i);
	return (res);
}
