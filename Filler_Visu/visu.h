/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   visu.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 00:31:26 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/17 02:42:40 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "libft/libft.h"
# include <unistd.h>

# define ANSI_CLR_SCREEN "\033[H\033[2J"
# define ANSI_CLR_LINE   "\033[2K"
# define ANSI_CURSOR_UP   "\033[1A"

typedef	struct	s_info
{
	char		*p1name;
	char		*p2name;
	int			mapheight;
	int			mapwidth;
	char		**map;
	int			p1placed;
	int			p2placed;
	char		*line;
}				t_info;

void	visu_print(t_info *game);
void	print_winner(t_info *game);

#endif