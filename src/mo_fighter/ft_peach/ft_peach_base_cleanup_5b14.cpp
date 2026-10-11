#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* fn_27_1A15B8(void* member, s16 deleteFlag);
void* fn_103_5B8C(void* base, s16 deleteFlag);

void* fn_103_5B14(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_1A15B8(static_cast<u8*>(object) + 0x20C, memberDeleteFlag);
        void* base = object;
        if (base != nullptr) {
            s16 baseDeleteFlag = 0;
            fn_103_5B8C(base, baseDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
