#include"enemy.h"
#include<stdlib.h>
#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"




int main(int argc, char *argv[])
{
    SDL_Surface *screen=NULL,*ecran = NULL, *imageDeFond = NULL,*image1 = NULL,*image2 = NULL,*image3 = NULL,*menu=NULL,*newgame=NULL,*option=NULL;
    SDL_Rect positionFond,pos1,pos2,pos3;
    int continuer=1,compteur=0,tempsPrecedent = 0, tempsActuel = 0;
    SDL_Event event;
	
enemy enemy;
    positionFond.x = 0;
    positionFond.y = 0;
    pos1.x=00;
    pos1.y=0;
    pos2.x=00;
    pos2.y=0;
    pos3.x=0;
    pos3.y=0;

    SDL_Init(SDL_INIT_VIDEO);
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
Mix_Music *musique;
//Mix_Chunk *bref=Mix_LoadWAV("bref.mp3");
musique=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(musique, 1);
    /* Chargement de l'icône AVANT SDL_SetVideoMode */
    //SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL);

    ecran = SDL_SetVideoMode(1024, 768, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("MENU TEST", NULL);

    imageDeFond = IMG_Load("fond.png");
    image1 = IMG_Load("ne.png");
    image2 = IMG_Load("op.png");
    image3 = IMG_Load("ex.png");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    SDL_Flip(ecran);
while (continuer)
{
    SDL_PollEvent(&event);
    switch(event.type)
{
    case SDL_QUIT:
        continuer = 0;
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
            case SDLK_UP: // Flèche haut
                if(compteur==0)
		{
		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
		SDL_BlitSurface(image3, NULL, ecran, &pos3);
		compteur=3;
SDL_Flip(ecran);
		}
		else if(compteur==3)
		{
		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
		SDL_BlitSurface(image2, NULL, ecran, &pos2);
		compteur--;
SDL_Flip(ecran);
		}
		else if(compteur==2)
		{
		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
		SDL_BlitSurface(image1, NULL, ecran, &pos1);
		compteur--;
SDL_Flip(ecran);
		}
                break;
            case SDLK_DOWN: // Flèche bas
                if(compteur==0)
		{
		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
		SDL_BlitSurface(image1, NULL, ecran, &pos1);
		compteur++;
SDL_Flip(ecran);
		}
		else if(compteur==1)
		{
		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
		SDL_BlitSurface(image2, NULL, ecran, &pos2);
		compteur++;
SDL_Flip(ecran);
		}
		else if(compteur==2)
		{
		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
		SDL_BlitSurface(image3, NULL, ecran, &pos3);
		compteur++;
SDL_Flip(ecran);
		}
                break;
          		
        }
        break;
    case SDL_MOUSEMOTION:
		if(event.motion.x < 661 && event.motion.x > 165 && event.motion.y < 359 && event.motion.y > 257)
		{
		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
		SDL_BlitSurface(image1, NULL, ecran, &pos1);
SDL_Flip(ecran);
		}
		else if(event.motion.x < 661 && event.motion.x > 165 && event.motion.y < 458 && event.motion.y > 356)
		{
		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
		SDL_BlitSurface(image2, NULL, ecran, &pos2);
SDL_Flip(ecran);
		}
		else if(event.motion.x < 661 && event.motion.x > 165 && event.motion.y < 541 && event.motion.y > 439)
		{
		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
		SDL_BlitSurface(image3, NULL, ecran, &pos3);
SDL_Flip(ecran);
		}
            break;
case SDL_MOUSEBUTTONDOWN: 
if(event.button.button==SDL_BUTTON_LEFT)
{
if(event.motion.x < 661 && event.motion.x > 165 && event.motion.y < 541 && event.motion.y > 439)
		{
		continuer=0;
		}
if(event.motion.x < 661 && event.motion.x > 165 && event.motion.y < 359 && event.motion.y > 257)
{
newgame = IMG_Load("foret.png");
SDL_FillRect(ecran,NULL, SDL_MapRGB(ecran->format,255,255,255));
SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
SDL_BlitSurface(image1,NULL,ecran,&pos1);
SDL_BlitSurface(image2,NULL,ecran,&pos2);
SDL_BlitSurface(image3,NULL,ecran,&pos3);
SDL_Flip(ecran);


jeu();

}
else if(event.motion.x < 661 && event.motion.x > 165 && event.motion.y < 458 && event.motion.y > 356)
{
option= IMG_Load("singe.png");
SDL_FillRect(ecran,NULL, SDL_MapRGB(ecran->format,255,255,255));
SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
SDL_BlitSurface(image1,NULL,ecran,&pos1);
SDL_BlitSurface(image2,NULL,ecran,&pos2);
SDL_BlitSurface(image3,NULL,ecran,&pos3);
SDL_Flip(ecran);


}
break;

}





    SDL_FreeSurface(imageDeFond);
    Mix_FreeMusic(musique);
    Mix_CloseAudio();
    SDL_Quit();

    return EXIT_SUCCESS;
}
}
}
void jeu()
{
	
	//declaration de la variable SDL_surface
	SDL_Surface *screen=NULL;
	SDL_Surface *image=NULL;
	SDL_Surface *perso=NULL;
	SDL_Rect positionecran;
	SDL_Rect positionperso;
	SDL_Event event;
	char pause;
	int done=1;
int k=1 ;
	//initialiser SDL video
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	//creer une nouvelle fenetre
	screen = SDL_SetVideoMode(1000, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	if(!screen)
	{
	printf("Unable to set 1000x800 videos: %s\n", SDL_GetError());
	///return (-1);
	}
	SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 255, 255, 255));
	image = SDL_LoadBMP("background.bmp");
	if(image==NULL)
	{
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		//return 1;
	}
	positionecran.x=0;
	positionecran.y=0;
	
	SDL_BlitSurface(image, NULL, screen, &positionecran);
	perso = IMG_Load("singe.png");
	if(perso==NULL)
	{
		printf("Unable to load the image: %s\n", SDL_GetError());
	//	return 1;
	}
	SDL_SetColorKey(perso, SDL_SRCCOLORKEY, SDL_MapRGB(perso->format, 0, 0, 255));
	positionperso.x=0;
	positionperso.y=0;
	SDL_BlitSurface(perso, NULL, screen, &positionperso);
