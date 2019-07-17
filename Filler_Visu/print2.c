/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 02:36:38 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/17 02:50:00 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "visu.h"

void	print_winner(t_info *game)
{
	if (game->p1placed > game->p2placed)
		ft_printf("\n\t{UND}{BLUE}{BOLD}%s WINS !{END}\n", game->p1name);
	else if (game->p2placed > game->p1placed)
		ft_printf("\n\t{UND}{RED}{BOLD}%s WINS !{END}\n", game->p2name);
	else
		ft_printf("{BOLD}{BLUE}W{RED}T{BLUE}F {END}IT'S A DRAW !!\n");
}
