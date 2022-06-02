#include "draw.h"
#include "window.h"

//ecran preparation et couleur
void prepareCanvas(Win *app)
{

    SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);

    SDL_RenderClear(app->renderer);
}

void presentCanvas(Win *app)
{
    SDL_RenderPresent(app->renderer);
}

//affichage des images
SDL_Texture *loadTexture(Win *app, char *img_path)
{
    SDL_Texture *texture;
    
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading: %s", img_path);
    texture = IMG_LoadTexture(app->renderer, img_path);
    if (texture == NULL) {
        printf("ERROR!! Failed to load texture %s\n", IMG_GetError());
    }
    return texture;
}

int collision( SDL_Rect *A, SDL_Rect *B )
{
    //Les cotes des rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
 
    //Calcul les cotes du rectangle A
    leftA = A->x;
    rightA = A->x + A->w;
    topA = A->y;
    bottomA = A->y + A->h;
 
    //Calcul les cotes du rectangle B
    leftB = B->x;
    rightB = B->x + B->w;
    topB = B->y;
    bottomB = B->y + B->h;
    //Tests de collision
    if( bottomA <= topB )
    {
        return 0;
    }
 
    if( topA >= bottomB )
    {
        return 0;
    }
 
    if( rightA <= leftB )
    {
        return 0;
    }
 
    if( leftA >= rightB )
    {
        return 0;
    }
 
    //Si conditions collision detectee
    return 1;
}

int drawEntity(Win *app,Entity *entity, Entity *enemy, Entity *enemy2, Entity *enemy3, Entity *enemy4, Entity *enemy5)
{
    SDL_Rect dest = {entity->pos_x, entity->pos_y, entity->width, entity->height};

    SDL_Rect boule = {enemy->pos_x, enemy->pos_y, enemy->width, enemy->height};

    SDL_Rect feu = {enemy2->pos_x, enemy2->pos_y, enemy2->width, enemy2->height};

    SDL_Rect fire = {enemy3->pos_x, enemy3->pos_y, enemy3->width, enemy3->height};

    SDL_Rect ball = {enemy4->pos_x, enemy4->pos_y, enemy4->width, enemy4->height};

    SDL_Rect rond = {enemy5->pos_x, enemy5->pos_y, enemy5->width, enemy5->height};

    SDL_RenderCopy(app->renderer, entity->texture, NULL, &dest);

    SDL_RenderCopy(app->renderer, enemy->texture, NULL, &boule);

    SDL_RenderCopy(app->renderer, enemy2->texture, NULL, &feu);

    SDL_RenderCopy(app->renderer, enemy3->texture, NULL, &fire);

    SDL_RenderCopy(app->renderer, enemy4->texture, NULL, &ball);

    SDL_RenderCopy(app->renderer, enemy5->texture, NULL, &rond);

    if(collision(&dest, &boule))
    {
        printf("GAME OVER HAHAHA!");
        return -1;
    }
    if(collision(&dest, &feu))
    {
        printf("GAME OVER HAHAHA!");
        return -1;
    }
    if(collision(&dest, &fire))
    {
        printf("GAME OVER HAHAHA!");
        return -1;
    }
    if(collision(&dest, &ball))
    {
        printf("GAME OVER HAHAHA!");
        return -1;
    }
    if(collision(&dest, &rond))
    {
        printf("GAME OVER HAHAHA!");
        return -1;
    }
    return 0;
}
