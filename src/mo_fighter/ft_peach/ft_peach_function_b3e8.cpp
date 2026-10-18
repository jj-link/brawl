#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_103_380C(void* object, s16 deleteFlag);

void* fn_103_B3E8(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        if (object != nullptr) {
            fn_103_380C(object, 0);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
