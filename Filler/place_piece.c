/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place_piece.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/24 19:16:24 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 22:15:13 by nsalle      ###    #+. /#+    ###.fr     */
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
		info->bestx = i - piece->minh;
		info->besty = j - piece->minw;
	}
	return (1);
}

int		fl_try(int i, int j, t_piece *p, t_init *fl)
{
	int	x;
	int	y;

	x = p->minh;
	while (x < p->height)
	{
		y = p->minw;
		while (y < p->width)
		{
			if (p->map[x][y] == fl->me)
			{
				if (fl->map[i + x - p->minh][j + y - p->minw] == fl->me)
					p->countme++;
				if (fl->map[i + x - p->minh][j + y - p->minw] == fl->en)
					return (-1);
				if (fl->heatmap[i + x - p->minh][j + y - p->minw] >= 0)
					p->score += (p->score = fl->heatmap[i + x - p->minh]\
					[j + y - p->minw]) > 0 ? p->score : 99;
			}
			y++;
		}
		x++;
	}
	return (1);
}

void	fl_place(t_init *fl, t_piece *piece)
{
	int	i;
	int	j;

	i = 0;
	fl->end = 0;
	while (i < fl->height)
	{
		j = 0;
		while (j < fl->width)
		{
			if (i + piece->height <= fl->height
				&& j + piece->width <= fl->width)
			{
				piece->score = 0;
				piece->countme = 0;
				if (fl_try(i, j, piece, fl) == 1 && piece->countme == 1)
					fl_checkscore(fl, piece, i, j);
			}
			j++;
		}
		i++;
	}
	if (fl->bestscore == 9999)
		fl->end = 1;
}
