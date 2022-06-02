#include "input.h"
#include <stdio.h>

int input_handler(Entity *entity, Entity *enemy, Entity *enemy2, Entity *enemy3, Entity *enemy4, Entity *enemy5) {
    SDL_Event event;
    
    SDL_PollEvent(&event);
//vitesse des ennemies venant de droite à gauche
        enemy->pos_x -= 2;
        enemy2->pos_x -= 2;
        enemy3->pos_x -= 2;
        enemy4->pos_x -= 2;
        enemy5->pos_x -= 2;

    //deplacement joueur
    switch (event.type)
    {
        case SDL_QUIT :
        return -1;
    case SDL_KEYDOWN :
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            entity -> pos_y -= 6;
            break;

        case SDLK_DOWN:
            entity->pos_y += 6;
            break;

        case SDLK_LEFT:
            entity->pos_x -= 6;
            break;

        case SDLK_RIGHT:
            entity->pos_x += 6;
            break;

        case SDL_KEYUP :
            break;


    default:
        break;
        }
        // limite du joueur dans la fenetre
        if (entity->pos_x <= 0) entity->pos_x = 0;
        if (entity->pos_y <= 0) entity->pos_y = 0;
        if (entity->pos_x >= WINDOW_WIDTH - entity->width) entity->pos_x = WINDOW_WIDTH - entity->width;
        if (entity->pos_y >= WINDOW_HEIGHT - entity->height) entity->pos_y = WINDOW_HEIGHT - entity->height;

        SDL_Delay(1000/60);
    } return 0;
}