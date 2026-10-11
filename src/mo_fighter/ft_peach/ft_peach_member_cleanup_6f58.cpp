#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* __dt__20soResourceModuleImplFv(void* member, s16 deleteFlag);
void* fn_103_4684(void* member, s16 deleteFlag);

void* fn_103_6F58(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        __dt__20soResourceModuleImplFv(static_cast<u8*>(object) + 0xC, memberDeleteFlag);
        void* base = object;
        if (base != nullptr) {
            s16 baseDeleteFlag = 0;
            fn_103_4684(base, baseDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
