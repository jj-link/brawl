#pragma force_active on
class muMenu;
class gfPadSystem {
public:
    void startMotor(int);
};

extern "C" void startMotor__11gfPadSystemFiUs(gfPadSystem*, int, int);
extern "C" int fn_8004D9A8(void* p, int i);
extern "C" unsigned int fn_8004DA94(void* o, muMenu* m);
extern void* g_GameGlobal;
extern gfPadSystem* g_gfPadSystem;

class muMenu {
public:
    void startRumbleController(int, int, int);
};

void muMenu::startRumbleController(int arg0, int arg1, int arg2) {
    int r;
    if (arg1 >= 0) {
        r = fn_8004D9A8(g_GameGlobal, arg1);
    } else {
        r = fn_8004DA94(g_GameGlobal, this);
    }
    if (r != 0) {
        gfPadSystem* pad = g_gfPadSystem;
        if (arg0 > 0) {
            startMotor__11gfPadSystemFiUs(pad, (int)this, arg0);
            return;
        }
        pad->startMotor((int)this);
    }
}
