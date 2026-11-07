#include <snd/snd_system.h>
#pragma force_active on

struct Obj {
    char _0[0x264];
    void* ptr_264;
};

struct Menu {
    char _0[0x64C];
    Obj* objects;
    char _650[0x28];
    int index;
    int value;
};

extern "C" {
unsigned int fn_18_12E0(Menu*);
void fn_800B330C(void*, void*, int);
void fn_2_28AEC(Menu*, int);
extern int lbl_2_data_3280[];
extern char lbl_2_data_3240[];

int fn_2_28CDC(Menu* self) {
    int saved = self->value;
    unsigned int flags = fn_18_12E0(self);
    if ((flags & 2) && self->index < 0x17) {
        self->index++;
        self->value = lbl_2_data_3280[self->index];
        fn_800B330C(self->objects->ptr_264, lbl_2_data_3240 + 0x28, 0);
    }
    if ((flags & 1) && self->index > 0) {
        self->index--;
        self->value = lbl_2_data_3280[self->index];
        fn_800B330C(self->objects->ptr_264, lbl_2_data_3240 + 0x14, 0);
    }
    if (saved != self->value) {
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        fn_2_28AEC(self, 1);
    }
    return 1;
}
}
