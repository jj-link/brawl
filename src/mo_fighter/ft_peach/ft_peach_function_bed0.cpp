#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_BE70(void* object, s16 deleteFlag);
void* fn_103_BD3C(void* object, s16 deleteFlag);

void* fn_103_BED0(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_BE70(static_cast<u8*>(object) + 0x1C8, memberDeleteFlag);
        if (object != nullptr) {
            s16 baseDeleteFlag = 0;
            fn_103_BD3C(object, baseDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
