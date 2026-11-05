#include <types.h>
#pragma force_active on

struct Entry {
    u32 pad0;
    s32 value;
    u8 pad8[0x1c];
    u32 flags;
};

class Class_C80 {
public:
    virtual void fn_27_FEE4();
    virtual Entry* fn_27_FF68(s32 index);
};

struct Data {
    u8 pad0[4];
    s16 offset;
    s16 count;
    u8 pad8[0x2B];
    u8 changed;
};

extern "C" void fn_27_42180(Data* self, Class_C80* obj, u32 key, s32 value) {
    for (s32 i = 0; i < self->count; i++) {
        if (key == (obj->fn_27_FF68(self->offset + i)->flags >> 23)) {
            obj->fn_27_FF68(self->offset + i)->value = value;
            self->changed = 1;
            return;
        }
    }
}
