#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"

void boucle_jeu()
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
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer = 0;
                break;
            case SDLK_RIGHT:
                continuer = 0;
                break;
            }
            break;
        }
    }
}

void display_submenu()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    if (TTF_Init() == -1)
    {
        printf("error\n");
    }
    SDL_Surface *screen1 = NULL;

    screen1 = SDL_SetVideoMode(1285, 723, 32, SDL_HWSURFACE);

    if (screen1 == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("submenu 1", NULL);

    SDL_Surface *bckg1 = NULL;
    SDL_Rect bckgPosition1;

    bckgPosition1.x = 0;
    bckgPosition1.y = 0;
    bckg1 = IMG_Load("images/back-jeu.png");
    SDL_BlitSurface(bckg1, NULL, screen1, &bckgPosition1);

    SDL_Flip(screen1);
}

void menu_jeu()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    //fenêtre principale

    SDL_Surface *screen = NULL;
    SDL_Surface *menu_items[3];
    menu_items[0] = IMG_Load("image2/play-btn-orange.png");
    menu_items[1] = IMG_Load("image2/setting-btn-orange.png");
    menu_items[2] = IMG_Load("image2/exit-btn-orange.png");

    screen = SDL_SetVideoMode(1285, 723, 32, SDL_HWSURFACE);

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }
    Mix_Music *music;
    music = Mix_LoadMUS("Katekyo Hitman RebornTsuna Awakens OST.mp3");
    Mix_PlayMusic(music, -1);
    if (screen == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        printf("erreur \n");
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetCaption("Menu", NULL); //rename window
    //background
    SDL_Surface *bckg = NULL;
    SDL_Rect bckgPosition;

    bckgPosition.x = 0;
    bckgPosition.y = 0;
    bckg = IMG_Load("image2/background2.jpg");
    SDL_BlitSurface(bckg, NULL, screen, &bckgPosition);

    SDL_Flip(screen);

    //bouton continue

    SDL_Surface *continueBtn = NULL;
    SDL_Rect continueBtnPositon;
    continueBtnPositon.x = 450;
    continueBtnPositon.y = 100;
    continueBtn = menu_items[0];
    SDL_BlitSurface(continueBtn, NULL, screen, &continueBtnPositon);
    SDL_FreeSurface(continueBtn);
    SDL_Flip(screen);

    //bouton settings
    SDL_Surface *settingBtn = NULL;
    SDL_Rect settingBtnPositon;
    settingBtnPositon.x = 450;
    settingBtnPositon.y = 200;
    settingBtn = IMG_Load("image2/setting-btn-orange.png");
    SDL_BlitSurface(settingBtn, NULL, screen, &settingBtnPositon);
    SDL_FreeSurface(settingBtn);
    SDL_Flip(screen);

    //bouton exit
    SDL_Surface *exitBtn = NULL;
    SDL_Rect exitBtnPositon;
    exitBtnPositon.x = 450;
    exitBtnPositon.y = 300;
    exitBtn = menu_items[1];
    SDL_BlitSurface(exitBtn, NULL, screen, &exitBtnPositon);
    SDL_FreeSurface(exitBtn);
    SDL_Flip(screen);

    //personnage initialisation

    SDL_Surface *pers = NULL;
    SDL_Rect pacmanPositon, pos[1];
    pos[0].x = 20;
    pos[0].y = 20;
    pacmanPositon.x = 20;
    pacmanPositon.y = 20;
    pers = menu_items[2];
    SDL_BlitSurface(pers, NULL, screen, &pacmanPositon);

    SDL_Flip(screen);

    //time management
    SDL_Surface *text1 = NULL;
    SDL_Rect text1_pos;
    TTF_Font *fonts = NULL;
    fonts = TTF_OpenFont("fonts/Roboto-Regular.ttf", 172);
    SDL_Color fontBlack = {250, 0, 0};
    text1 = TTF_RenderText_Blended(fonts, "hello world", fontBlack);

    text1_pos.x = 50;
    text1_pos.y = 50;

    SDL_BlitSurface(text1, NULL, screen, &text1_pos);
    SDL_FreeSurface(text1);
    SDL_Flip(screen);

    // SDL_Surface *text1 = NULL;
    // SDL_Rect text1_pos;
    // TTF_Font *fonts = NULL;
    // fonts = TTF_OpenFont("fonts/Roboto-Regular.ttf", 22);
    // if (fonts == NULL)
    // {
    //     printf("erreur \n");
    // }
    // SDL_Color fontBlack = {250, 0, 0};
    // text1 = TTF_RenderText_Solid(fonts, "hello world", fontBlack);
    // if (text1 == NULL)
    // {
    //     printf("erreur \n");
    // }
    // text1_pos.x = 200;
    // text1_pos.y = 50;

    // SDL_BlitSurface(text1, NULL, screen, &text1_pos);
    // SDL_Flip(screen);

    //game play
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer = 0;
                break;
            case SDLK_RIGHT:
                pacmanPositon.x += 50;

                break;
            case SDLK_LEFT:
                pacmanPositon.x -= 50;
                break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            switch (event.button.button)
            {
            case SDL_BUTTON_LEFT:
                // display_submenu();

                break;
            }

            break;
        case SDL_MOUSEMOTION:

            //if (event.type == SDL_MOUSEBUTTONDOWN)
            //{
            if (((event.motion.x >= 450) && (event.motion.x <= 568)) && ((event.motion.y <= 159) && (event.motion.y >= 100)))
                display_submenu();
            if (((event.motion.x >= 450) && (event.motion.x <= 568)) && ((event.motion.y <= 159) && (event.motion.y >= 100)))
                display_submenu();
            else if (((event.motion.x >= 450) && (event.motion.x <= 568)) && ((event.motion.y <= 259) && (event.motion.y >= 200)))
                display_submenu();
            else if (((event.motion.x >= 450) && (event.motion.x <= 568)) && ((event.motion.y <= 359) && (event.motion.y >= 300)))
                continuer = 0;
            //printf("je suis dedans");
            //}
            //printf("je suis dehors");
        }
    }
    // boucle_jeu();
    // fprintf(stdout, "%d", SDL_GetTicks());

    SDL_FreeSurface(bckg);
    SDL_FreeSurface(pers);
    SDL_FreeSurface(screen);
    SDL_FreeSurface(text1);
    Mix_FreeMusic(music);
    TTF_CloseFont(fonts);
    SDL_Flip(screen);
    TTF_Quit();
    SDL_Quit();
}

//refresh screen
// SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 255, 255));
// SDL_BlitSurface(bckg, NULL, screen, &bckgPosition);
// SDL_BlitSurface(pers, NULL, screen, &pacmanPositon);
// SDL_Flip(screen);