/**
 * @file fonctions.c
 * @author the hunt teams(ngueemmanuel.prof@gmail.com)
 * @brief the next functions display menu, submenu and firstage
 * @version 0.1
 * @date 2020-02-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"

/**
 * @brief working in firstage function
 * 
 * @param stage1 
 */
void first_stage(SDL_Surface *stage1)
{ /**
 * @brief permet l'afichage du premier state
 * 
 */
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
        printf("error\n");
    }
    Mix_Music *bckmusic[3];
    for (int i = 0; i < 3; i++)
        bckmusic[i] = NULL;
    bckmusic[0] = Mix_LoadMUS("son/kafon.mp3");
    bckmusic[1] = Mix_LoadMUS("son/niska.mp3");
    bckmusic[2] = Mix_LoadMUS("son/kafon.mp3");

    SDL_Surface *stage1_items[2];

    for (int i = 0; i < 2; i++)
        stage1_items[i] = NULL; //iniatialisation of surface tha we will use
    /**
     * @brief load image we will use in the first stage
     * 
     */
    stage1_items[0] = IMG_Load("stage1-images/background.png"); /*!< main menu function*/
    stage1_items[1] = IMG_Load("stage1-images/detective.png");

    stage1 = SDL_SetVideoMode(1285, 723, 32, SDL_HWSURFACE | SDL_RESIZABLE);
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
        printf("error\n");
    }
    SDL_WM_SetCaption("Menu", NULL);

    SDL_Rect pos_stage1[2];

    //initiallisation of background, positionate and all the bliting background
    pos_stage1[0].x = 0;
    pos_stage1[0].y = 0;
    SDL_BlitSurface(stage1_items[0], NULL, stage1, &pos_stage1[0]);
    SDL_Flip(stage1);

    //displaying character
    pos_stage1[1].x = 0;
    pos_stage1[1].y = 200;
    SDL_BlitSurface(stage1_items[1], NULL, stage1, &pos_stage1[1]);
    SDL_Flip(stage1);

    int continuer = 1;
    SDL_Event event;
    int x, y, count1 = -1, count2 = 3;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            SDL_EnableKeyRepeat(1000, 1000);
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                /**
                 * @brief déplacement du personnage vers la droite
                 * 
                 */
                pos_stage1[1].x += 50;
                SDL_BlitSurface(stage1_items[0], NULL, stage1, &pos_stage1[0]);
                SDL_BlitSurface(stage1_items[1], NULL, stage1, &pos_stage1[1]);
                SDL_Flip(stage1);
                break;
            case SDLK_LEFT:
                /**
                 * @brief déplacement du personnage vers la gauche
                 * 
                 */
                pos_stage1[1].x -= 50;
                SDL_BlitSurface(stage1_items[0], NULL, stage1, &pos_stage1[0]);
                SDL_BlitSurface(stage1_items[1], NULL, stage1, &pos_stage1[1]);
                SDL_Flip(stage1);
                break;
            }
            break;
        }
    }

    SDL_Flip(stage1);
    for (int i = 0; i < 2; i++)
        SDL_FreeSurface(stage1_items[i]); /**
         * @brief suppression des surface déclarer personnage et background
         * 
         */
    SDL_FreeSurface(stage1);
    printf("error\n");
}

/**
 * @brief cette fonction permet la l'affichage du sous menu about
 * 
 * @param about_submenu 
 */
