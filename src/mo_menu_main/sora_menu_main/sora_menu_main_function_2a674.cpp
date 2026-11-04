#include <mu/mu_msg.h>
#include <gm/gm_global.h>
#pragma force_active on
extern "C" int fn_8004D6C4(void*, int, char*);
struct Menu {
    char pad0[0x66c];
    unsigned long index;
    char pad670[8];
    MuMsg* msg;
    char pad67c[0x18];
    int current;
    char pad698[0xc];
    int count;
};
extern "C" void fn_2_2A674(Menu* self, int enabled) {
    char buf[16];
    GameGlobal* global;
    int current = self->current;
    global = g_GameGlobal;
    if (enabled && current < self->count - 1) {
        fn_8004D6C4(global, current + 1, buf);
    } else {
        buf[0] = 0;
    }
    self->msg->printf(self->index + 3, buf);
    if (enabled && current > 0) {
        fn_8004D6C4(global, current - 1, buf);
    } else {
        buf[0] = 0;
    }
    self->msg->printf(self->index + 2, buf);
}