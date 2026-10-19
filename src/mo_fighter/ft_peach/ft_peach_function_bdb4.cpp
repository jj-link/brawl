#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_103_380C(void* object, s16 deleteFlag);

void* fn_103_BDB4(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = 0;
        fn_103_380C(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
