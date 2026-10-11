#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* fn_27_1A15B8(void* member, s16 deleteFlag);
void* fn_103_59AC(void* base, s16 deleteFlag);

void* fn_103_5934(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_1A15B8(static_cast<u8*>(object) + 0x30C, memberDeleteFlag);
        void* base = object;
        if (base != nullptr) {
            s16 baseDeleteFlag = 0;
            fn_103_59AC(base, baseDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
