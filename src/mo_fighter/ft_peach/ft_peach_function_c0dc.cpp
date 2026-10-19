#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_C064(void* object, s16 flag);

void* fn_103_C0DC(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        fn_103_C064(object, 0);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
