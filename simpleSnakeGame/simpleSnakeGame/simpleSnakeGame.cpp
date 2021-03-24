#include <iostream>
#include "map.h"
#include "snake.h"
#include "player.h"
using namespace std;
int main() {
   map m;
   snake s;
   player p;
   while (!p.getGameOver()) {
        m.draw(s, p);
        s.input();
        s.move(p); 
        printf(" Score : %d ", p.getScore());
   }
   printf("             Game Over!.....\n");
   system("pause");
}

