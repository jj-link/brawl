#include <types.h>
#pragma force_active on

extern "C" int fn_40_153B4(void*);
extern "C" void fn_40_1530C(void*);

extern "C" void fn_40_7CAC(void* self) {
    void* obj = *(void**)((char*)self + 0x518);
    if (obj && fn_40_153B4(obj)) {
        fn_40_1530C(*(void**)((char*)self + 0x518));
    }
}
