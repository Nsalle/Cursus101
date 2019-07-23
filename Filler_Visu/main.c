/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 00:25:57 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/23 22:05:51 by nsalle      ###    #+. /#+    ###.fr     */
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
	if (!(game->p1name = ft_strndup(game->line + 23,
		ft_strlen(game->line + 23) - 1)))
		return ;
	get_next_line(0, &game->line);
	get_next_line(0, &game->line);
	if (!(game->p2name = ft_strndup(game->line + 23,
		ft_strlen(game->line + 23) - 1)))
	{
		free(game->p1name);
		return ;
	}
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
		if (!(game->map[numline] = ft_strdup(game->line + 4)))
			emergency_free(numline, game);
		numline++;
	}
}

int		my_sleep(t_info *game)
{
	int	i;

	i = 0;
	while (i < game->speed)
		i++;
	return (0);
}

int		main(int argc, char **argv)
{
	t_info	game;

	game.speed = 30000000;
	if (argc > 1)
	{
		if (!(ft_strcmp(argv[1], "-s1")))
			game.speed = 300000000;
		if (!(ft_strcmp(argv[1], "-s3")))
			game.speed = 3000000;
	}
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
	free_all(game);
	return (0);
}
