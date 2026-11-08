#pragma force_active on
#include <gf/gf_pad_system.h>

extern "C" {
extern gfPadSystem* g_gfPadSystem;
int fn_6_8F50(void*);
int fn_6_93B0(void*);
int getSysPadStatus__11gfPadSystemFiP11gfPadStatus(gfPadSystem*, int, gfPadStatus*);
}

struct Self {
    char pad0[0x124];
    int f124;
    char pad128[0x748 - 0x128];
    int state;
};

extern "C" int fn_6_9CA8(Self* self) {
    gfPadStatus status;
    int r;

    r = getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, 0xF0, &status);

    switch (self->state) {
    case 0:
        r = fn_6_8F50(self);
        break;
    case 1:
        r = fn_6_93B0(self);
        break;
    }

    switch (r) {
    case 1:
        return 10;
    case 2:
        return 8;
    case 3:
        return 9;
    default:
        return self->f124;
    }
}
