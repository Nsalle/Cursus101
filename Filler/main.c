/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/22 16:48:09 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/10 19:45:10 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	fl_get_info(t_init *fl)
{
	get_next_line(0, &fl->line);
	fl->nbPlayer = fl->line[10];
	fl->me = fl->nbPlayer == '1' ? 1 : 2;
	fl->en = fl->me == 1 ? 2 : 1;
	fl->turn = 0;
	while (1)
	{
		get_next_line(0, &fl->line);
		if (ft_strstr(fl->line, "Plateau"))
		{
			fl->height = ft_atoi(fl->line + 8);
			fl->width = ft_atoi(fl->line + ft_intlen(fl->height) + 9);
			break ;
		}
	}
}

int		main(void)
{
	t_init	fl;
	t_piece	piece;

	if (fl.nbPlayer != '1' || fl.nbPlayer != '2')
		fl_get_info(&fl);
	while (1)
	{
		get_next_line(0, &fl.line);
		fl_parse_map(&fl);
		fl_parse_piece(&piece, &fl);
		create_heat_map(&fl);
		fl_place(&fl, &piece);
		ft_putnbr(fl.bestx);
		ft_putchar(' ');
		ft_putnbr(fl.besty);
		ft_putchar('\n');
		fl_free_all(&fl, &piece);
		if (fl.end)
			break ;
	}
}
