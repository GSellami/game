#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <stdbool.h>
#include "perso.h"

void sauvegarder( perso p,SDL_Rect position,SDL_Rect col)
{
    FILE* save=fopen("game_save","w");

    
     if (save != NULL) {
       fprintf(save,"%d ",p.vi);
	fprintf(save,"%d ",position.x);
	fprintf(save,"%d ",position.y);
	fprintf(save,"%d ",col.x);
	fprintf(save,"%d ",col.y);
    }
    else {
	printf("ERREUR");
        
    }

    //On quitte SDL
    fclose(save);
}

bool load_files( perso *p,SDL_Rect *position,SDL_Rect *col)
{

    FILE* load=fopen("game_save","r");
	int a,b,c,d,e;
	//Si le fichier est charge
	if (load != NULL){
	fscanf(load,"%d %d %d %d %d", &(a), &(b), &(c), &(d), &(e));
	p->vi=a;
	position->x=b;
	position->y=c;
	col->x=d;
	col->y=e;
	}
    	else
{
return false;
}
fclose(load);
    //Si tout s'est bien passé
    return true;
}
