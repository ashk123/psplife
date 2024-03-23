#include <pspkernel.h>
#include <pspgu.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include <stdio.h>
#include <stdlib.h>
#include "rect.h"
#include "callback.h"
#include "life.h"
#include "colors.h"
#include "ctrl.h"

PSP_MODULE_INFO("GameOfLife", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_VFPU | THREAD_ATTR_USER);

// void sleep(float value);

int done = 1;

void frames()
{
    sceGuStart(GU_DIRECT, list);
    sceGuClearColor(BLACK);
    sceGuClear(GU_COLOR_BUFFER_BIT);
}

void endFrame()
{
    sceGuFinish();
    sceGuSync(0, 0);
    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}

int main()
{
	SceCtrlData pad;
	CtrlInitMain();
    initGu();
    UpdateLifeMap();
    setup_callbacks();
    while (done){

        sceCtrlReadBufferPositive(&pad, 1);

        sleep(0.8);
		CtrlControl(&pad);
        frames();
        draw();
        Evolution();
        endFrame();

    }
    return 0;
}
