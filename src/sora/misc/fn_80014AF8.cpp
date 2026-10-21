#include <types.h>
#pragma force_active on

struct Header {
    u32 magic;
    u16 version;
    u16 count;
};

struct Object {
    u8 pad00[8];
    u32 kind : 8;
    u32 flags : 24;
    u16 pad0C;
    u16 count;
    u32 pad10;
    s32 overrideValue;
    u8 pad18[8];
    Header* data;
    s32 size;
    u8 pad28[0x48];
    u32 field70;
};

extern "C" void PPCHalt();
extern "C" void fn_80014BF4(Object*, Header*, s32);
extern "C" void fn_800141E8(Object*);

extern "C" void fn_80014AF8(Object* self, Header* data, s32 size, s32 value) {
    self->data = data;
    self->kind = 3;
    self->size = size;
    *((u8*)self + 9) |= 0x80;
    self->field70 = 0;

    int valid;
    if (data->magic == 0x41524300 &&
        (u16)(data->version + 0xFF00) <= 1U) {
        valid = 1;
    } else {
        valid = 0;
    }

    if (!valid) {
        PPCHalt();
    }

    u16 count = data->count;
    self->count = count;
    if (count != 0) {
        if (!((*((u8*)self + 9) >> 4) & 1)) {
            s32 overrideValue = self->overrideValue;
            if (overrideValue != 0) {
                value = overrideValue;
            }
            fn_80014BF4(self, data, value);
        }
        if ((*((u8*)self + 9) >> 3) & 1) {
            fn_800141E8(self);
        }
    }
}
