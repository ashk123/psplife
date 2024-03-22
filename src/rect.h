#define BUFFER_WIDTH 512
#define BUFFER_HEIGHT 272
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272

void initGu(void);
void drawRect(float x, float y, float w, float h, int color);
extern char list[0x90000] __attribute__((aligned(64)));
