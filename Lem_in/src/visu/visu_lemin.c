/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   visu_lemin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 16:56:58 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 06:03:55 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../lem_in.h"
#include "../../sdl2/SDL.h"

void	visu_lemin(t_lem *lem)
{
	t_visulem	vs;
	vs.room_size = 40;
    SDL_Window *window = NULL;
    vs.renderer = NULL;
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG);
	//TTF_Init();

	if (lem->biggestxcoord > 2000 || lem->biggestycoord > 1200 || lem->nb_ant > 9999 || lem->nb_room > 99)
	{
		ft_printf("There are some limitations to use the visualizer, for memory, screen size");
		ft_printf(", and because it would be too long and uninteresting to watch\n");
		ft_printf("Limits are:\n");
		ft_printf("-Window size 2000x1200 max, check the coords of your rooms\n");
		ft_printf("-Maximum number of ants is 9999\n");
		ft_printf("-Maximum number of rooms is 99\n");
		error_init(lem, &vs, 0);
	}

    // Rendu de base (fond)
	int	window_width = lem->biggestxcoord + 100;
	int	window_height = lem->biggestycoord + 100;
    if ((SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window, &vs.renderer)) != 0)
		error_init(lem, &vs, 0);
	init_items(lem, &vs);

	// Texte pour les Start et End
	//Start
	// SDL_Rect textrect;
	// TTF_Font *police = NULL;
	// police = TTF_OpenFont("src/visu/FFF_Tusj.ttf", 26);
	// SDL_Surface *texte = NULL;
	// SDL_Color LightGray = {255, 255, 255, 255};
	// texte = TTF_RenderText_Blended(police, "Start", LightGray);
	// texte->w = 70;
	// SDL_Texture *text = SDL_CreateTextureFromSurface(vs.renderer, texte);
	// textrect.x = vs.rooms[0].x - 10;
	// textrect.y = vs.rooms[0].y + 50;
	// textrect.h = 30;
	// textrect.w = 70;
	// SDL_RenderCopy(vs.renderer, text, NULL, &textrect);
	// // End
	// texte = TTF_RenderText_Blended(police, "End", LightGray);
	// texte->w = 54;
	// text = SDL_CreateTextureFromSurface(vs.renderer, texte);
	// SDL_FreeSurface(texte);
	// textrect.x = vs.rooms[lem->nb_room - 1].x - 2;
	// textrect.y = vs.rooms[lem->nb_room - 1].y + 50;
	// textrect.w = 54;
	// SDL_RenderCopy(vs.renderer, text, NULL, &textrect);


	////////////////////////////// JEU DE TEST
	////////////////////////////// JEU DE TEST
	////////////////////////////// JEU DE TEST

	lem->turns = (int***)malloc(sizeof(int**) * 3); 	//Alloc du nombre de tours;

	lem->turns[0] = (int**)malloc(sizeof(int*) * 3);	//Allocs pour chaque fourmis
	lem->turns[1] = (int**)malloc(sizeof(int*) * 4);
	lem->turns[2] = (int**)malloc(sizeof(int*) * 2);

	lem->turns[0][0] = (int*)malloc(sizeof(int) * 2);	//Allocs pour chaque move;
	lem->turns[0][1] = (int*)malloc(sizeof(int) * 2);
	lem->turns[1][0] = (int*)malloc(sizeof(int) * 2);
	lem->turns[1][1] = (int*)malloc(sizeof(int) * 2);
	lem->turns[1][2] = (int*)malloc(sizeof(int) * 2);
	lem->turns[2][0] = (int*)malloc(sizeof(int) * 2);

	// 		PREMIER TOUR
	lem->nb_turn = 3;
	lem->turns[0][0][0] = 0; 		// Tour numéro 0, la fourmis a deplacer est la numéro 0;
	lem->turns[0][0][1] = 1;	// Tour numeéro 0, la fourmis numéro 0 doit aller en case 1;

	lem->turns[0][1][0] = 1;		// Tour numéro 0, la fourmis a deplacer est la numero 1;
	lem->turns[0][1][1] = 2;	// Tour numero 0, la fourmis 1 doit aller en salle 2

	lem->turns[0][2] = NULL;
	// 		DEUXIEME TOUR

	lem->turns[1][0][0] = 0;		// Tour numéro 1, la fourmis a deplacer est la numéro 0;
	lem->turns[1][0][1] = 3;	// Tour numéro 1, la fourmis 0 doit aller en salle 3;

	lem->turns[1][1][0] = 1;		// Tour numéro 1, la fourmis a deplacer est la numéro 0;
	lem->turns[1][1][1] = 3;	// Tour numéro 1, la fourmis 1 doit aller en salle 3;

	lem->turns[1][2][0] = 2;		// Tour numéro 1, la fourmis a deplacer est la numéro 2;
	lem->turns[1][2][1] = 1;	// Tour numéro 1, la fourmis 2 doit aller en salle 1;

	lem->turns[1][3] = NULL;

	// 		TROISIEME TOUR

	lem->turns[2][0][0] = 2;	// Tour numéro 2, la fourmis a deplacer est la numéro 2;
	lem->turns[2][0][1] = 3;	// Tour numéro 2, la fourmis 2 doit aller en salle 3;

	lem->turns[2][1] = NULL;



	vs.bool_end = 0;
	SDL_bool program_launched = SDL_TRUE;

	while(program_launched)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					program_launched = SDL_FALSE;
					break;
				
				case SDL_KEYDOWN:
					if (vs.bool_end)
					{
						program_launched = SDL_FALSE;
						break;
					}
					settings(event, &vs);
					change_ant_pos(&vs, lem);
					if ((print_all(&vs, lem)) != 0)
						error_init(lem, &vs, 2);
					break;

				case SDL_MOUSEBUTTONDOWN:
					if (vs.bool_end)
					{
						program_launched = SDL_FALSE;
						break;
					}
					allmoves(lem, &vs);
					break;

				default:
					break;
			}
			if ((print_all(&vs, lem)) != 0)
				error_init(lem, &vs, 2);
		}
	}

    //  
    // Destroy et termine
    if(NULL != vs.renderer)
        SDL_DestroyRenderer(vs.renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    IMG_Quit();
	//TTF_CloseFont(police);
	//TTF_Quit();
    SDL_Quit();
}