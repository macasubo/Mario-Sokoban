#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "mario.h"
#include "errors_handling.h"

int					main(int argc, char *argv[])
{
	Objlist 		**list;
	SDL_Window 		*win;
	SDL_Surface 	*screen;
	SDL_Surface 	*mario;
	SDL_Surface 	*objectif;
	SDL_Rect		position;

	list = (Objlist **)malloc(sizeof(Objlist*));
	win = NULL;
	screen = NULL;

	init(&win, &screen);


	position.x = 50;
	position.y = 50;
	(mario = IMG_Load("img/mario_bas.gif")) == NULL ? freeSDL(list, win) : pushObject(list, mario);
	SDL_BlitSurface(mario, NULL, screen, &position);

	(objectif = IMG_Load("img/objectif.bmp")) == NULL ? freeSDL(list, win) : pushObject(list, objectif);
	SDL_BlitSurface(objectif, NULL, screen, &position);

	if (SDL_UpdateWindowSurface(win) != 0)
		freeSDL(list, win);

	SDL_Delay(5000);

	return (EXIT_SUCCESS);
}

void				init(SDL_Window **win, SDL_Surface **screen)
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		fprintf(stderr, "SDL_Init Error : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	*win = SDL_CreateWindow("Mario Sokoban", 100, 100, 34*12, 34*12, SDL_WINDOW_SHOWN);
	if (*win == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error : %s\n", SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}
	*screen = SDL_GetWindowSurface(*win);
	if (*screen == NULL)
	{
		fprintf(stderr, "SDL_GetWindowSurface Error : %s\n", SDL_GetError());
		SDL_DestroyWindow(*win);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}
}