#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_103_4408(void* object, s16 deleteFlag);

void* fn_103_6924(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        void* base = object;
        if (base != nullptr) {
            s16 baseDeleteFlag = 0;
            fn_103_4408(base, baseDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
