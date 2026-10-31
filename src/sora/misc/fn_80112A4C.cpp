#include <types.h>
#include <revolution/OS/OSTime.h>

#pragma force_active on

union Flags {
    unsigned char flags;
    struct {
        unsigned char active : 1;
        unsigned char bit6 : 1;
        unsigned char bit5 : 1;
        unsigned char bit4 : 1;
        unsigned char bit3 : 1;
        unsigned char bit2 : 1;
        unsigned char bit1 : 1;
        unsigned char bit0 : 1;
    } bit;
};

struct Object {
    char pad[0x40];
    Flags state;
};

extern "C" {
int fn_8004E96C(void* p);
void fn_80112674(void* p, s32 x);
void fn_801127D0(void* p);
extern void* g_GameGlobal;
extern unsigned char lbl_805A0358;
}

extern "C" void fn_80112A4C(void* self) {
    Object* object = (Object*)self;
    object->state.flags = (object->state.flags | 0x80) & ~0x40;

    if (fn_8004E96C(g_GameGlobal) != 0) {
        object->state.flags |= 0x40;
    }

    bool active = (object->state.flags >> 7) & 1;
    if (active) {
        const unsigned char* flag = &object->state.flags;
        lbl_805A0358 = (*flag & 0x20) >> 5;
        OSGetTime();
        fn_80112674(self, 0);
        fn_801127D0(self);
        OSGetTime();
    }
}
