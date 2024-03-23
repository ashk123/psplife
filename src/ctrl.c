#include <pspkernel.h>
#include <pspctrl.h>
#include <stdlib.h>
#include "ctrl.h"

Pl *pl;

void CtrlInitMain() {
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);
	InitialPl(pl);
}

void InitialPl(Pl* pl) {
	pl->x = 1;
	pl->y = 1;
	pl->act = 0;
}

Pl* getPl() {
	if (pl == NULL) {
		pl = (Pl*) malloc(3 * sizeof(Pl));
		InitialPl(pl);
		return pl;
	} else {
		return pl;
	}
}

void CtrlControl(SceCtrlData *pad) {
	int speed = 1;
	pl->act = 0;
	if (pad->Buttons & PSP_CTRL_SQUARE) {
		speed = 3;
	}
	if (pad->Buttons & PSP_CTRL_RIGHT) {
		pl->x += 1 * speed;
	} else if (pad->Buttons & PSP_CTRL_LEFT) {
		pl->x -= 1 * speed;
	} else if (pad->Buttons & PSP_CTRL_UP) {
		pl->y -= 1 * speed;
	} else if (pad->Buttons & PSP_CTRL_DOWN) {
		pl->y += 1 * speed;
	}
	if (pad->Buttons & PSP_CTRL_CIRCLE) {
		pl->act = 1 * speed;
	}
}