//	SDL_SetColorkey(perso, SDL_SRCCOLORKEY, SDL_MapRGB(perso->format, 50, 100, 255));
	//nom de ma fenetre
	SDL_WM_SetCaption("Mon premier jeux", NULL);
	if(!screen)
	{
		printf("Unable to set 600*400 video: %s\n", SDL_GetError());
		//return -1;
	}
//musiue***********************************
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
	{
		printf("%s", Mix_GetError());
	}
	Mix_Music * music;
	music = Mix_LoadMUS("music.mp3");//chargement de misic.mp3

	//jouer la musique
	Mix_PlayMusic(music, -1); //jouer infinementla musique
	
//	Mix_FreeMusic(music); liberation de la musique

//evennement ********************************************
while(done)
{
	SDL_BlitSurface(image ,NULL,screen,&positionecran);
		SDL_Flip(screen);

	/*SDL_PollEvent(&event);
	
		switch(event.type)
		{
			//quitter si la fenetre est fermée
			case SDL_QUIT:
			done = 0;
			break;
			//clique pour verifier
			case SDL_KEYDOWN:
			{
//				Mix_PlayChannel(-1, sound, 0);
				//sortie si espce est apuyer
				switch(event.key.keysym.sym)
				{
					case SDLK_UP:
					positionperso.y--;
					break;
					case SDLK_DOWN:
					positionperso.y++;
					break;
					case SDLK_RIGHT:
					positionperso.x++;
					break;
					case SDLK_LEFT:
					positionperso.x--;
					break;
				}
			break;
			}
		}*/
k= rand()%100+1;
                   if((k>=1)&&(k<60)){
         positionperso.x++; 
  

}
  if((k>60)&&(k<70)){
          positionperso.x++; 
      

}
 if((k>70)&&(k<80)){
       positionperso.y++ ;
      

}
if((k>80)&&(k<101)){
       positionperso.y-- ;
      

}                 
		//on efface l'écran
		SDL_BlitSurface(image, NULL, screen, &positionecran);
		//on place le personnage dans sa nouvelle position
		SDL_BlitSurface(perso, NULL, screen, &positionperso);
		//on met a jour l'aicharge de l'écran
		SDL_Flip(screen);

}
	/*couleur de la fenetre*/
//	SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 30, 15, 220));
/*	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
	{
		printf("%s", Mix_GetError());
	}
	Mix_Music * music;
	Mix_Chunk * sound;

	music = Mix_LoadMUS("music.mp3");
	assert(music);

	sound = Mix_LoadWAV("detruit.wav");
	assert(sound);
	//jouer la musique
	Mix_PlayMusic(music, -1);

*/
	Mix_FreeMusic(music); //liberation de la musique
	SDL_Flip(screen);
	SDL_FreeSurface(image);
	///pause=getchar();
	SDL_Quit();
}



