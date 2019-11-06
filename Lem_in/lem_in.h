/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/27 19:05:24 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 19:54:07 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include "sdl2/SDL.h"


typedef struct		s_ant
{
	SDL_Rect		pos;
	SDL_Rect		start;
	SDL_Rect		target;
	int				**path;
}					t_ant;
typedef struct		s_room
{
    int       		x;
    int     		y;

}              		t_room;
typedef struct		s_rooms
{
	char			*name;
	char			start;
	char			end;
}					t_rooms;

typedef struct		s_lem
{
	char			**tabfile;
	char			*start;
	char			*end;
	char			startfound;
	char			endfound;
	long long int	nb_ant;
	int				startindex;
	int				endindex;
	int				nb_room;
	int				curs;
	int				**room_coords;
	int				biggestxcoord;
	int				biggestycoord;
	char			**room_matrix;
	t_rooms			*rooms;
	t_list			list;
}					t_lem;

typedef	struct		s_visulem
{
	unsigned int	room_size;
	SDL_Renderer	*renderer;
	SDL_Texture 	*background;
	SDL_Rect 		bgrect;
	SDL_Rect 		startroom;
	SDL_Rect 		endroom;
	SDL_Rect		antrect;
	t_room			*rooms;
	t_ant			*ants;
}					t_visulem;


void				exit_lemin(void);
void				lem_parsing(t_lem *lem);
void				exit_early_parsing(t_lem *lem);

char				*clean_join(char *s1, char *s2);
char				*file_to_line(void);

void      			parse_rooms(t_lem *lem);

void				parse_coords(t_lem *lem);
void				visu_lemin(t_lem *lem);
void				DrawAllLines(t_lem *lem, SDL_Renderer *renderer, t_room *room);
void				print_all(t_visulem *vs, t_lem *lem);
void				create_ants(t_visulem *vs, t_lem *lem);

void				test(t_lem *lem);

#endif
