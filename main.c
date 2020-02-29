/**
 * @file main.c
 * @author the hunt teams(ngueemmanuel.prof@gmail.com)
 * @brief the calling menu and all the stage function
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
#include "fonctions.h"

int main()
{
    SDL_Surface screen;

    menu(&screen);
    return 0;
}