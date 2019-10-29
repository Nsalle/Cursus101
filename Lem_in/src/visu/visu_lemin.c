/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   visu_lemin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 16:56:58 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 08:13:58 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../lem_in.h"
#include "../../sdl2/SDL.h"

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
    IMG_Init(IMG_INIT_JPG);
	TTF_Init();

	int i = 0;
	while(i < lem->nb_room)
	{
		rooms[i].x = lem->room_coords[i][0];
		rooms[i].y = lem->room_coords[i][1];
		i++;
	}
    // Rendu de base (fond)
	int	window_width = lem->biggestxcoord + 100;
	int	window_height = lem->biggestycoord + 100;
    SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 163, 83, 0, 255);
    
	// Chargement du background
	SDL_Surface *image = NULL;
	SDL_Texture *background = NULL;
	SDL_Rect rrectangle;
	rrectangle.x = 0;
	rrectangle.y = 0;
	image = IMG_Load("src/visu/img/background.jpg");
	if (image == NULL)
		ft_printf("ERROR IMG");
	background = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	SDL_QueryTexture(background, NULL, NULL, &rrectangle.w, &rrectangle.h);
	SDL_RenderCopy(renderer, background, NULL, &rrectangle);
	//

    // Boucle de creation des rectangles selon le nombre d'arguments
    i =  1;
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_Rect rectangle;
	int	nbroom = lem->nb_room - 2;
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

    //*** Affichage de lignes entre les rooms selon la matrice d'adjacence
	DrawAllLines(lem, renderer, rooms);


	// Affichage des salles Start et End
    SDL_SetRenderDrawColor(renderer, 125, 125, 125, 255);
    rectangle.x = rooms[0].x;
    rectangle.y = rooms[0].y;
    rectangle.w = 50;
    rectangle.h = 50;
    SDL_RenderFillRect(renderer, &rectangle);
    rectangle.x = rooms[lem->nb_room - 1].x;
    rectangle.y = rooms[lem->nb_room - 1].y;
    rectangle.w = 50;
    rectangle.h = 50;
    SDL_RenderFillRect(renderer, &rectangle);
    

	// FOURMISSE
	image = NULL;
	background = NULL;
	rrectangle.x = rooms[0].x + 5;
    rrectangle.y = rooms[0].y + 5;
	printf("coords = %d, %d\n\n", rooms[0].x, rooms[0].y);
	image = IMG_Load("src/visu/img/FOURMISSE.png");
	if (image == NULL)
		ft_printf("ERROR IMG");
	background = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	SDL_QueryTexture(background, NULL, NULL, &rrectangle.w, &rrectangle.h);
	SDL_RenderCopy(renderer, background, NULL, &rrectangle);
	rrectangle.x = rooms[0].x + 50;
    rrectangle.y = rooms[0].y + 50;
	SDL_UpdateWindowSurfaceRects(window, &rrectangle, 1);
	//SDL_RenderCopy(renderer, background, NULL, &rrectangle);


	// Texte pour les Start et End
	//Start
	TTF_Font *police = NULL;
	police = TTF_OpenFont("src/visu/FFF_Tusj.ttf", 26);
	SDL_Surface *texte = NULL;
	SDL_Color LightGray = {255, 255, 255, 255};
	texte = TTF_RenderText_Blended(police, "Start", LightGray);
	texte->w = 70;
	SDL_Texture *text = SDL_CreateTextureFromSurface(renderer, texte);
	rrectangle.x = rooms[0].x - 10;
	rrectangle.y = rooms[0].y + 50;
	rrectangle.w = 70;
	SDL_RenderCopy(renderer, text, NULL, &rrectangle);
	// End
	texte = TTF_RenderText_Blended(police, "End", LightGray);
	texte->w = 54;
	text = SDL_CreateTextureFromSurface(renderer, texte);
	SDL_FreeSurface(texte);
	rrectangle.x = rooms[lem->nb_room - 1].x - 2;
	rrectangle.y = rooms[lem->nb_room - 1].y + 50;
	rrectangle.w = 54;
	SDL_RenderCopy(renderer, text, NULL, &rrectangle);

	/////////////////// MERDE
	int x = 50;
	int y = 50;
	int k = 0;
	while (k<1000)
	{
		// while (k < 100)
		// 	k++;
		SDL_Rect test = {x, y, 40, 40};
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, background, NULL, &test);
		SDL_RenderPresent(renderer);
		x++;
		y++;
		k++;
	}



    //*** Affichage du rendu et attente d'un clic avant destruction
    SDL_RenderPresent(renderer);
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
    // Destroy et termine
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    IMG_Quit();
	TTF_CloseFont(police);
	TTF_Quit();
    SDL_Quit();
}