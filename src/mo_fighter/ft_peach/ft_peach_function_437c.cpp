#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_B5324(void* member, s16 deleteFlag);
void* fn_103_4408(void* object, s16 deleteFlag);

void* fn_103_437C(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_B5324(static_cast<u8*>(object) + 0x20, memberDeleteFlag);
        void* base = static_cast<char*>(object) + 0x10;
        if (base != nullptr) {
            s16 baseDeleteFlag = 0;
            fn_103_4408(base, baseDeleteFlag);
        }
        void* base2 = object;
        if (base2 != nullptr) {
            s16 baseDeleteFlag2 = 0;
            fn_103_4408(base2, baseDeleteFlag2);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
