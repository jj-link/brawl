#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_103_380C(void* base, s16 deleteFlag);

void* fn_103_B8F0(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        void* base = object;
        if (base != nullptr) {
            s16 baseDeleteFlag = 0;
            fn_103_380C(base, baseDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
