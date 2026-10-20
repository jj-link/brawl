#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_1A262C(void* member, s16 deleteFlag);
void* fn_103_400C(void* object, s16 deleteFlag);
void* fn_103_404C(void* object, s16 deleteFlag);

void* fn_103_3F84(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        u8* base = (u8*)object;
        if (base + 0x24 != nullptr) {
            s16 f1 = -1;
            fn_27_1A262C(base + 0x34, f1);
            s16 f2 = 0;
            fn_103_400C(base + 0x24, f2);
        }
        s16 f3 = -1;
        fn_103_404C(object, f3);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
