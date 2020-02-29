/**
 * @file fonctions.h
 * @author the hunt teams(ngueemmanuel.prof@gmail.com)
 * @brief declaring all the function and structure we will use in our game
 * @version 0.1
 * @date 2020-02-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef FONCTIONS_H_
#define FONCTIONS_H_

void menu(SDL_Surface *screen);                 /*!< main menu function*/
void main_menu(SDL_Surface *screen2);           /*!< alow to call main menu anywhere you are in game function*/
void first_stage(SDL_Surface *stage1);          /*!<stage one function*/
void display_about(SDL_Surface *about_submenu); /*!<about submenu function*/
void display_settings(SDL_Surface *settings);   /*!<settings submenu  function*/

#endif /* !FONCTIONS_H_ */
