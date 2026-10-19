#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_103_1B00(void* object, s16 flag);

void* fn_103_1CD4(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        fn_103_1B00(object, static_cast<s16>(0));
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
