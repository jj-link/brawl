#include <types.h>
#pragma force_active on

extern "C" {
void __dt__14gfFileIOHandleFv(void* p, int flag);
void __dl__FPv(void* p);
void* fn_1_5058(void* p, s32 flag);
}

extern "C" void* fn_1_5058(void* p, s32 flag) {
    if (p != nullptr) {
        __dt__14gfFileIOHandleFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
