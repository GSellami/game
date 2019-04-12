#include "enemy.h"
#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"

void initialisation_enemy(char *image[],char *image1[],int x,int y)
{
SDL_Surface* screen = NULL;
enemy enemy;
SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);
screen = SDL_SetVideoMode(W_Screen, H_Screen, CMode, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_HWPALETTE /*| SDL_FULLSCREEN */| SDL_RESIZABLE /*| SDL_NOFRAME*/);
enemy.spriteleft = IMG_Load("singe.png");
enemy.spriteright = IMG_Load("singe.png");
enemy.dst.x = 0;
enemy.dst.y = 0;

}
void afficher_enemy(SDL_Surface *screen,enemy enemy)
{
SDL_Surface* backg = NULL;
backg = IMG_Load("fond.png");
SDL_BlitSurface(backg, NULL, screen, NULL);
SDL_Flip(screen);

SDL_ShowCursor(SDL_DISABLE); /*hide cursor*/

	int carryon = 1;
	while(carryon)
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		int i;

		for(i = 0; i<MAX_FRAMES; i++)
		{
			enemy.frame.x = i*(Sint16)SPRITE_W;
			enemy.frame.y = 0;
			enemy.frame.w = SPRITE_W;
			enemy.frame.h = SPRITE_H;
			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(enemy.spriteright, &enemy.frame, screen, &enemy.dst);
			SDL_Flip(screen);
			SDL_Delay(500);
		}
		for(i = (MAX_FRAMES - 1); i>=0; i--)
		{
			enemy.frame.x = i*(Sint16)SPRITE_W;
			enemy.frame.y = 0;
			enemy.frame.w = SPRITE_W;
			enemy.frame.h = SPRITE_H;
			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(enemy.spriteleft, &enemy.frame, screen, &enemy.dst);
			SDL_Flip(screen);
			SDL_Delay(500);
		}

		switch(event.type)
		{
			case SDL_KEYDOWN:
			    if(event.key.keysym.sym == SDLK_ESCAPE)
			    {
			    	carryon = 0;
			    }
		}

	}
	SDL_Quit();
 

}

