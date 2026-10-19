#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_4B53C(void*, short);
void fn_27_19C45C(void*, short);
void __dl__FPv(void*);

void* fn_103_6618(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_4B53C(static_cast<u8*>(object) + 0x17C, memberDeleteFlag);
        fn_27_19C45C(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
