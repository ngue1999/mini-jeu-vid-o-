#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"

void boucle_jeu()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    SDL_Surface *menu_items[4];

    for (int i = 0; i <= 4; i++)
        menu_items[i] = NULL;
    menu_items[0] = IMG_Load("image2/play-btn-orange.png");
    menu_items[1] = IMG_Load("image2/setting-btn-orange.png");
    menu_items[2] = IMG_Load("image2/exit-btn-orange.png");
    menu_items[3] = IMG_Load("image2/background2.jpg");
    SDL_Rect pos[3];

    menu_items[4] = SDL_SetVideoMode(1285, 723, 32, SDL_HWSURFACE);

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
        printf("error\n");
    }
    SDL_WM_SetCaption("Menu", NULL);

    //displaying background
    pos[3].x = 0;
    pos[3].y = 0;
    SDL_BlitSurface(menu_items[3], NULL, menu_items[4], &pos[3]);
    SDL_Flip(menu_items[4]);

    //displaying button
    pos[0].x = menu_items[4]->clip_rect.w / 2 - menu_items[0]->clip_rect.w / 2;
    pos[0].y = menu_items[4]->clip_rect.h / 2 - menu_items[0]->clip_rect.h / 2 - 50;
    SDL_BlitSurface(menu_items[0], NULL, menu_items[4], &pos[0]);
    SDL_Flip(menu_items[4]);

    //displaying settings button
    pos[1].x = menu_items[4]->clip_rect.w / 2 - menu_items[1]->clip_rect.w / 2;
    pos[1].y = menu_items[4]->clip_rect.h / 2 - menu_items[1]->clip_rect.h / 2 + 50;
    SDL_BlitSurface(menu_items[1], NULL, menu_items[4], &pos[1]);
    SDL_Flip(menu_items[4]);

    //displaying exit button
    pos[2].x = menu_items[4]->clip_rect.w / 2 - menu_items[2]->clip_rect.w / 2;
    pos[2].y = menu_items[4]->clip_rect.h / 2 - menu_items[2]->clip_rect.h / 2 + 150;
    SDL_BlitSurface(menu_items[2], NULL, menu_items[4], &pos[2]);
    SDL_Flip(menu_items[4]);

    int continuer = 1;
    SDL_Event event;
    int x, y;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        { //pricipal
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            { //second
            case SDLK_ESCAPE:
                continuer = 0;
                break;

            } //second

            break;
        case SDL_MOUSEBUTTONDOWN:
            x = event.motion.x;
            y = event.motion.y;
            for (int i = 0; i < 4; i++)
            {
                if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
                {
                    printf("index:%d", i);
                }
            }
            break;
        }

        break;
    } //pricipal
    SDL_Flip(menu_items[4]);
    for (int i = 0; i <= 4; i++)
        SDL_FreeSurface(menu_items[i]);

    SDL_Quit();
}
