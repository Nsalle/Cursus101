/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checkaround.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/08 10:28:58 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/10 19:24:37 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int		check_around_map(t_init *fl, int x, int y, int i)
{
	if (x - 1 >= 0 && fl->map[x - 1][y] == i)
		return (1);
	if (y - 1 >= 0 && fl->map[x][y - 1] == i)
		return (1);
	if (y + 1 < fl->width && fl->map[x][y + 1] == i)
		return (1);
	if (x + 1 < fl->height && fl->map[x + 1][y] == i)
		return (1);
	if (x - 1 >= 0 && y - 1 >= 0 && fl->map[x - 1][y - 1] == i)
		return (1);
	if (x - 1 >= 0 && y + 1 < fl->width && fl->map[x - 1][y + 1] == i)
		return (1);
	if (x + 1 < fl->height && y - 1 >= 0 && fl->map[x + 1][y - 1] == i)
		return (1);
	if (x + 1 < fl->height && y + 1 < fl->width && fl->map[x + 1][y + 1] == i)
		return (1);
	return (0);
}

int		check_around_hmap(t_init *fl, int x, int y, int i)
{
	if (x - 1 >= 0 && fl->heatmap[x - 1][y] == i)
		return (1);
	if (y - 1 >= 0 && fl->heatmap[x][y - 1] == i)
		return (1);
	if (y + 1 < fl->width && fl->heatmap[x][y + 1] == i)
		return (1);
	if (x + 1 < fl->height && fl->heatmap[x + 1][y] == i)
		return (1);
	if (x + 1 < fl->height && y + 1 < fl->width && fl->heatmap[x + 1][y + 1] == i)
		return (1);
	if (x - 1 >= 0 && y - 1 >= 0 && fl->heatmap[x - 1][y - 1] == i)
		return (1);
	if (x + 1 < fl->height && y - 1 >= 0 && fl->heatmap[x + 1][y - 1] == i)
		return (1);
	if (x - 1 >= 0 && y + 1 < fl->width && fl->heatmap[x - 1][y + 1] == i)
		return (1);
	return (0);
}
