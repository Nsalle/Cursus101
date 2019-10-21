/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   visu_lemin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 16:56:58 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 19:24:24 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"
#include "sdl2/SDL.h"

typedef struct s_room
{
    int        x;
    int        y;

}              t_room;

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


void	visu_lemin(t_lem *lem)
{
	if (lem->biggestxcoord > 2000 || lem->biggestycoord > 1200)
	{
		ft_putendl_fd("Coords of Rooms are too big for visualizer, window size is 2000x1200 max", 2);
		exit(0);
	}
    t_room *rooms = (t_room*)malloc(sizeof(t_room) * (lem->nb_room));
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Init(SDL_INIT_VIDEO);


	// JEU DE TEST TABLEAU DE 6 SALLES
	// rooms[0].x = 50;
	// rooms[0].y = 50;

	// rooms[1].x = 400;
	// rooms[1].y = 50;

	// rooms[2].x = 900;
	// rooms[2].y = 150;

	// rooms[3].x = 50;
	// rooms[3].y = 800;

	// rooms[4].x = 700;
	// rooms[4].y = 900;

	// rooms[5].x = 190;
	// rooms[5].y = 400;

	int i = 0;
	while(i < lem->nb_room)
	{
		rooms[i].x = lem->room_coords[i][0];
		rooms[i].y = lem->room_coords[i][1];
		i++;
	}
    // Rendu de base (fond)
    SDL_CreateWindowAndRenderer(lem->biggestxcoord + 100, lem->biggestycoord + 100, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 163, 83, 0, 255);
    SDL_RenderClear(renderer);
    //

    // Boucle obligatoire sinon rien n'apparait (wtf ?)
    SDL_Event e;
    char quit = 0;
    while (!quit)
    {  
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = 1;
            if (e.type == SDL_KEYDOWN)
                quit = 1;
            if (e.type == SDL_MOUSEBUTTONDOWN)
                quit = 1;
            
        }
    }
    //

    // Boucle de creation des rectangles selon le nombre d'arguments
    i = 0;
    SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
    SDL_Rect rectangle;
	int	nbroom = lem->nb_room;
    while (nbroom > 0)
    {
        rectangle.x = rooms[i].x;
        rectangle.y = rooms[i].y;
        rectangle.w = 50;
        rectangle.h = 50;

        SDL_RenderFillRect(renderer, &rectangle);

        i ++;
		nbroom--;
    }
	
    // Affichage de lignes entre les rooms selon la matrice d'adjacence
	int matrixi = 0;
	int matrixj;

	while (matrixi < lem->nb_room)
	{
		matrixj = matrixi;
		while (matrixj < lem->nb_room)
		{
			if (lem->room_matrix[matrixi][matrixj] == '1')
				Draw_BigFatline(renderer, rooms[matrixi].x +25, rooms[matrixi].y +25, rooms[matrixj].x +25, rooms[matrixj].y +25);
			matrixj++;
		}
		matrixi++;
	}

    // Affichage du rendu avec Delay avant destruction
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    //

    // Destroy et termine
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
}