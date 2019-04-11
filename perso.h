
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct
{

    char key[SDLK_LAST];

} Input;


typedef struct
{
	SDL_Surface* image;
	SDL_Rect frame;
	SDL_Rect position;
	int vi;
	int coins;
	int HP;
} perso;




