#include <types.h>
#pragma force_active on

struct Arg0 {
    u8 pad[0x1C];
    u8* data;
    s32 count;
};

struct Arg1 {
    u16* arr;
    s32 index;
    s32 value;
};

extern "C" void fn_8027CE3C(void*, int);

extern "C" void fn_802D8E78(Arg0* arg0, Arg1* arg1) {
    u16 val;
    for (s32 i = 0; i < arg0->count; i++) {
        if (arg0->data[i] != 0xFF) {
            val = (u16)i;
            if (arg1->index == (arg1->value & 0x3FFFFFFF)) {
                fn_8027CE3C(arg1, 2);
            }
            arg1->arr[arg1->index++] = val;
        }
    }
}
