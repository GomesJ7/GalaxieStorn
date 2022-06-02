#include <stdio.h>
#include "window.h"
#include "input.h"
#include "draw.h"
#include  "init.h"

int main()
{
    Win *app = malloc(sizeof(Win));
    Entity *player = malloc(sizeof(Entity));
    Entity *enemy = malloc(sizeof(Entity));
    Entity *enemy2 = malloc(sizeof(Entity));
    Entity *enemy3 = malloc(sizeof(Entity));
    Entity *enemy4 = malloc(sizeof(Entity));
    Entity *enemy5 = malloc(sizeof(Entity));
    if (initSDL(app) < 0) 
    {
        return -1;
    }

    player->pos_x = 100;
    player->pos_y = 250;
    player->width = 60;
    player->height = 60;
    player->texture = loadTexture(app, "ressource/player.png");

    enemy->pos_x = 1300;
    enemy->pos_y = 100;
    enemy->width = 45;
    enemy->height = 45;
    enemy->texture = loadTexture(app, "ressource/enemyrouge.png");

    enemy2->pos_x = 1400;
    enemy2->pos_y = 300;
    enemy2->width = 45;
    enemy2->height = 45;
    enemy2->texture = loadTexture(app, "ressource/enemypink.png");

    enemy3->pos_x = 1000;
    enemy3->pos_y = 250;
    enemy3->width = 45;
    enemy3->height = 45;
    enemy3->texture = loadTexture(app, "ressource/enemyblue.png");

    enemy4->pos_x = 1100;
    enemy4->pos_y = 170;
    enemy4->width = 45;
    enemy4->height = 45;
    enemy4->texture = loadTexture(app, "ressource/enemyrouge.png");

    enemy5->pos_x = 1450;
    enemy5->pos_y = 210;
    enemy5->width = 45;
    enemy5->height = 45;
    enemy5->texture = loadTexture(app, "ressource/enemyblue.png");


    while (input_handler(player, enemy, enemy2, enemy3, enemy4, enemy5) == 0)
    {
        prepareCanvas(app);
        if(drawEntity(app, player, enemy, enemy2, enemy3, enemy4, enemy5) == -1)
        {
            return 0;
        }
        presentCanvas(app);
        SDL_Delay(16);
    }
    free(app);
    free(player);
    free(enemy);
    free(enemy2);
    free(enemy3);
    free(enemy4);
    free(enemy5);

    return 0;
}