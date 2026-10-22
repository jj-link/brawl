#include <types.h>
#pragma force_active on

extern "C" void exit__6gfTaskFv(void* self);

struct Fn800DB1B0Owner {
    u8 pad0[0x48];
    s32 f48;
    u8 pad1[0x4];
    s32 f50;
    u8 pad2[0x8];
    u8* f5c;
};

extern "C" s32 fn_800DB1B0(Fn800DB1B0Owner* self) {
    s32 state;
    u8* task;
    task = self->f5c;
    if (task == 0) {
        state = 0;
    } else if (*(s32*)(task + 0x104) != 3) {
        state = 1;
    } else {
        state = 3;
        if (*(u8*)(task + 0x100) != 0) {
            state = 2;
        }
    }
    if (state != 1) {
        if (task != 0) {
            exit__6gfTaskFv(task);
            self->f5c = 0;
        }
        self->f48 = 1;
        return 4;
    }
    return self->f50;
}
