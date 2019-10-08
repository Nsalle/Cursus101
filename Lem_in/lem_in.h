/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/27 19:05:24 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 23:23:34 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct		s_rooms
{
	int				id;
	char			*name;
	char			*coords;
}					t_rooms;

typedef struct		s_lem
{
	char			**tabfile;
	char			*start;
	char			*end;
	char			startfound;
	char			endfound;
	long long int	nb_ant;
	int				nb_room;
	int				curs;
	t_rooms			*rooms;
	t_list			list;
}					t_lem;

void				exit_lemin(void);
void				lem_parsing(t_lem *lem);
void				exit_early_parsing(t_lem *lem);

void				test(t_lem *lem);

#endif
