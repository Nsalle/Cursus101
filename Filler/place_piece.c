/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place_piece.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/24 19:16:24 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/09 13:46:33 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		fl_checkscore(t_init *info, t_piece *piece, int i, int j)
{
	if (piece->score < info->bestscore)
	{
		info->bestscore = piece->score;
		info->bestx = i;
		info->besty = j;
	}
	return (1);
}

int		fl_try(int	i, int j, int **map, t_piece piece, t_init *info)
{
	int	x;
	int	y;
	int	countme;

	x = 0;
	piece.score = 0;
	countme = 0;
	while (x < piece.height)
	{
		y = 0;
		while (y < piece.width)
		{
			if (map[i + x][j + y] == info->me && piece.piece[x][y] == info->me)
				countme++;
			if (countme >= 2)
				return (0);
			if (map[i + x][j + y] == info->enemy && piece.piece[x][y] == info->me)
				return (0);
			if (piece.piece[x][y] == info->me && info->heatmap[i + x][j + y] >= 0)
			{
				piece.score += info->heatmap[i + x][j + y];
				if (info->heatmap[i + x][j + y] == 0)
					piece.score += 99;
			}
			y++;
		}
		x++;
	}
	if (countme == 1 && fl_checkscore(info, &piece, i, j))
		return (1);
	return (0);
}

void	fl_place(int **map, t_init *info, t_piece *piece)
{
	int	i;
	int	j;

	i = 0;
	info->end = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			if (i + piece->height <= info->height && j + piece->width <= info->width)
				fl_try(i, j, map, *piece, info);
			j++;
		}
		i++;
	}
	if (info->bestscore == 9999)
		info->end = 1;
}