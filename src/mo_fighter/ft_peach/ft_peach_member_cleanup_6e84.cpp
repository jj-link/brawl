#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* __dt__17soModelModuleImplFv(void* member, s16 deleteFlag);
void* fn_103_6EFC(void* member, s16 deleteFlag);
void* fn_27_19A83C(void* member, s16 deleteFlag);

void* fn_103_6E84(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        __dt__17soModelModuleImplFv(static_cast<u8*>(object) + 0x1F4, memberDeleteFlag);
        fn_103_6EFC(static_cast<u8*>(object) + 0x1AC, memberDeleteFlag);
        fn_27_19A83C(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
