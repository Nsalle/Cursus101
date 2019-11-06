/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   visu_lemin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 16:56:58 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 22:46:14 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../lem_in.h"
#include "../../sdl2/SDL.h"

#define ROOM_SIZE 40

int			bresenham(SDL_Rect *rect, int x2, int y2, int **path)
{
	int x, y;
	int Dx,Dy;
  	int xincr,yincr;
  	int erreur;
  	int i;
	int count = 0;
	
	Dx = ft_abs(x2 - rect->x);
  	Dy = ft_abs(y2 - rect->y);
	  if(rect->x<x2)
    xincr = 1;
  	else
    xincr = -1;
  	if(rect->y<y2)
    yincr = 1;
  	else
    yincr = -1;

  	x = rect->x;
  	y = rect->y;
  	if(Dx>Dy)
    {
      erreur = Dx/2;
      for(i=0;i<Dx;i++)
        {
          x += xincr;
          erreur += Dy;
          if(erreur>Dx)
            {
              erreur -= Dx;
              y += yincr;
            }
		path[count] = (int*)malloc(sizeof(int) * 2);
		path[count][0] = x;
		path[count][1] = y;
		count++;
        }
    }
  else
    {
      erreur = Dy/2;
      for(i=0;i<Dy;i++)
        {
          y += yincr;
          erreur += Dx;
          if(erreur>Dy)
            {
              erreur -= Dy;
              x += xincr;
            }
		path[count] = (int*)malloc(sizeof(int) * 2);
		path[count][0] = x;
		path[count][1] = y;
		count++;
        }
    }
	ft_printf("\nlignes: %d\n", count);
	return(count);
}

void	create_ants(t_visulem *vs, t_lem *lem)
{
	int	i;

	SDL_SetRenderDrawColor(vs->renderer, 220, 0, 0, 255);
	i = 0;
	while (i < lem->nb_ant)
	{
		SDL_RenderFillRect(vs->renderer, &vs->ants[i].pos);
		i++;
	}
}

void	create_antpath(t_visulem *vs, t_lem *lem, t_ant *ant)
{
	int i = ft_abs(ant->pos.x - vs->rooms[lem->nb_room - 1].x);
	int j = ft_abs(ant->pos.y - vs->rooms[lem->nb_room - 1].y);
	int alloc;
	int	nbmoves;

	if (i > j)
		alloc = i;
	else
		alloc = j;
	ant->path = (int**)malloc(sizeof(int*) * alloc);
	nbmoves = bresenham(&ant->pos, vs->rooms[lem->nb_room - 1].x + 10, vs->rooms[lem->nb_room - 1].y + 10, ant->path);
	int test = 0;
	while (test < nbmoves)
	{
		ant->pos.x = ant->path[test][0];
		ant->pos.y = ant->path[test][1];
		test+=5;
		print_all(vs, lem);
	}
}

