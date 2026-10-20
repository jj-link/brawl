#include <types.h>
#pragma force_active on

extern "C" void fn_27_2429BC(void*, s32);

extern "C" void* fn_27_24427C(void* obj, s32 count) {
    if (obj) {
        fn_27_2429BC(obj, 0);
        if (count > 0)
            operator delete(obj);
    }
    return obj;
}
