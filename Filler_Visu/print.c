/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 01:39:03 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/17 02:34:08 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "visu.h"

void	print_score(t_info *game)
{
	ft_printf("\n{BLUE}%s placed:{BOLD} %d\t", game->p1name, game->p1placed);
	ft_printf("{RED}%s placed:{BOLD} %d{END}", game->p2name, game->p2placed);
}

void	colour_is_important(t_info *game, int i, int j)
{
	if (game->map[i][j] == 'o' || game->map[i][j] == 'O')
	{
		ft_printf("{BLUE}%c  {END}", game->map[i][j]);
		game->p1placed++;
	}
	else if (game->map[i][j] == 'x' || game->map[i][j] == 'X')
	{
		ft_printf("{RED}%c  {END}", game->map[i][j]);
		game->p2placed++;
	}
	else
		ft_printf("%c  {END}", game->map[i][j]);
}

void	print_map(t_info *game)
{
	int	i;
	int	j;

	i = 0;
	game->p1placed = 0;
	game->p2placed = 0;
	while (i < game->mapheight)
	{
		j = 0;
		while (j < game->mapwidth)
		{
			colour_is_important(game, i, j);
			j++;
		}
		i++;
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	print_header(t_info *game)
{
	ft_printf("{BLUE}%s {END}VS {RED}%s{END}\n", game->p1name, game->p2name);
}

void	visu_print(t_info *game)
{
	ft_printf(ANSI_CLR_SCREEN);
	print_header(game);
	print_map(game);
	print_score(game);
	usleep(50000);
}
