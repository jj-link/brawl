#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_103_4408(void* object, s16 deleteFlag);

void* fn_103_6984(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        fn_103_4408(object, 0);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
