/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 05:45:09 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 22:38:52 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../lem_in.h"
#include "../../sdl2/SDL.h"

#define MIDROOM_SIZE 20

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
	DrawAllLines(lem, vs->renderer, vs->rooms);
	SDL_SetRenderDrawColor(vs->renderer, 45, 45, 45, 255);
	SDL_RenderFillRect(vs->renderer, &vs->endroom);
	SDL_SetRenderDrawColor(vs->renderer, 160, 160, 160, 255);
	SDL_RenderFillRect(vs->renderer, &vs->startroom);
	create_ants(vs, lem);
	SDL_RenderPresent(vs->renderer);
}

void	Draw_Fatline(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
	SDL_RenderDrawLine(renderer, x1 - 1, y1, x2 - 1, y2);
	SDL_RenderDrawLine(renderer, x1, y1 - 1, x2, y2 - 1);
	SDL_RenderDrawLine(renderer, x1 + 1, y1, x2 + 1, y2);
	SDL_RenderDrawLine(renderer, x1, y1 + 1, x2, y2 + 1);

	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void	Draw_BigFatline(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
	Draw_Fatline(renderer, x1, y1, x2, y2);

	SDL_RenderDrawLine(renderer, x1 - 2, y1, x2 - 2, y2);
	SDL_RenderDrawLine(renderer, x1, y1 - 2, x2, y2 - 2);
	SDL_RenderDrawLine(renderer, x1 + 2, y1, x2 + 2, y2);
	SDL_RenderDrawLine(renderer, x1, y1 + 2, x2, y2 + 2);
}

void	DrawAllLines(t_lem *lem, SDL_Renderer *renderer, t_room *room)
{
	int matrixi = 0;
	int matrixj;

	while (matrixi < lem->nb_room)
	{
		matrixj = matrixi;
		while (matrixj < lem->nb_room)
		{
			if (lem->room_matrix[matrixi][matrixj] == '1')
				Draw_BigFatline(renderer, room[matrixi].x + MIDROOM_SIZE,
				room[matrixi].y +MIDROOM_SIZE,
				room[matrixj].x +MIDROOM_SIZE,
				room[matrixj].y +MIDROOM_SIZE);
			matrixj++;
		}
		matrixi++;
	}
}