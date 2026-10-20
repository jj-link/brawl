#include <types.h>
#pragma force_active on

extern "C" void fn_27_41708(void* a, void* b);

struct Work {
    virtual void v0();
    virtual void* v1(s32 x);
};

extern "C" void fn_27_422C4(s16* hdr, Work* obj, void* arg3) {
    s32 i = 0;
    for (; i < *(s16*)(hdr + 3); i++) {
        fn_27_41708(obj->v1(*(s16*)(hdr + 2) + i), arg3);
    }
}
