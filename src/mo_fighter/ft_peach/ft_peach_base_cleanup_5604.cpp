#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* fn_103_5664(void* base, s16 deleteFlag);

void* fn_103_5604(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        void* base = object;
        if (base != nullptr) {
            s16 baseDeleteFlag = 0;
            fn_103_5664(base, baseDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
