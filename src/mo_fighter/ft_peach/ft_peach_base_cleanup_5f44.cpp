#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* fn_27_1A15B8(void* base, s16 deleteFlag);

void* fn_103_5F44(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        void* base = object;
        if (base != nullptr) {
            s16 baseDeleteFlag = -1;
            fn_27_1A15B8(base, baseDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
