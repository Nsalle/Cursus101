/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fl_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/10 17:27:43 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/10 19:01:14 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	fl_transform_piece(t_piece *piece, t_init fl)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < piece->height)
	{
		j = 0;
		while (j < piece->width)
		{
			if (piece->map[i][j] == (int)'.')
				piece->map[i][j] = 0;
			else
				piece->map[i][j] = fl.me;
			j++;
		}
		i++;
	}
}

void	fl_parse_piece(t_piece *piece, t_init *fl)
{
	int	i;
	int	j;

	i = 0;
	get_next_line(0, &fl->line);
	piece->height = ft_atoi(fl->line + 6);
	piece->width = ft_atoi(fl->line + 7 + ft_intlen(piece->height));
	if (!(piece->map = ft_memalloc(sizeof(int *) * piece->height)))
		return ;
	while (i < piece->height)
	{
		if (!(piece->map[i] = ft_memalloc(sizeof(int *) * piece->width)))
			emergency_free(piece->map, i);
		j = 0;
		get_next_line(0, &fl->line);
		while (j < piece->width)
		{
			piece->map[i][j] = fl->line[j];
			j++;
		}
		i++;
	}
	fl_transform_piece(piece, *fl);
	fl->bestscore = 9999;
}

void	fl_make_map(t_init *fl, int lc, int i, int numline)
{
	if (fl->line[lc] == '.')
		fl->map[numline][i] = 0;
	else if (fl->line[lc] == 'O' || fl->line[lc] == 'o')
		fl->map[numline][i] = 1;
	else
		fl->map[numline][i] = 2;
}

void	fl_parse_map(t_init *fl)
{
	int		numline;
	int		lc;
	int		i;

	if (!(fl->map = ft_memalloc(sizeof(int *) * fl->height)))
		return ;
	numline = 0;
	if (fl->turn > 0)
		get_next_line(0, &fl->line);
	fl->turn++;
	while (numline < fl->height)
	{
		lc = 4;
		i = 0;
		if (!(fl->map[numline] = ft_memalloc(sizeof(int *) * fl->width)))
			emergency_free(fl->map, numline);
		get_next_line(0, &fl->line);
		while (lc < fl->width + 4)
			fl_make_map(fl, lc++, i++, numline);
		numline++;
	}
}