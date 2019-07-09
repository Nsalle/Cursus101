/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/22 16:49:22 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/09 15:48:16 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# ifndef FILLER_H
# define FILLER_H

#include "libft/libft.h"

typedef struct  s_init
{
	char        nbPlayer;
    uint8_t     height;
    uint8_t     width;
    uint8_t     me;
    uint8_t     enemy;
    char        *line;
    int         turn;
    uint8_t     end;
    int         **heatmap;
    int         bestx;
    int         besty;
    int         bestscore;
    int         nbzero;
	int			**map;
}               t_init;

typedef struct	s_piece
{
	uint8_t     height;
    uint8_t     width;
    int         **piece;
    uint8_t     x;
    uint8_t     y;
    int         score;
}			    t_piece;

int     check_around(t_init *info, int x, int y, int i, int **map);
void    fl_place(int **map, t_init *info, t_piece *piece);
void	create_heat_map(int	**map, t_init *info);

void	test_printmap(int	**map, t_init info);// DELETE THIS BEFORE THE FINAL PUSH YOOOOOOOO
void	test_printpiece(t_piece *piece); // DELETE THIS BEFORE THE FINAL PUSH YOOOOOOOO
void	test_printheatmap(t_init *info, int	**hmap);// DELETE THIS BEFORE THE FINAL PUSH YOOOOOOOO

#endif