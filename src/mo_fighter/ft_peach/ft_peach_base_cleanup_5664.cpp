#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* fn_27_1A1CFC(void* member, s16 deleteFlag);
void* fn_103_56DC(void* base, s16 deleteFlag);

void* fn_103_5664(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_1A1CFC(static_cast<u8*>(object) + 0x544, memberDeleteFlag);
        void* base = object;
        if (base != nullptr) {
            s16 baseDeleteFlag = 0;
            fn_103_56DC(base, baseDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
