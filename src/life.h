#include "rect.h"

#define ROW ((int)SCREEN_WIDTH / (CSIZE + CPAD))
#define COL ((int)SCREEN_HEIGHT / (CSIZE + CPAD))
#define CSIZE 5
#define CPAD 2
// #define CFSIZE CSIZE
// #define CFPAD CPAD

void UpdateLifeMap();
void Evolution();
void draw();
