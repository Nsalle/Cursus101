/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heatmap.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/08 11:00:41 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/08 17:55:57 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int		countzero(t_init *info)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	x = 0;
	while (x < info->height)
	{
		y = 0;
		while (y < info->width)
		{
			if (info->heatmap[x][y] == 0)
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

int		check_hmap(t_init *info)
{
	int	x;
	int	y;

	x = 0;
	while (x < info->height)
	{
		y = 0;
		while (y < info->width)
		{
			if (info->heatmap[x][y] == 0)
			{
				if (countzero(info) == info->nbzero)
					return(0);
				else
					return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void	do_real_hmap(t_init *info)
{
	int	x;
	int	y;
	int	i;

	i = 1;
	while (check_hmap(info))
	{
		x = 0;
		info->nbzero = countzero(info);
		while (x < info->height)
		{
			y = 0;
			while (y < info->width)
			{
				if (info->heatmap[x][y] == 0 && check_around(info, x, y, i, info->heatmap))
					info->heatmap[x][y] = i + 1;
				y++;
			}
			x++;
		}
		i++;
	}
}

void	init_heat_map(int **map, t_init *info)
{
	int	x;
	int	y;

	x = 0;
	while (x < info->height)
	{
		y = 0;
		while (y < info->width)
		{
			if (info->heatmap[x][y] == 0 && check_around(info, x, y, info->enemy, map))
				info->heatmap[x][y] = 1;
			y++;
		}
		x++;
	}
	do_real_hmap(info);
}

void	create_heat_map(int	**map, t_init *info)
{
	int	x;
	int	y;

	info->nbzero = 0;
	if (!(info->heatmap = ft_memalloc(info->height * 8)))
		return ;
	x = 0;
	while (x < info->height)
	{
		y = 0;
		if (!(info->heatmap[x] = ft_memalloc(info->width * 8)))
			return ;
		while (y < info->width)
		{
			if (map[x][y] == 1)
				info->heatmap[x][y] = -1;
			if (map[x][y] == 2)
				info->heatmap[x][y] = -2;
			else if (map[x][y] == 0)
				info->heatmap[x][y] = 0;
			y++;
		}
		x++;
	}
	init_heat_map(map, info);
}