#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *surface1 = NULL, *surface2 = NULL, *background= NULL,*question=NULL;
    SDL_Event event;
    SDL_Rect position1, position2, positionQ,positionback,camera1,camera2;
    int continuer = 1;
    char texte[100]="appuyer sur s pour sauvegarder et sur q pour quitter";
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    TTF_Font *police = NULL;
     SDL_Color noire={100,0,0};
    police = TTF_OpenFont("de.ttf",20);
	SDL_Color blanc={255,255,255};
     ecran = SDL_SetVideoMode(1000, 600, 32, SDL_HWSURFACE);
   
    position1.x=0;
    position1.y=0;
    positionQ.x=345;
    positionQ.y=280;
positionback.x = 0;
	positionback.y = 0;
	surface1 = IMG_Load("nature.jpg");
position2.x=335;
position2.y=200;
	background = IMG_Load("joueur1.png");
    question = TTF_RenderText_Blended(police,texte,blanc);
    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    SDL_SetAlpha(surface1,SDL_SRCALPHA, 128);
    SDL_BlitSurface(surface1, NULL, ecran,&positionback );
    SDL_BlitSurface(surface1, &camera1, ecran, &positionback );
    surface2 = SDL_CreateRGBSurface(SDL_HWSURFACE, 470, 180, 32, 0, 0, 0, 0);
    SDL_BlitSurface(surface2, NULL, ecran,&position2 );
    SDL_BlitSurface(question, NULL, ecran, &positionQ );
    SDL_Flip(ecran);

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
			case SDLK_s:
			//sauvegarder(&p);
			break;
			case SDLK_q:
			continuer=0;
			break;
		}
	    break;
        }
    }
    SDL_Quit();
    SDL_FreeSurface(surface1);
    SDL_FreeSurface(surface2);
    SDL_FreeSurface(background);
    return EXIT_SUCCESS;
}
