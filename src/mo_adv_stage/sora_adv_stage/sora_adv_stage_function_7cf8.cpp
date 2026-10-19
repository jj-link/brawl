#include <types.h>
#pragma force_active on

extern "C" int fn_40_153BC(void*);
extern "C" void fn_40_1538C(void*);

extern "C" void fn_40_7CF8(void* self) {
    void* obj = *reinterpret_cast<void**>(reinterpret_cast<u8*>(self) + 0x518);
    if (obj) {
        if (fn_40_153BC(obj) != 0) {
            fn_40_1538C(*reinterpret_cast<void**>(reinterpret_cast<u8*>(self) + 0x518));
        }
    }
}
