/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place_piece.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/24 19:16:24 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/10 18:43:27 by nsalle      ###    #+. /#+    ###.fr     */
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

void	fl_try(int i, int j, t_piece *piece, t_init *fl)
{
	int	x;
	int	y;

	x = 0;
	while (x < piece->height)
	{
		y = 0;
		while (y < piece->width)
		{
			if (fl->map[i + x][j + y] == fl->me && piece->map[x][y] == fl->me)
				piece->countme++;
			if (fl->map[i + x][j + y] == fl->en && piece->map[x][y] == fl->me)
				return ;
			if (piece->map[x][y] == fl->me && fl->heatmap[i + x][j + y] >= 0)
			{
				piece->score += fl->heatmap[i + x][j + y];
				if (fl->heatmap[i + x][j + y] == 0)
					piece->score += 99;
			}
			y++;
		}
		x++;
	}
	if (piece->countme == 1)
		fl_checkscore(fl, piece, i, j);
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
				fl_try(i, j, piece, fl);
			}
			j++;
		}
		i++;
	}
	if (fl->bestscore == 9999)
		fl->end = 1;
}
