/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/27 19:05:24 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 11:56:38 by nsalle      ###    #+. /#+    ###.fr     */
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
	int				**path;
	int				nbmoves;
	int				turn;
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
	int				***turns;
	int				nb_turn;
}					t_lem;

typedef	struct		s_visulem
{
	uint8_t			room_size;
	SDL_Renderer	*renderer;
	SDL_Texture 	*background;
	SDL_Rect 		bgrect;
	SDL_Rect 		startroom;
	SDL_Rect 		endroom;
	SDL_Rect		antrect;
	t_room			*rooms;
	t_ant			*ants;
	char			bool_end;
}					t_visulem;


void				exit_lemin(void);
void				lem_parsing(t_lem *lem);
void				exit_early_parsing(t_lem *lem);

char				*clean_join(char *s1, char *s2);
char				*file_to_line(void);

void      			parse_rooms(t_lem *lem);

void				check_dupe_roomname(t_lem *lem);
void				check_com_cut(t_lem *lem, int i, char start);
void				check_roomerrors(t_lem *lem);

void				parse_coords(t_lem *lem);
void				visu_lemin(t_lem *lem);
int					DrawAllLines(t_lem *lem, t_visulem *vs, t_room *room);
int					print_all(t_visulem *vs, t_lem *lem);
int					create_ants(t_visulem *vs, t_lem *lem);
void   				free_path(t_ant ant);
void				error_init(t_lem *lem, t_visulem *vs, uint8_t ret);
int    				ret_msg(uint8_t i, char *msg);
void     			init_items(t_lem *lem, t_visulem *vs);
int					bresenham(SDL_Rect *rect, int x2, int y2, int **path);
void   				settings(SDL_Event event, t_visulem *vs);
void				change_ant_pos(t_visulem *vs, t_lem *lem);
void				test(t_lem *lem);
void				allmoves(t_lem *lem, t_visulem *vs);


#endif