void display_about(SDL_Surface *about_submenu)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
        printf("error\n");
    }
    Mix_Music *bckmusic[3];
    for (int i = 0; i < 3; i++)
        bckmusic[i] = NULL;
    bckmusic[0] = Mix_LoadMUS("son/kafon.mp3");
    bckmusic[1] = Mix_LoadMUS("son/niska.mp3");
    bckmusic[2] = Mix_LoadMUS("son/kafon.mp3");

    Mix_PlayMusic(bckmusic[0], -1);

    SDL_Surface *menu_items[6];
    for (int i = 0; i < 6; i++)
        menu_items[i] = NULL;
    /**
     * @brief je charge toute les images qui interviendrons dans le sous menu about dans le tableau menu_itens
     * 
     */
    menu_items[0] = IMG_Load("fly12/multi-1.png");
    menu_items[1] = IMG_Load("fly12/load-1.png");
    menu_items[2] = IMG_Load("fly12/new-game-1.png");
    menu_items[3] = IMG_Load("fly12/new-game-1.png");
    menu_items[4] = IMG_Load("fly12/new-game-1.png");
    menu_items[5] = IMG_Load("fly12/new-game-1.png");
    SDL_Rect pos[5];

    about_submenu = SDL_SetVideoMode(1285, 723, 32, SDL_HWSURFACE | SDL_RESIZABLE);
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
        printf("error\n");
    }
    SDL_WM_SetCaption("Menu", NULL);

    SDL_FillRect(about_submenu, NULL, SDL_MapRGBA(about_submenu->format, 15, 24, 32, 0.92));
    SDL_Flip(about_submenu);

    SDL_Surface *text1 = NULL, *txt = NULL;
    SDL_Rect text1_pos, txt_pos;
    TTF_Font *fonts, *ft;
    char phrase[300] = "DISCOVERY", phrse[300] = "هل تريد أن تعيش حياتك";
    fonts = TTF_OpenFont("font/Roboto-Regular.otf", 102); /**per de charger la police roboto-regular*/
    ft = TTF_OpenFont("font/arabe.ttf", 60);

    SDL_Color fontBlack = {242, 242, 242}, color2 = {166, 3, 3};

    /**
     * @brief initialisation du texte 
     * 
     */
    text1 = TTF_RenderText_Blended(fonts, phrase, fontBlack);
    txt = TTF_RenderText_Blended(ft, phrse, color2);
    text1_pos.x = about_submenu->clip_rect.w / 2 - menu_items[5]->clip_rect.w / 2 - 200;
    text1_pos.y = about_submenu->clip_rect.h / 2 - menu_items[5]->clip_rect.h / 2;
    SDL_BlitSurface(text1, NULL, about_submenu, &text1_pos);
    SDL_Flip(about_submenu);

    txt_pos.x = about_submenu->clip_rect.w / 2 - menu_items[5]->clip_rect.w / 2 - 500;
    txt_pos.y = about_submenu->clip_rect.h / 2 - menu_items[5]->clip_rect.h / 2;

    int continuer = 1;
    SDL_Event event;
    int x, y, count1 = -1, count2 = 3;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEMOTION:
            x = event.motion.x;
            y = event.motion.y;
            if (x >= text1_pos.x && x <= text1_pos.x + text1_pos.w && y >= text1_pos.y && y <= text1_pos.y + text1_pos.h)
            {
                SDL_FillRect(about_submenu, NULL, SDL_MapRGBA(about_submenu->format, 15, 24, 32, 0.92));
                SDL_BlitSurface(txt, NULL, about_submenu, &txt_pos);
                SDL_Flip(about_submenu);
            }
            break;
        }
    }
    for (int i = 0; i < 5; i++)
        SDL_FreeSurface(menu_items[i]);
    for (int i = 0; i < 3; i++)
        Mix_FreeMusic(bckmusic[i]);

    SDL_FreeSurface(about_submenu);
    SDL_FreeSurface(text1);
    SDL_Flip(about_submenu);
}

/**
 * @brief this fonction display settings submenu
 * 
 * @param settings 
 */
