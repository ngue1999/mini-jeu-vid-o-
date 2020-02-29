// int bool = -1;
// for (int i = 0; i < 4; i++)
// {

//     if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
//     {
//         bool = 1;
//     }
// }
// if (bool == -1)
// {
//     SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
//     SDL_BlitSurface(menu_items[0], NULL, screen, &pos[0]);
//     SDL_BlitSurface(menu_items[1], NULL, screen, &pos[1]);
//     SDL_BlitSurface(menu_items[2], NULL, screen, &pos[2]);
//     SDL_BlitSurface(menu_items[3], NULL, screen, &pos[3]);
//     SDL_Flip(screen);
// }
// for (int i = 0; i < 4; i++)
// {
//     if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
//     {
//         switch (i)
//         {
//         case 0:
//             SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
//             SDL_BlitSurface(menu_items[7], NULL, screen, &pos[0]);
//             SDL_BlitSurface(menu_items[1], NULL, screen, &pos[1]);
//             SDL_BlitSurface(menu_items[2], NULL, screen, &pos[2]);
//             SDL_BlitSurface(menu_items[3], NULL, screen, &pos[3]);
//             SDL_Flip(screen);
//             break;

//         case 1:
//             SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
//             SDL_BlitSurface(menu_items[0], NULL, screen, &pos[0]);
//             SDL_BlitSurface(menu_items[8], NULL, screen, &pos[1]);
//             SDL_BlitSurface(menu_items[2], NULL, screen, &pos[2]);
//             SDL_BlitSurface(menu_items[3], NULL, screen, &pos[3]);
//             SDL_Flip(screen);
//             break;
//         case 2:
//             SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
//             SDL_BlitSurface(menu_items[0], NULL, screen, &pos[0]);
//             SDL_BlitSurface(menu_items[1], NULL, screen, &pos[1]);
//             SDL_BlitSurface(menu_items[9], NULL, screen, &pos[2]);
//             SDL_BlitSurface(menu_items[3], NULL, screen, &pos[3]);
//             SDL_Flip(screen);
//             break;
//         case 3:
//             SDL_BlitSurface(menu_items[6], NULL, screen, &screen_pos);
//             SDL_BlitSurface(menu_items[0], NULL, screen, &pos[0]);
//             SDL_BlitSurface(menu_items[1], NULL, screen, &pos[1]);
//             SDL_BlitSurface(menu_items[2], NULL, screen, &pos[2]);
//             SDL_BlitSurface(menu_items[11], NULL, screen, &pos[3]);
//             SDL_Flip(screen);
//             break;
//         }
//     }
// }