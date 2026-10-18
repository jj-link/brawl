#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_103_BF48(void* object, s16 deleteFlag);
void __dl__FPv(void* object);

void* fn_103_BFA4(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        fn_103_BF48(static_cast<u8*>(object) + 4, -1);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
