#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_D2904(void* member, s16 deleteFlag);
void* fn_109_5480(void* object, s16 deleteFlag);
void __dl__FPv(void*);

void* fn_109_5408(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_D2904(static_cast<u8*>(object) + 0x154, memberDeleteFlag);
        if (object != nullptr) {
            s16 baseDeleteFlag = 0;
            fn_109_5480(object, baseDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
