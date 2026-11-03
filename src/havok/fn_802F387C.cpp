#include <types.h>
#pragma force_active on

extern "C" void fn_802FF3FC(void* a, void* b);

struct Elem {
    void* a;
    s32 b;
};

struct Holder {
    u8 pad[0x40];
    Elem* elems;
    s32 count;
};

extern "C" void fn_802F387C(Holder* arg0, void* arg1) {
    for (s32 i = 0; i < arg0->count; i++) {
        fn_802FF3FC(arg0->elems[i].a, arg1);
    }
}
