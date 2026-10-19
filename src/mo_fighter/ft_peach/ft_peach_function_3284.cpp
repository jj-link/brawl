#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_32F4(void* object, s16 deleteFlag);
void fn_103_52FC(void* object, s16 deleteFlag);

void* fn_103_3284(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_32F4(static_cast<u8*>(object) + 0x8, memberDeleteFlag);
        s16 baseDeleteFlag = 0;
        fn_103_52FC(object, baseDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
