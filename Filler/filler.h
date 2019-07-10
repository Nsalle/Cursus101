/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/22 16:49:22 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/10 19:38:12 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# ifndef FILLER_H
# define FILLER_H

#include "libft/libft.h"

# define ANSI_CLR_SCREEN "\033[H\033[2J"
# define ANSI_CLR_LINE   "\033[2K"
# define ANSI_CURSOR_UP   "\033[1A"

typedef struct  s_init
{
	char        nbPlayer;
    uint8_t     height;
    uint8_t     width;
    uint8_t     me;
    uint8_t     en;
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
    int         **map;
    uint8_t     x;
    uint8_t     y;
    int         score;
	int			countme;
}			    t_piece;

int     check_around_hmap(t_init *info, int x, int y, int i);
int		check_around_map(t_init *fl, int x, int y, int i);
void    fl_place(t_init *info, t_piece *piece);
void	create_heat_map(t_init *info);
void	fl_free_all(t_init *info, t_piece *piece);
void	fl_parse_map(t_init *fl);
void	fl_parse_piece(t_piece *piece, t_init *fl);
void	emergency_free(int **tab, int nlines);

void	test_printmap(int	**map, t_init info);// DELETE THIS BEFORE THE FINAL PUSH YOOOOOOOO
void	test_printpiece(t_piece *piece); // DELETE THIS BEFORE THE FINAL PUSH YOOOOOOOO
void	test_printheatmap(t_init *info, int	**hmap);// DELETE THIS BEFORE THE FINAL PUSH YOOOOOOOO

#endif