#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>

void zoom(int *tempsActuel,int *tempsPrecedent,SDL_Surface *ecran,double *angle,SDL_Surface *image,SDL_Surface *rotation,SDL_Rect rect,int TEMPS){
*tempsActuel = SDL_GetTicks();
        if ((*tempsActuel) - (*tempsPrecedent) > TEMPS)
        {
            *angle += 3; //On augmente l'angle pour que l'image tourne sur elle-même.
 
            *tempsPrecedent = *tempsActuel;
        }
        else
        {
            SDL_Delay(TEMPS - ((*tempsActuel) - (*tempsPrecedent)));
        }
 
 
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
 
        rotation = rotozoomSurface(image, (*angle), 0.5, 1); //On transforme la surface image.
 
        SDL_BlitSurface(rotation , NULL, ecran, &rect); //On affiche la rotation de la surface image.
        SDL_FreeSurface(rotation); //On efface la surface rotation car on va la redéfinir dans la prochaine boucle. Si on ne le fait pas, cela crée une fuite de mémoire. 
 
        SDL_Flip(ecran);}
