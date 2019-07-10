/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   testodel.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/24 17:13:54 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/10 17:12:19 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"

void	test_printmap(int	**map, t_init info)
{
	int i = 0;
	int j = 0;
	while (i < info.height)
	{
		j = 0;
		while (j < info.width)
		{
			printf("%d\t", map[i][j]);
			j++;
		}
		i++;
		printf("\n\n");
	}
	printf("\n\n");
}

void	test_printpiece(t_piece *piece)
{
	int i = 0;
	int j = 0;
	while (i < piece->height)
	{
		j = 0;
		while (j < piece->width)
		{
			printf("%d\t", piece->map[i][j]);
			j++;
		}
		i++;
		printf("\n\n");
	}
}

void	test_printheatmap(t_init *info, int	**hmap)
{
	int	x = 0;
	int y;

	while (x < info->height)
	{
		y = 0;
		while (y < info->width)
		{
			printf("%d\t", hmap[x][y]);
			y++;
		}
		x++;
		printf("\n\n"); 
	}
}