void display_settings(SDL_Surface *settings)
{

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
        printf("error\n");
    }
    Mix_Music *bckmusic[2];
    for (int i = 0; i < 2; i++)
        bckmusic[i] = NULL;
    bckmusic[0] = Mix_LoadMUS("son/interstellar.mp3");
    bckmusic[1] = Mix_LoadMUS("son/bouton.wav");

    Mix_PlayMusic(bckmusic[0], -1);

    SDL_Surface *menu_items[8];
    for (int i = 0; i < 8; i++)
        menu_items[i] = NULL;
    menu_items[0] = IMG_Load("fly12/multi-1.png");
    menu_items[1] = IMG_Load("fly12/load-1.png");
    //menu_items[2] = IMG_Load("fly12/new-game-2.png");
    menu_items[3] = IMG_Load("fly12/load-2.png");
    menu_items[4] = IMG_Load("fly12/load-2.png");
    menu_items[5] = IMG_Load("btn/nom.png");
    menu_items[6] = IMG_Load("fly12/b3.jpg");
    menu_items[7] = IMG_Load("fly12/multi-2.png");
    SDL_Rect pos[5],
        settings_pos;

    settings = SDL_SetVideoMode(1285, 723, 32, SDL_HWSURFACE | SDL_RESIZABLE);
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
        printf("error\n");
    }
    SDL_WM_SetCaption("Menu", NULL);

    settings_pos.x = 0;
    settings_pos.y = 0;
    SDL_BlitSurface(menu_items[6], NULL, settings, &settings_pos);

    //displaying start btn
    pos[0].x = settings->clip_rect.w / 2 - menu_items[0]->clip_rect.w / 2 + 450;
    pos[0].y = settings->clip_rect.h / 2 - menu_items[0]->clip_rect.h / 2 + 100;
    SDL_BlitSurface(menu_items[0], NULL, settings, &pos[0]);
    SDL_Flip(settings);

    //displaying  settings btn
    pos[1].x = settings->clip_rect.w / 2 - menu_items[1]->clip_rect.w / 2 + 500;
    pos[1].y = settings->clip_rect.h / 2 - menu_items[1]->clip_rect.h / 2 + 200;
    SDL_BlitSurface(menu_items[1], NULL, settings, &pos[1]);
    SDL_Flip(settings);

    int continuer = 1, x, y;
    SDL_Event event;
    int i = 0, count1 = -1;
    Mix_Chunk *son = NULL;
    son = Mix_LoadWAV("son/bouton.wav");
    SDL_Surface *screen2 = NULL;
    while (continuer)
    {
        /**
         * @brief Construct a new sdl waitevent object that help us to listen user event and active relative result
         * 
         */
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            SDL_EnableKeyRepeat(1000, 1000);
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer = 0;
                break;
            case SDLK_DOWN:
                count1++;
                if (count1 > 1)
                {
                    count1 = 0;
                }
                switch (count1)
                {
                case 0:
                    SDL_BlitSurface(menu_items[6], NULL, settings, &settings_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[7], NULL, settings, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, settings, &pos[1]);
                    SDL_Flip(settings);
                    break;
                case 1:
                    SDL_BlitSurface(menu_items[6], NULL, settings, &settings_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, settings, &pos[0]);
                    SDL_BlitSurface(menu_items[3], NULL, settings, &pos[1]);
                    SDL_Flip(settings);
                    break;
                }
                break;
            case SDLK_UP:
                count1--;
                if (count1 <= -1)
                {
                    count1 = 1;
                }
                switch (count1)
                {
                case 0:
                    SDL_BlitSurface(menu_items[6], NULL, settings, &settings_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[7], NULL, settings, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, settings, &pos[1]);
                    SDL_Flip(settings);
                    break;
                }
                break;
            case 1:
                SDL_BlitSurface(menu_items[6], NULL, settings, &settings_pos);
                Mix_PlayChannel(1, son, 0);
                SDL_BlitSurface(menu_items[0], NULL, settings, &pos[0]);
                SDL_BlitSurface(menu_items[3], NULL, settings, &pos[1]);
                SDL_Flip(settings);
                break;
            }
            break;
        case SDL_MOUSEMOTION:
            x = event.motion.x;
            y = event.motion.y;
            if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
            {
                switch (i)
                {
                case 0:
                    SDL_BlitSurface(menu_items[6], NULL, settings, &settings_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[7], NULL, settings, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, settings, &pos[1]);
                    SDL_Flip(settings);

                    break;

                case 1:
                    SDL_BlitSurface(menu_items[6], NULL, settings, &settings_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, settings, &pos[0]);
                    SDL_BlitSurface(menu_items[3], NULL, settings, &pos[1]);
                    SDL_Flip(settings);
                    break;
                }
            }
            int bool = -1;
            for (int j = 0; j < 4; j++)
            {

                if (x >= pos[j].x && x <= pos[j].x + pos[j].w && y >= pos[j].y && y <= pos[j].y + pos[j].h)
                {
                    bool = 1;
                }
            }
            if (bool == -1)
            {
                SDL_BlitSurface(menu_items[6], NULL, settings, &settings_pos);
                SDL_BlitSurface(menu_items[0], NULL, settings, &pos[0]);
                SDL_BlitSurface(menu_items[1], NULL, settings, &pos[1]);
                SDL_BlitSurface(menu_items[2], NULL, settings, &pos[2]);
                SDL_Flip(settings);
            }
            if (i == 1)
            {
                i = -1;
            }
            i++;
            break;
            x = event.motion.x;
            y = event.motion.y;
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
                    {
                        switch (i)
                        {
                        case 0:
                            //main_menu(&menu);
                            //main_menu(&screen2);
                            //first_stage(&stage1);
                            break;
                        case 1:
                            //display_settings(&settings);
                            break;
                        }
                    }
                }
            }
            break;
        }
    }

    for (int i = 0; i < 8; i++)
        SDL_FreeSurface(menu_items[i]);
    for (int i = 0; i < 2; i++)
        Mix_FreeMusic(bckmusic[i]);
    Mix_FreeChunk(son);
    Mix_CloseAudio();
    SDL_FreeSurface(settings);
    SDL_Flip(settings);
}

