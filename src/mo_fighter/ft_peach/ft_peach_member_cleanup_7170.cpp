#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* fn_800A6A94(void* base, s16 deleteFlag);

void* fn_103_7170(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 baseDeleteFlag = 0;
        fn_800A6A94(object, baseDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
