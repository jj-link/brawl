#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_D2904(void* member, s16 deleteFlag);
void* fn_100_5960(void* base, s16 deleteFlag);

void* fn_100_58E8(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_D2904(static_cast<u8*>(object) + 0xB4, memberDeleteFlag);
        void* base = object;
        if (base != nullptr) {
            s16 baseDeleteFlag = 0;
            fn_100_5960(base, baseDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
