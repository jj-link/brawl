#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* fn_27_1A1FE4(void* member, s16 deleteFlag);

void* fn_103_6E24(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        void* base = object;
        if (base != nullptr) {
            s16 memberDeleteFlag = -1;
            fn_27_1A1FE4(base, memberDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
