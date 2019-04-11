#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "animate.h"
#include "collision.h"

SDL_Rect deplacerSouris(SDL_Rect Position_joueur,SDL_Rect Position_curseur){
    int pos,i;
    if((Position_curseur.x > Position_joueur.x )&&(Position_curseur.y < Position_joueur.y)){
        pos=1;
    }
    else if((Position_curseur.x > Position_joueur.x )&&(Position_curseur.y > Position_joueur.y)){
        pos=2;
    }
    else if((Position_curseur.x < Position_joueur.x )&&(Position_curseur.y > Position_joueur.y)){
        pos=3;
    }
    else if((Position_curseur.x < Position_joueur.x )&&(Position_curseur.y < Position_joueur.y)){
        pos=4;
    }

	                       if(pos==1){
                            for(i=0;i<3;i++){
                                Position_joueur.x+=4;
                                Position_joueur.y-=2;
                            }
                       }
                       else if(pos==2){
                            for(i=0;i<3;i++){
                                Position_joueur.x+=4;
                                Position_joueur.y+=2;
                            }
                       }
                       else if(pos==3){
                            for(i=0;i<3;i++){
                                Position_joueur.x-=4;
                                Position_joueur.y+=2;
                            }
                       }
                       else if(pos==4){
                            for(i=0;i<3;i++){
                                Position_joueur.x-=4;
                                Position_joueur.y-=2;
                            }
                       }
	return Position_joueur;
}

SDL_Rect deplacer(SDL_Rect Position_joueur,int pos)
{
	
	if(pos==1)
	{
		Position_joueur.y-=4;
	}
	
	else if(pos==2)

	{
		Position_joueur.y+=4;
	}
	
	else if(pos==3)

	{
		Position_joueur.x-=4;
	}

	else if(pos==4)

	{
		Position_joueur.x+=4;
	}
	return Position_joueur;
}


int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *surface1 = NULL, *surface2 = NULL, *background= NULL;
    SDL_Event event;
    SDL_Rect position1, position2, position3,positionback;
    int continuer = 1;
    SDL_Init(SDL_INIT_VIDEO);
     ecran = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE);
   
    position1.x=500;
    position1.y=200;
    position2.x=600;
    position2.y=0;

perso p;
	initialiser_joueur(&p);
p.image=IMG_Load("joueur.png");
positionback.x = 0;
	positionback.y = 0;
	surface1 = IMG_Load("joueur1.png");
position3.x=900;
position3.y=200;
	background = IMG_Load("nature.jpg");
    SDL_BlitSurface(background, NULL, ecran,&positionback );
    SDL_BlitSurface(surface1, NULL, ecran,&position3 );
    SDL_Flip(ecran);
SDL_EnableKeyRepeat(10,10);
    while(continuer)
    {
        SDL_WaitEvent(&event);
 
        switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;
	    case SDL_KEYDOWN:
		switch(event.key.keysym.sym)
		{
			case SDLK_UP:
			if(!collision(&position1,&position3))
			position1=deplacer(position1,1);
			animate_up(&p);
			break;
			case SDLK_DOWN:
			if(!collision(&position1,&position3))
			position1=deplacer(position1,2);
			animate_down(&p);
			break;
			case SDLK_LEFT:
			if(!collision(&position1,&position3))
			position1=deplacer(position1,3);
			animate_left(&p);
			break;
			case SDLK_RIGHT:
			if(!collision(&position1,&position3))
			position1=deplacer(position1,4);
			animate_right(&p);
			break;
		}
		break;
	    case SDL_MOUSEBUTTONDOWN:
		position2.x=event.button.x;
		position2.y=event.button.y;
		position1=deplacerSouris(position1,position2);
	    break;
        }
	SDL_BlitSurface(background, NULL, ecran,&positionback );
	SDL_BlitSurface(surface1, NULL, ecran,&position3 );
	Display_perso (p,position1,ecran);
    }
    SDL_Quit();
    SDL_FreeSurface(surface1);
    SDL_FreeSurface(surface2);
    SDL_FreeSurface(background);
    return EXIT_SUCCESS;
}
