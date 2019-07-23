/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/23 20:34:54 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/23 22:07:19 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "visu.h"

void	emergency_free(int i, t_info *game)
{
	while (i >= 0)
	{
		free(game->map[i]);
		i--;
	}
	free(game->map);
	free(game->p1name);
	free(game->p2name);
}

void	free_all(t_info *game)
{
	int	i;

	i = 0;
	while (i < game->mapheight)
		free(game->map[i++]);
	free(game->map);
	free(game->p1name);
	free(game->p2name);
}