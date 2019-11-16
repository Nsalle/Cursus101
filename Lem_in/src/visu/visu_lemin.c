/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   visu_lemin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 16:56:58 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/16 18:26:38 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../lem_in.h"
#include "../../sdl2/SDL.h"

// void	move_this_ant(t_lem *lem, t_visulem *vs, t_ant *ant, int tour, int numant)
// {
// 	if (ant->turn < ant->nbmoves)
// 	{
// 		ant->pos.x = vs->ants[lem->turns[tour][numant][0]].path[ant->turn][0];
// 		ant->pos.y = vs->ants[lem->turns[tour][numant][0]].path[ant->turn][1];
// 	}
// 	if (ant->turn + ant->nbmoves / 50 >= ant->nbmoves)
// 		ant->turn = ant->nbmoves - 1;
// 	else if (ant->nbmoves / 50 == 0)
// 		ant->turn++;
// 	else
// 		ant->turn += ant->nbmoves / 50;
// }

// void	my_delay(int clock)
// {
// 	int	wait;

// 	wait = SDL_GetTicks() - clock;
// 	if (wait < 33)
// 		SDL_Delay(33 - wait);
// }

// void	allmoves(t_lem *lem, t_visulem *vs)
// {
// 	int tour = 0;
// 	int	ant;
// 	int i;
// 	int j;
// 	int alloc;
// 	int turn = 0;
// 	int	totalmoves;

// 	int clock;
// 	while (tour < lem->nb_turn)
// 	{
// 		ant = 0;
// 		totalmoves = 0;
// 		while (lem->turns[tour][ant] != NULL)
// 		{
// 			i = ft_abs(vs->ants[lem->turns[tour][ant][0]].pos.x - (vs->rooms[lem->turns[tour][ant][1]].x + vs->room_size / 4));
// 			j = ft_abs(vs->ants[lem->turns[tour][ant][0]].pos.y - (vs->rooms[lem->turns[tour][ant][1]].y + vs->room_size / 4));
// 			if (i > j)
// 				alloc = i;
// 			else
// 				alloc = j;
// 			if ((vs->ants[lem->turns[tour][ant][0]].path = (int**)malloc(sizeof(int*) * alloc)) == NULL)
// 				error_init(lem, &vs, 2);

// 			if ((vs->ants[lem->turns[tour][ant][0]].nbmoves = bresenham(&vs->ants[lem->turns[tour][ant][0]].pos,
// 																	vs->rooms[lem->turns[tour][ant][1]].x + vs->room_size / 4,
// 																	vs->rooms[lem->turns[tour][ant][1]].y + vs->room_size / 4,
// 																	vs->ants[lem->turns[tour][ant][0]].path)) == NULL)
// 				error_init(lem, &vs, 2);
// 			if (vs->ants[lem->turns[tour][ant][0]].nbmoves > totalmoves)
// 				totalmoves = vs->ants[lem->turns[tour][ant][0]].nbmoves;
// 			ant++;
// 		}
// 		turn = 0;
// 		while (turn <= 60)
// 		{
// 			clock = SDL_GetTicks();
// 			ant = 0;
// 			while (lem->turns[tour][ant] != NULL)
// 			{
// 				move_this_ant(lem, vs, &vs->ants[lem->turns[tour][ant][0]], tour, ant);
// 				ant++;
// 			}
// 			if ((print_all(&vs, lem)) != 0)
// 				error_init(lem, &vs, 2);
// 			turn++;
// 			my_delay(clock);
// 		}
// 		ant = 0;
// 		while (lem->turns[tour][ant] != NULL)
// 		{
// 			vs->ants[lem->turns[tour][ant][0]].turn = 0;
// 			free_path(vs->ants[lem->turns[tour][ant][0]]);
// 			ant++;
// 		}
// 		tour++;
// 	}
// 	vs->bool_end = 1;
// 	return (0);
// }

void	visu_lemin(t_lem *lem)
{
	if (lem->biggestxcoord > 2000 || lem->biggestycoord > 1200)
	{
		ft_putendl_fd("Coords of Rooms are too big for visualizer, window size is 2000x1200 max", 2);
		exit(0);
	}
	t_visulem	vs;
	vs.room_size = 40;
    SDL_Window *window = NULL;
    vs.renderer = NULL;
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG);
	//TTF_Init();

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