/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/22 16:48:09 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/17 02:50:55 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "filler.h"

void	fl_get_info(t_init *fl)
{
	get_next_line(0, &fl->line);
	fl->nbplayer = fl->line[10];
	fl->me = fl->nbplayer == '1' ? 1 : 2;
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

	if (fl.nbplayer != '1' || fl.nbplayer != '2')
		fl_get_info(&fl);
	while (1)
	{
		get_next_line(0, &fl.line);
		fl_parse_map(&fl);
		fl_parse_piece(&piece, &fl);
		create_heat_map(&fl);
		fl_place(&fl, &piece);
		ft_printf("%d %d\n", fl.bestx, fl.besty);
		fl_free_all(&fl, &piece);
		if (fl.end)
			break ;
	}
	return (0);
}
