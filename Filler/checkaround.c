/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checkaround.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/08 10:28:58 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/09 15:45:42 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int		check_around(t_init *info, int x, int y, int i, int **map)
{
	if (x - 1 >= 0 && y - 1 >= 0 && map[x - 1][y - 1] == i)
		return (1);
	if (x - 1 >= 0 && map[x - 1][y] == i)
		return (1);
	if (x - 1 >= 0 && y + 1 < info->width && map[x - 1][y + 1] == i)
		return (1);
	if (y - 1 >= 0 && map[x][y - 1] == i)
		return (1);
	if (y + 1 < info->width && map[x][y + 1] == i)
		return (1);
	if (x + 1 < info->height && y - 1 >= 0 && map[x + 1][y - 1] == i)
		return (1);
	if (x + 1 < info->height && map[x + 1][y] == i)
		return (1);
	if (x + 1 < info->height && y + 1 < info->width && map[x +1][y + 1] == i)
		return (1);
    return (0);
}
