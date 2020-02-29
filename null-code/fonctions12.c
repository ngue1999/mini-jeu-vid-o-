#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
        }
    }
}

void affiche()
{
    SDL_Surface *screen = NULL;
    SDL_Surface *text1 = NULL;
    SDL_Rect text1_pos;
    TTF_Font *fonts = NULL;
    fonts = TTF_OpenFont("Roboto-Regular.ttf", 172);
    SDL_Color fontBlack = {250, 0, 0};
    text1 = TTF_RenderText_Blended(fonts, "hello world", fontBlack);

    text1_pos.x = 50;
    text1_pos.y = 50;

    SDL_BlitSurface(text1, NULL, screen, &text1_pos);
    SDL_FreeSurface(text1);
    SDL_Flip(screen);

    TTF_CloseFont(fonts);
}

void menu()
{

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_Surface *screen = NULL;

    screen = SDL_SetVideoMode(1082, 730, 32, SDL_HWSURFACE);
    if (screen == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetCaption("Ma super fenêtre SDL !", NULL);
    SDL_Surface *text1 = NULL;
    SDL_Rect text1_pos;
    TTF_Font *fonts = NULL;
    fonts = TTF_OpenFont("Roboto-Regular.ttf", 172);
    SDL_Color fontBlack = {250, 0, 0};
    text1 = TTF_RenderText_Blended(fonts, "hello world", fontBlack);

    text1_pos.x = 50;
    text1_pos.y = 50;

    SDL_BlitSurface(text1, NULL, screen, &text1_pos);
    SDL_FreeSurface(text1);
    SDL_Flip(screen);

    TTF_CloseFont(fonts);

    // fin de la zone de texte
    pause();
    SDL_Flip(screen);
    SDL_Quit();
}

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *texte = NULL, *fond = NULL;
    SDL_Rect position;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);

    fond = IMG_Load("moraira.jpg");

    /* Chargement de la police */
    SDL_Surface *texte = NULL;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    SDL_Rect position;
    police = TTF_OpenFont("angelina.ttf", 65);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "Salut les Zér0s !", couleurNoire);
    position.x = 60;
    position.y = 370;
    SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        position.x = 0;
        position.y = 0;
        SDL_BlitSurface(fond, NULL, ecran, &position); /* Blit du fond */

        position.x = 60;
        position.y = 370;
        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */
        SDL_Flip(ecran);
    }

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);
    SDL_Quit();

    return EXIT_SUCCESS;
}