void	visu_lemin(t_lem *lem)
{
	if (lem->biggestxcoord > 2000 || lem->biggestycoord > 1200)
	{
		ft_putendl_fd("Coords of Rooms are too big for visualizer, window size is 2000x1200 max", 2);
		exit(0);
	}
	t_visulem	vs;
	vs.room_size = ROOM_SIZE;
	vs.rooms = (t_room*)malloc(sizeof(t_room) * (lem->nb_room));
    SDL_Window *window = NULL;
    vs.renderer = NULL;
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG);
	TTF_Init();

	int i = 0;
	while(i < lem->nb_room)
	{
		vs.rooms[i].x = lem->room_coords[i][0];
		vs.rooms[i].y = lem->room_coords[i][1];
		i++;
	}
    // Rendu de base (fond)
	int	window_width = lem->biggestxcoord + 100;
	int	window_height = lem->biggestycoord + 100;
    SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window, &vs.renderer);
    
	// Chargement du background
	SDL_Surface *image = NULL;
	vs.background = NULL;
	vs.bgrect.x = 0;
	vs.bgrect.y = 0;
	image = IMG_Load("src/visu/img/background.jpg");
	if (image == NULL)
		ft_printf("ERROR IMG");
	vs.background = SDL_CreateTextureFromSurface(vs.renderer, image);
	SDL_FreeSurface(image);
	SDL_QueryTexture(vs.background, NULL, NULL, &vs.bgrect.w, &vs.bgrect.h);
	SDL_RenderCopy(vs.renderer, vs.background, NULL, &vs.bgrect);
	//

    // Boucle de creation des rectangles selon le nombre d'arguments
    i =  1;
    SDL_SetRenderDrawColor(vs.renderer, 100, 100, 100, 255);
    SDL_Rect rectangle;
	int	nbroom = lem->nb_room - 2;
    while (nbroom > 0)
    {
        rectangle.x = vs.rooms[i].x;
        rectangle.y = vs.rooms[i].y;
        rectangle.w = ROOM_SIZE;
        rectangle.h = ROOM_SIZE;

        SDL_RenderFillRect(vs.renderer, &rectangle);

        i ++;
		nbroom--;
    }

    //*** Affichage de lignes entre les rooms selon la matrice d'adjacence
	DrawAllLines(lem, vs.renderer, vs.rooms);


	// Affichage des salles Start et End
    SDL_SetRenderDrawColor(vs.renderer, 160, 160, 160, 255);
    vs.startroom.x = vs.rooms[0].x;
    vs.startroom.y = vs.rooms[0].y;
    vs.startroom.w = ROOM_SIZE;
    vs.startroom.h = ROOM_SIZE;
    SDL_RenderFillRect(vs.renderer, &vs.startroom);
	SDL_SetRenderDrawColor(vs.renderer, 45, 45, 45, 255);
    vs.endroom.x = vs.rooms[lem->nb_room - 1].x;
    vs.endroom.y = vs.rooms[lem->nb_room - 1].y;
    vs.endroom.w = ROOM_SIZE;
    vs.endroom.h = ROOM_SIZE;
    SDL_RenderFillRect(vs.renderer, &vs.endroom);
    

	//FOURMISSE
	int antcount = 0;
	vs.ants = (t_ant*)malloc(sizeof(t_ant) * lem->nb_ant);
	SDL_SetRenderDrawColor(vs.renderer, 220, 0, 0, 255);
	while (antcount < lem->nb_ant)
	{
		vs.ants[antcount].pos.h = ROOM_SIZE / 2;
		vs.ants[antcount].pos.w = ROOM_SIZE / 2;
		vs.ants[antcount].pos.x = vs.rooms[0].x + 10;
		vs.ants[antcount].pos.y = vs.rooms[0].y + 10;
		SDL_RenderFillRect(vs.renderer, &vs.ants[antcount].pos);
		antcount++;
	}
	create_ants(&vs, lem);

	// Texte pour les Start et End
	//Start
	SDL_Rect textrect;
	TTF_Font *police = NULL;
	police = TTF_OpenFont("src/visu/FFF_Tusj.ttf", 26);
	SDL_Surface *texte = NULL;
	SDL_Color LightGray = {255, 255, 255, 255};
	texte = TTF_RenderText_Blended(police, "Start", LightGray);
	texte->w = 70;
	SDL_Texture *text = SDL_CreateTextureFromSurface(vs.renderer, texte);
	textrect.x = vs.rooms[0].x - 10;
	textrect.y = vs.rooms[0].y + 50;
	textrect.h = 30;
	textrect.w = 70;
	SDL_RenderCopy(vs.renderer, text, NULL, &textrect);
	// End
	texte = TTF_RenderText_Blended(police, "End", LightGray);
	texte->w = 54;
	text = SDL_CreateTextureFromSurface(vs.renderer, texte);
	SDL_FreeSurface(texte);
	textrect.x = vs.rooms[lem->nb_room - 1].x - 2;
	textrect.y = vs.rooms[lem->nb_room - 1].y + 50;
	textrect.w = 54;
	SDL_RenderCopy(vs.renderer, text, NULL, &textrect);


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
				
				case SDL_MOUSEBUTTONDOWN:
					create_antpath(&vs, lem, &vs.ants[0]);
					create_antpath(&vs, lem, &vs.ants[1]);
					create_antpath(&vs, lem, &vs.ants[2]);
					create_antpath(&vs, lem, &vs.ants[3]);
					create_antpath(&vs, lem, &vs.ants[4]);
					create_antpath(&vs, lem, &vs.ants[5]);
					create_antpath(&vs, lem, &vs.ants[6]);
					create_antpath(&vs, lem, &vs.ants[7]);
					create_antpath(&vs, lem, &vs.ants[8]);
					create_antpath(&vs, lem, &vs.ants[9]);
					create_antpath(&vs, lem, &vs.ants[10]);

					print_all(&vs, lem);
					SDL_RenderCopy(vs.renderer, text, NULL, &textrect);
					break;

				default:
					break;
			}
			SDL_RenderPresent(vs.renderer);
		}
	}


    //  
    // Destroy et termine
    if(NULL != vs.renderer)
        SDL_DestroyRenderer(vs.renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    IMG_Quit();
	TTF_CloseFont(police);
	TTF_Quit();
    SDL_Quit();
}