/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_lines.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 05:45:09 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 05:45:24 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../lem_in.h"
#include "../../sdl2/SDL.h"

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
				Draw_BigFatline(renderer, room[matrixi].x +25, room[matrixi].y +25, room[matrixj].x +25, room[matrixj].y +25);
			matrixj++;
		}
		matrixi++;
	}
}