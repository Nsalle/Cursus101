/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fl_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/10 14:57:10 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/10 17:45:25 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	emergency_free(int **tab, int nlines)
{
	int	i;

	i = 0;
	while (i < nlines)
		free(tab[i]);
	free(tab);
}

void	free_map(t_init *fl)
{
	int	x;

	x = 0;
	while (x < fl->height)
		free(fl->map[x++]);
	free(fl->map);
}

void	free_heatmap(t_init *fl)
{
	int	x;

	x = 0;
	while (x < fl->height)
		free(fl->heatmap[x++]);
	free(fl->heatmap);
}

void	free_piece(t_piece *piece)
{
	int	x;

	x = 0;
	while (x < piece->height)
		free(piece->map[x++]);
	free(piece->map);
}

void	fl_free_all(t_init *fl, t_piece *piece)
{
	free_map(fl);
	free_heatmap(fl);
	free_piece(piece);
}