/**
 * @brief this function allows you to display main menu whit all the submenu
 * 
 * @param screen 
 */
void menu(SDL_Surface *screen)
{
    int i = 0;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    TTF_Init();
    // TTF_CloseFont();

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
        printf("error\n");
    }
    Mix_Music *bckmusic[3];

    for (int i = 0; i <= 3; i++)
        bckmusic[i] = NULL;
    bckmusic[0] = Mix_LoadMUS("son/interstellar.mp3");
    bckmusic[1] = Mix_LoadMUS("son/bckSon.mp3");
    bckmusic[2] = Mix_LoadMUS("son/bckSon.mp3");
    Mix_Chunk *son = NULL;
    son = Mix_LoadWAV("son/bouton.wav");
    Mix_PlayMusic(bckmusic[0], -1);

    SDL_Surface *menu_items[12], *bg = NULL;
    for (int i = 0; i < 12; i++)
        menu_items[i] = NULL;

    /**
 * @brief load all the images we will use in main menu
 * 
 */
    menu_items[0] = IMG_Load("fly12/new-game-1.png");
    menu_items[1] = IMG_Load("fly12/setting-1.png");
    menu_items[2] = IMG_Load("fly12/load-1.png");
    menu_items[3] = IMG_Load("fly12/quit-1.png");
    menu_items[4] = IMG_Load("fly12/multi-1.png");
    menu_items[5] = IMG_Load("btn/nom.png"); //fly12/background.png
    menu_items[6] = IMG_Load("fly12/b3.jpg");
    menu_items[7] = IMG_Load("fly12/new-game-2.png");
    menu_items[8] = IMG_Load("fly12/settings-2.png");
    menu_items[9] = IMG_Load("fly12/load-2.png");
    menu_items[10] = IMG_Load("buttons/background.jpg");
    menu_items[11] = IMG_Load("fly12/quit-2.png");
    SDL_Rect pos[5], screen_pos, position;

    screen = SDL_SetVideoMode(1285, 723, 32, SDL_HWSURFACE | SDL_RESIZABLE);
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
        printf("error\n");
    }
    SDL_WM_SetCaption("the best fly", NULL);
    bg = SDL_LoadBMP("fly12/b2.bmp");
    screen_pos.x = 0;
    screen_pos.y = 0;
    SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
    SDL_Flip(screen);

    //displaying start btn
    pos[0].x = screen->clip_rect.w / 2 - menu_items[0]->clip_rect.w / 2 + 350;
    pos[0].y = screen->clip_rect.h / 2 - menu_items[0]->clip_rect.h / 2 - 30;
    SDL_BlitSurface(menu_items[0], NULL, screen, &pos[0]);
    SDL_Flip(screen);

    //displaying  settings btn
    pos[1].x = screen->clip_rect.w / 2 - menu_items[1]->clip_rect.w / 2 + 400;
    pos[1].y = screen->clip_rect.h / 2 - menu_items[1]->clip_rect.h / 2 + 60;
    SDL_BlitSurface(menu_items[1], NULL, screen, &pos[1]);
    SDL_Flip(screen);

    //displaying about btn
    pos[2].x = screen->clip_rect.w / 2 - menu_items[2]->clip_rect.w / 2 + 450;
    pos[2].y = screen->clip_rect.h / 2 - menu_items[2]->clip_rect.h / 2 + 150;

    SDL_BlitSurface(menu_items[2], NULL, screen, &pos[2]);
    SDL_Flip(screen);

    //displaying quit btn
    pos[3].x = screen->clip_rect.w / 2 - menu_items[3]->clip_rect.w / 2 + 500;
    pos[3].y = screen->clip_rect.h / 2 - menu_items[3]->clip_rect.h / 2 + 240;
    SDL_BlitSurface(menu_items[3], NULL, screen, &pos[3]);
    SDL_Flip(screen);

    SDL_Flip(screen);

    int continuer = 1;
    SDL_Event event;
    Mix_PlayMusic(bckmusic[0], -1);
    int x, y, count1 = -1, count2 = 3;
    SDL_Surface settings, stage1, about_submenu;

    while (continuer)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            SDL_EnableKeyRepeat(1000, 1000);
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer = 0;
                break;
            case SDLK_f:
                SDL_WM_ToggleFullScreen(screen);
                break;
            case SDLK_DOWN:
                count1++;
                if (count1 > 3)
                {
                    count1 = -1;
                }
                switch (count1)
                {
                case 0:
                    SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[7], NULL, screen, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen, &pos[3]);
                    SDL_Flip(screen);
                    break;
                case 1:
                    SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen, &pos[0]);
                    SDL_BlitSurface(menu_items[8], NULL, screen, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen, &pos[3]);
                    SDL_Flip(screen);
                    break;
                case 2:
                    SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen, &pos[1]);
                    SDL_BlitSurface(menu_items[9], NULL, screen, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen, &pos[3]);
                    SDL_Flip(screen);
                    break;
                case 3:
                    SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen, &pos[2]);
                    SDL_BlitSurface(menu_items[11], NULL, screen, &pos[3]);
                    SDL_Flip(screen);
                    break;
                }
                break;
            case SDLK_UP:
                count1--;
                switch (count1)
                {
                case -1:
                    SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[7], NULL, screen, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen, &pos[3]);
                    SDL_Flip(screen);
                    break;
                case 1:
                    SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen, &pos[0]);
                    SDL_BlitSurface(menu_items[8], NULL, screen, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen, &pos[3]);
                    SDL_Flip(screen);
                    break;
                case 2:
                    SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen, &pos[1]);
                    SDL_BlitSurface(menu_items[9], NULL, screen, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen, &pos[3]);
                    SDL_Flip(screen);
                    break;
                case 3:
                    SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen, &pos[2]);
                    SDL_BlitSurface(menu_items[11], NULL, screen, &pos[3]);
                    SDL_Flip(screen);
                    break;
                }
                break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            x = event.motion.x;
            y = event.motion.y;
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
                    {
                        switch (i)
                        {
                        case 0:
                            //main_menu(&stage1);
                            first_stage(&stage1);
                            break;
                        case 1:
                            display_settings(&settings);
                            break;
                        case 2:
                            display_about(&about_submenu);
                            break;
                        case 3:
                            continuer = 0;
                            break;
                        }
                    }
                }
            }
            break;
        case SDL_MOUSEMOTION:
            x = event.motion.x;
            y = event.motion.y;
            if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
            {
                switch (i)
                {
                case 0:
                    SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[7], NULL, screen, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen, &pos[3]);
                    SDL_Flip(screen);
                    break;

                case 1:
                    SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen, &pos[0]);
                    SDL_BlitSurface(menu_items[8], NULL, screen, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen, &pos[3]);
                    SDL_Flip(screen);
                    break;
                case 2:
                    SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen, &pos[1]);
                    SDL_BlitSurface(menu_items[9], NULL, screen, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen, &pos[3]);
                    SDL_Flip(screen);
                    break;
                case 3:
                    SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen, &pos[2]);
                    SDL_BlitSurface(menu_items[11], NULL, screen, &pos[3]);
                    SDL_Flip(screen);
                    break;
                }
            }
            int bool = -1;
            for (int j = 0; j < 4; j++)
            {

                if (x >= pos[j].x && x <= pos[j].x + pos[j].w && y >= pos[j].y && y <= pos[j].y + pos[j].h)
                {
                    bool = 1;
                }
            }
            if (bool == -1)
            {
                SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
                SDL_BlitSurface(menu_items[0], NULL, screen, &pos[0]);
                SDL_BlitSurface(menu_items[1], NULL, screen, &pos[1]);
                SDL_BlitSurface(menu_items[2], NULL, screen, &pos[2]);
                SDL_BlitSurface(menu_items[3], NULL, screen, &pos[3]);
                SDL_Flip(screen);
            }
            if (i == 3)
            {
                i = -1;
            }
            i++;
            break;
        }
    }
    Mix_PlayMusic(bckmusic[0], -1);

    for (int i = 0; i < 11; i++)
        SDL_FreeSurface(menu_items[i]);

    for (int i = 0; i < 3; i++)
        Mix_FreeMusic(bckmusic[i]);
    Mix_FreeChunk(son);
    Mix_CloseAudio();
    SDL_FreeSurface(screen);
    SDL_Flip(screen);
    TTF_Quit();
    SDL_Quit();
}

