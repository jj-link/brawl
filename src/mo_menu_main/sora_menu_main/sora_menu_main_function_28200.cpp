#include <snd/snd_system.h>
#pragma force_active on

struct Obj {
    char _0[0x230];
    void* ptr_230;
    void* ptr_234;
};

struct Target {
    char _0[0x8C];
    unsigned char byte_8C;
};

struct Menu {
    char _0[0x64C];
    Obj* objects;
    char _650[0x28];
    Target* target;
    unsigned char byte_67C;
    unsigned char byte_67D;
};

extern "C" {
unsigned int fn_18_12E0(Menu*);
void fn_800B330C(void*, void*, int);
void fn_2_27E34(Menu*, int);
extern unsigned char lbl_2_data_3110[];
}

extern "C" int fn_2_28200(Menu* self) {
    unsigned char saved_67C = self->byte_67C;
    unsigned char saved_67D = self->byte_67D;
    unsigned int flags = fn_18_12E0(self);

    if (flags & 2) {
        unsigned char v = self->byte_67D;
        if (v + 6 < self->target->byte_8C) {
            self->byte_67D = v + 1;
            fn_800B330C(self->objects->ptr_230, lbl_2_data_3110 + 0x28, 0);
        }
    }
    if (flags & 1) {
        unsigned char v = self->byte_67D;
        if (v != 0) {
            self->byte_67D = v - 1;
            fn_800B330C(self->objects->ptr_230, lbl_2_data_3110 + 0x14, 0);
        }
    }
    if (flags & 8) {
        unsigned char v = self->byte_67C;
        if (v + 5 < self->target->byte_8C) {
            self->byte_67C = v + 1;
            fn_800B330C(self->objects->ptr_234, lbl_2_data_3110 + 0x14, 0);
        }
    }
    if (flags & 4) {
        unsigned char v = self->byte_67C;
        if (v != 0) {
            self->byte_67C = v - 1;
            fn_800B330C(self->objects->ptr_234, lbl_2_data_3110 + 0x28, 0);
        }
    }
    if (saved_67C != self->byte_67C || saved_67D != self->byte_67D) {
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        fn_2_27E34(self, 1);
    }
    return 1;
}