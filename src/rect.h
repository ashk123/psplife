#define BUFFER_WIDTH 512
#define BUFFER_HEIGHT 270
#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 270

void initGu(void);
void drawRect(float x, float y, float w, float h, int color);
extern char list[0x20000] __attribute__((aligned(64)));
