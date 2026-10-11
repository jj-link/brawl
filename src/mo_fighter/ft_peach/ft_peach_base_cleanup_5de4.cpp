#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* fn_27_D2904(void* member, s16 deleteFlag);
void* fn_103_5E5C(void* base, s16 deleteFlag);

void* fn_103_5DE4(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_D2904(static_cast<u8*>(object) + 0xB4, memberDeleteFlag);
        void* base = object;
        if (base != nullptr) {
            s16 baseDeleteFlag = 0;
            fn_103_5E5C(base, baseDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
