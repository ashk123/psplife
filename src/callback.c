#include <pspkernel.h>
#include <pspgu.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include <stdio.h>
#include <stdlib.h>
#include "rect.h"
#include "callback.h"

int exit_callback(int arg1, int arg2, void *common)
{
    done = 0;
    return 0;
}

int callback_thread(SceSize args, void *argp)
{
    int cbid = sceKernelCreateCallback("Exit Callback",
        exit_callback, NULL);
    sceKernelRegisterExitCallback(cbid);
    sceKernelSleepThreadCB();
    return 0;
}

int setup_callbacks(void)
{
    int thid = sceKernelCreateThread("update_thread",
        callback_thread, 0x11, 0xFA0, 0, 0);

    if(thid >= 0)
        sceKernelStartThread(thid, 0, 0);
    return thid;
}


