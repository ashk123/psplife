#include <pspctrl.h>
typedef struct {
	int x, y;
	int act;
} Pl;

extern Pl* getPl();
extern void CtrlControl(SceCtrlData *pad);
extern void CtrlInitMain();
