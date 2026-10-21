#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_1AA4(void*, short);
void* fn_103_1B64(void*, short);
void* fn_103_1BC0(void*, short);
void* fn_103_1C1C(void*, short);
void* fn_103_1C78(void*, short);
void* fn_103_1CD4(void*, short);
void* fn_103_1D30(void*, short);
void* fn_103_1D8C(void*, short);
void __dl__FPv(void*);

void* fn_103_19EC(void* object, short deleteFlag) {
    if (object != nullptr) {
        short memberDeleteFlag = -1;
        u8* members = static_cast<u8*>(object);
        fn_103_1AA4(members + 0x84, memberDeleteFlag);
        fn_103_1B64(members + 0x70, memberDeleteFlag);
        fn_103_1BC0(members + 0x5C, memberDeleteFlag);
        fn_103_1C1C(members + 0x48, memberDeleteFlag);
        fn_103_1C78(members + 0x34, memberDeleteFlag);
        fn_103_1CD4(members + 0x20, memberDeleteFlag);
        fn_103_1D30(members + 0x8, memberDeleteFlag);
        fn_103_1D8C(object, static_cast<short>(0));
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
