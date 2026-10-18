#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A1E70(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_111_1009C(void* object, s16 deleting) {
    if (object) {
        if (object) {
            fn_27_1A1E70(object, -1);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
