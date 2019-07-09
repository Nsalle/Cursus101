/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/22 16:48:09 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/09 15:50:14 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void	fl_transform_piece(t_piece *piece, t_init info)
{
	int i = 0;
	int j = 0;
	while (i < piece->height)
	{
		j = 0;
		while (j < piece->width)
		{
			if (piece->piece[i][j] == 46)
				piece->piece[i][j] = 0;
			else
				piece->piece[i][j] = info.me;
			j++;
		}
		i++;
	}
}

void	fl_parse_piece(t_piece *piece, t_init *info)
{
	int	i;
	int	j;

	i = 0;
	get_next_line(0, &info->line);
	piece->height = ft_atoi(info->line + 6);
	piece->width = ft_atoi(info->line + 7 + ft_intlen(piece->height));
	piece->piece = ft_memalloc(8 * piece->height);
	while (i < piece->height)
	{
		piece->piece[i] = ft_memalloc(8 * piece->width);
		j = 0;
		get_next_line(0, &info->line);
		while (j < piece->width)
		{
			piece->piece[i][j] = info->line[j];
			j++;
		}
		i++;
	}
	fl_transform_piece(piece, *info);
	info->bestscore = 9999;
}

int		**fl_parse_map(t_init *info)
{
	int		**map;
	int		numline;
	int		line_cursor;
	int		i;

	map = ft_memalloc(8 * info->height);
	numline = 0;
	get_next_line(0, &info->line);
	if (info->turn > 0)
		get_next_line(0, &info->line);
	while (numline < info->height)
	{
		info->turn++;
		line_cursor = 4;
		i = 0;
		map[numline] = ft_memalloc(8 * info->width);
		get_next_line(0, &info->line);
		while (line_cursor < info->width + 4)
		{
			if (info->line[line_cursor] == '.')
				map[numline][i] = 0;
			else if (info->line[line_cursor] == 'O' || info->line[line_cursor] == 'o')
				map[numline][i] = 1;
			else
				map[numline][i] = 2;
			line_cursor++;
			i++;
		}
		numline++;
	}
	return(map);
}

void    fl_get_info(t_init  *info)
{
	get_next_line(0, &info->line);
	info->nbPlayer = info->line[10];
	info->me = info->nbPlayer == '1' ? 1 : 2;
	info->enemy = info->me == 1 ? 2 : 1;
	while (1)
	{
		get_next_line(0, &info->line);
		if(ft_strstr(info->line, "Plateau"))
		{
			info->height = ft_atoi(info->line + 8);
			info->width = ft_atoi(info->line + ft_intlen(info->height) + 9);
			break ;
		}
	}
}

int     main(void)
{
	t_init  info;
	t_piece	piece;
	int turn;

	// TO REMOVE 
	int fd = open("log.txt", O_RDWR);
	//////////////////////////
	turn = 0;
	if (info.nbPlayer != '1' || info.nbPlayer != '2')
		fl_get_info(&info);
	info.turn = 0;
	while (1)
	{
		info.map = fl_parse_map(&info);
		fl_parse_piece(&piece, &info);

		create_heat_map(info.map, &info);
		fl_place(info.map, &info, &piece);
		
		ft_putnbr(info.bestx);
		ft_putchar(' ');
		ft_putnbr(info.besty);
		ft_putchar('\n');
		/*free(piece.piece);
		free(map);*/
		turn++;
		if (info.end)
			break;
		
		
		
		
		
		//////////////////////
		ft_putstr_fd("Turn: ", fd);
		ft_putnbr_fd(turn, fd);
		ft_putstr_fd("Play: ", fd);
		ft_putnbr_fd(info.bestx, fd);
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(info.besty, fd);
		ft_putchar_fd('\n', fd);
	}
}