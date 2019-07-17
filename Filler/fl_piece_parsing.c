/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fl_piece_parsing.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 21:13:27 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/17 02:51:23 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	fl_transform_piece(t_piece *piece, t_init *fl)
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
				piece->map[i][j] = fl->me;
			j++;
		}
		i++;
	}
}

void	fl_get_minheight(t_piece *piece, t_init *fl)
{
	int	i;
	int	j;
	int minh;
	int	stoph;

	i = 0;
	minh = 0;
	stoph = 0;
	piece->minh = 0;
	while (i < piece->height)
	{
		j = 0;
		while (j < piece->width)
		{
			if (piece->map[i][j] == (int)'*')
				stoph = 1;
			j++;
		}
		if (!stoph)
			piece->minh++;
		else
			break ;
		i++;
	}
	fl_transform_piece(piece, fl);
}

void	fl_get_minwidth(t_piece *piece, t_init *fl)
{
	int	i;
	int	j;
	int	minw;
	int	stopw;

	i = 0;
	piece->minw = piece->width;
	while (i < piece->height)
	{
		j = 0;
		minw = 0;
		stopw = 0;
		while (j < piece->width)
		{
			if (piece->map[i][j] == (int)'.' && !stopw)
				minw++;
			if (piece->map[i][j] == (int)'*')
				stopw = 1;
			j++;
		}
		if (minw < piece->minw)
			piece->minw = minw;
		i++;
	}
	fl_get_minheight(piece, fl);
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
	fl_get_minwidth(piece, fl);
	fl->bestscore = 9999;
}