//main menu
/**
 * @brief this function allow to come back to main menu anywhere you are in the game
 * 
 * @param screen2 
 */
void main_menu(SDL_Surface *screen2)
{
    int i = 0;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    TTF_Init();
    // TTF_CloseFont();

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
        printf("error\n");
    }
    Mix_Music *bckmusic[3];

    for (int i = 0; i <= 3; i++)
        bckmusic[i] = NULL;
    bckmusic[0] = Mix_LoadMUS("son/interstellar.mp3");
    bckmusic[1] = Mix_LoadMUS("son/bckSon.mp3");
    bckmusic[2] = Mix_LoadMUS("son/kafon.mp3");
    Mix_Chunk *son = NULL;
    son = Mix_LoadWAV("son/bouton.wav");
    Mix_PlayMusic(bckmusic[0], -1);

    SDL_Surface *menu_items[12];
    for (int i = 0; i < 12; i++)
        menu_items[i] = NULL;

    menu_items[0] = IMG_Load("fly12/new-game-1.png");
    menu_items[1] = IMG_Load("fly12/setting-1.png");
    menu_items[2] = IMG_Load("fly12/load-1.png");
    menu_items[3] = IMG_Load("fly12/quit-1.png");
    menu_items[4] = IMG_Load("fly12/multi-1.png");
    menu_items[5] = IMG_Load("btn/nom.png"); //fly12/background.png
    menu_items[6] = IMG_Load("fly12/b3.jpg");
    menu_items[7] = IMG_Load("fly12/new-game-2.png");
    menu_items[8] = IMG_Load("fly12/settings-2.png");
    menu_items[9] = IMG_Load("fly12/load-2.png");
    menu_items[10] = IMG_Load("buttons/background.jpg");
    menu_items[11] = IMG_Load("fly12/quit-2.png");
    SDL_Rect pos[5], screen_pos, position;

    screen2 = SDL_SetVideoMode(1285, 723, 32, SDL_HWSURFACE | SDL_RESIZABLE);
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
        printf("error\n");
    }
    SDL_WM_SetCaption("the hunt", NULL); // allow you to name window
    screen_pos.x = 0;
    screen_pos.y = 0;
    SDL_BlitSurface(menu_items[6], NULL, screen2, &screen_pos);
    SDL_Flip(screen2);

    //displaying start btn
    pos[0].x = screen2->clip_rect.w / 2 - menu_items[0]->clip_rect.w / 2 + 400;
    pos[0].y = screen2->clip_rect.h / 2 - menu_items[0]->clip_rect.h / 2 - 100;
    SDL_BlitSurface(menu_items[0], NULL, screen2, &pos[0]);
    SDL_Flip(screen2);

    //displaying  settings btn
    pos[1].x = screen2->clip_rect.w / 2 - menu_items[1]->clip_rect.w / 2 + 400;
    pos[1].y = screen2->clip_rect.h / 2 - menu_items[1]->clip_rect.h / 2;
    SDL_BlitSurface(menu_items[1], NULL, screen2, &pos[1]);
    SDL_Flip(screen2);

    //displaying about btn
    pos[2].x = screen2->clip_rect.w / 2 - menu_items[2]->clip_rect.w / 2 + 400;
    pos[2].y = screen2->clip_rect.h / 2 - menu_items[2]->clip_rect.h / 2 + 100;

    SDL_BlitSurface(menu_items[2], NULL, screen2, &pos[2]);
    SDL_Flip(screen2);

    //displaying quit btn
    pos[3].x = screen2->clip_rect.w / 2 - menu_items[3]->clip_rect.w / 2 + 400;
    pos[3].y = screen2->clip_rect.h / 2 - menu_items[3]->clip_rect.h / 2 + 200;
    SDL_BlitSurface(menu_items[3], NULL, screen2, &pos[3]);
    SDL_Flip(screen2);

    SDL_Flip(screen2);

    int continuer = 1;
    SDL_Event event;
    Mix_PlayMusic(bckmusic[0], -1);
    int x, y, count1 = -1, count2 = 3;
    SDL_Surface settings, stage1, about_submenu;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            SDL_EnableKeyRepeat(1000, 1000);
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer = 0;
                break;
            case SDLK_f:
                SDL_WM_ToggleFullScreen(screen2);
                break;
            case SDLK_DOWN:
                count1++;
                if (count1 > 3)
                {
                    count1 = -1;
                }
                switch (count1)
                {
                case 0:
                    SDL_BlitSurface(menu_items[6], NULL, screen2, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[7], NULL, screen2, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen2, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen2, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen2, &pos[3]);
                    SDL_Flip(screen2);
                    break;
                case 1:
                    SDL_BlitSurface(menu_items[6], NULL, screen2, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen2, &pos[0]);
                    SDL_BlitSurface(menu_items[8], NULL, screen2, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen2, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen2, &pos[3]);
                    SDL_Flip(screen2);
                    break;
                case 2:
                    SDL_BlitSurface(menu_items[6], NULL, screen2, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen2, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen2, &pos[1]);
                    SDL_BlitSurface(menu_items[9], NULL, screen2, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen2, &pos[3]);
                    SDL_Flip(screen2);
                    break;
                case 3:
                    SDL_BlitSurface(menu_items[6], NULL, screen2, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen2, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen2, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen2, &pos[2]);
                    SDL_BlitSurface(menu_items[11], NULL, screen2, &pos[3]);
                    SDL_Flip(screen2);
                    break;
                }
                break;
            case SDLK_UP:
                count1--;
                if (count2 < -1)
                {
                    count2 = -1;
                }
                // printf("count1=%d\n", count2);
                printf("count2=%d\n", count2);
                switch (count1)
                {
                case -1:
                    SDL_BlitSurface(menu_items[6], NULL, screen2, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[7], NULL, screen2, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen2, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen2, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen2, &pos[3]);
                    SDL_Flip(screen2);
                    break;
                case 1:
                    SDL_BlitSurface(menu_items[6], NULL, screen2, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen2, &pos[0]);
                    SDL_BlitSurface(menu_items[8], NULL, screen2, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen2, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen2, &pos[3]);
                    SDL_Flip(screen2);
                    break;
                case 2:
                    SDL_BlitSurface(menu_items[6], NULL, screen2, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen2, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen2, &pos[1]);
                    SDL_BlitSurface(menu_items[9], NULL, screen2, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen2, &pos[3]);
                    SDL_Flip(screen2);
                    break;
                case 3:
                    SDL_BlitSurface(menu_items[6], NULL, screen2, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen2, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen2, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen2, &pos[2]);
                    SDL_BlitSurface(menu_items[11], NULL, screen2, &pos[3]);
                    SDL_Flip(screen2);
                    break;
                }
                break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            x = event.motion.x;
            y = event.motion.y;
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
                    {
                        switch (i)
                        {
                        case 0:
                            first_stage(&stage1);
                            break;
                        case 1:
                            display_settings(&settings);
                            break;
                        case 2:
                            display_about(&about_submenu);
                            //settings_submenu(&about_submenu);
                            break;
                        case 3:
                            continuer = 0;
                            break;
                        }
                    }
                }
            }
            break;
        case SDL_MOUSEMOTION:
            x = event.motion.x;
            y = event.motion.y;
            if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
            {
                switch (i)
                {
                case 0:
                    SDL_BlitSurface(menu_items[6], NULL, screen2, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[7], NULL, screen2, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen2, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen2, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen2, &pos[3]);
                    SDL_Flip(screen2);
                    break;

                case 1:
                    SDL_BlitSurface(menu_items[6], NULL, screen2, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen2, &pos[0]);
                    SDL_BlitSurface(menu_items[8], NULL, screen2, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen2, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen2, &pos[3]);
                    SDL_Flip(screen2);
                    break;
                case 2:
                    SDL_BlitSurface(menu_items[6], NULL, screen2, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen2, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen2, &pos[1]);
                    SDL_BlitSurface(menu_items[9], NULL, screen2, &pos[2]);
                    SDL_BlitSurface(menu_items[3], NULL, screen2, &pos[3]);
                    SDL_Flip(screen2);
                    break;
                case 3:
                    SDL_BlitSurface(menu_items[6], NULL, screen2, &screen_pos);
                    Mix_PlayChannel(1, son, 0);
                    SDL_BlitSurface(menu_items[0], NULL, screen2, &pos[0]);
                    SDL_BlitSurface(menu_items[1], NULL, screen2, &pos[1]);
                    SDL_BlitSurface(menu_items[2], NULL, screen2, &pos[2]);
                    SDL_BlitSurface(menu_items[11], NULL, screen2, &pos[3]);
                    SDL_Flip(screen2);
                    break;
                }
            }
            int bool = -1;
            for (int j = 0; j < 4; j++)
            {

                if (x >= pos[j].x && x <= pos[j].x + pos[j].w && y >= pos[j].y && y <= pos[j].y + pos[j].h)
                {
                    bool = 1;
                }
            }
            if (bool == -1)
            {
                SDL_BlitSurface(menu_items[6], NULL, screen2, &screen_pos);
                SDL_BlitSurface(menu_items[0], NULL, screen2, &pos[0]);
                SDL_BlitSurface(menu_items[1], NULL, screen2, &pos[1]);
                SDL_BlitSurface(menu_items[2], NULL, screen2, &pos[2]);
                SDL_BlitSurface(menu_items[3], NULL, screen2, &pos[3]);
                SDL_Flip(screen2);
            }
            if (i == 3)
            {
                i = -1;
            }
            i++;
            break;
        }
    }

    for (int i = 0; i < 11; i++)
        SDL_FreeSurface(menu_items[i]);

    for (int i = 0; i < 3; i++)
        Mix_FreeMusic(bckmusic[i]);

    Mix_FreeChunk(son);
    Mix_CloseAudio();
    SDL_FreeSurface(screen2);
    SDL_Flip(screen2);
    TTF_Quit();
    SDL_Quit();
}