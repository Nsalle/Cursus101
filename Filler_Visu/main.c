/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 00:25:57 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/17 02:49:46 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "visu.h"

void	get_player_names(t_info *game)
{
	int	i;

	i = 0;
	while (i++ < 7)
		get_next_line(0, &game->line);
	game->p1name = ft_strndup(game->line + 23, ft_strlen(game->line + 23) - 1);
	get_next_line(0, &game->line);
	get_next_line(0, &game->line);
	game->p2name = ft_strndup(game->line + 23, ft_strlen(game->line + 23) - 1);
}

void	get_map_size(t_info *game)
{
	get_next_line(0, &game->line);
	game->mapheight = ft_atoi(game->line + 8);
	game->mapwidth = ft_atoi(game->line + ft_intlen(game->mapheight) + 9);
}

void	get_map(t_info *game)
{
	int	numline;

	numline = 0;
	if (!(game->map = ft_memalloc(sizeof(char *) * game->mapheight)))
		return ;
	while (numline < game->mapheight)
	{
		get_next_line(0, &game->line);
		game->map[numline] = ft_strdup(game->line + 4);
		numline++;
	}
}

int		main(void)
{
	t_info	game;

	get_player_names(&game);
	get_map_size(&game);
	while (get_next_line(0, &game.line))
	{
		if (ft_strstr(game.line, "Plateau"))
		{
			get_next_line(0, &game.line);
			get_map(&game);
			visu_print(&game);
		}
		get_next_line(0, &game.line);
	}
	print_winner(&game);
	return (0);
}
