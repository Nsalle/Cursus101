/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 05:45:09 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 00:19:54 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../lem_in.h"
#include "../../sdl2/SDL.h"

int		create_ants(t_visulem *vs, t_lem *lem)
{
	int	i;

	if (SDL_SetRenderDrawColor(vs->renderer, 220, 0, 0, 255) != 0)
		ret_msg(1, "error on RenderColor in create_ants()");
	i = 0;
	while (i < lem->nb_ant)
	{
		if (SDL_RenderFillRect(vs->renderer, &vs->ants[i].pos) != 0)
			ret_msg(1, "error on RenderFillRect in create_ants()");
		i++;
	}
	return (0);
}

void	print_all(t_visulem *vs, t_lem *lem)
{
	SDL_Rect rectangle;
	int	nbroom = lem->nb_room - 2;
	int i = 1;
	SDL_RenderClear(vs->renderer);
	SDL_RenderCopy(vs->renderer, vs->background, NULL, &vs->bgrect);
	SDL_SetRenderDrawColor(vs->renderer, 100, 100, 100, 255);
    while (nbroom > 0)
    {
        rectangle.x = vs->rooms[i].x;
        rectangle.y = vs->rooms[i].y;
        rectangle.w = vs->room_size;
        rectangle.h = vs->room_size;

        SDL_RenderFillRect(vs->renderer, &rectangle);

        i ++;
		nbroom--;
    }
	DrawAllLines(lem, vs, vs->rooms);
	SDL_SetRenderDrawColor(vs->renderer, 45, 45, 45, 255);
	SDL_RenderFillRect(vs->renderer, &vs->endroom);
	SDL_SetRenderDrawColor(vs->renderer, 160, 160, 160, 255);
	SDL_RenderFillRect(vs->renderer, &vs->startroom);
	create_ants(vs, lem);
	SDL_RenderPresent(vs->renderer);
}

int		Draw_Fatline(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
	SDL_RenderDrawLine(renderer, x1 - 1, y1, x2 - 1, y2);
	SDL_RenderDrawLine(renderer, x1, y1 - 1, x2, y2 - 1);
	SDL_RenderDrawLine(renderer, x1 + 1, y1, x2 + 1, y2);
	SDL_RenderDrawLine(renderer, x1, y1 + 1, x2, y2 + 1);

	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	return(0);
}

int		Draw_BigFatline(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
	Draw_Fatline(renderer, x1, y1, x2, y2);

	SDL_RenderDrawLine(renderer, x1 - 2, y1, x2 - 2, y2);
	SDL_RenderDrawLine(renderer, x1, y1 - 2, x2, y2 - 2);
	SDL_RenderDrawLine(renderer, x1 + 2, y1, x2 + 2, y2);
	SDL_RenderDrawLine(renderer, x1, y1 + 2, x2, y2 + 2);
	return(0);
}

int		DrawAllLines(t_lem *lem, t_visulem *vs, t_room *room)
{
	int matrixi = 0;
	int matrixj;

	while (matrixi < lem->nb_room)
	{
		matrixj = matrixi;
		while (matrixj < lem->nb_room)
		{
			if (lem->room_matrix[matrixi][matrixj] == '1')
				Draw_BigFatline(vs->renderer, room[matrixi].x + vs->room_size / 2,
				room[matrixi].y + vs->room_size / 2,
				room[matrixj].x + vs->room_size / 2,
				room[matrixj].y + vs->room_size / 2);
			matrixj++;
		}
		matrixi++;
	}
	return (0);
}