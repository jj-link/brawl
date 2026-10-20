#include <types.h>
#pragma force_active on

extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, s16);
void* fn_27_82AD4(void*, s16);
void* fn_27_CB800(void*, s16);
void* fn_27_CCF74(void*, s16);
void __dl__FPv(void*);

void* fn_41_2F54C(void* obj, s16 p1) {
    if (obj) {
        __dt__27soCollisionAttackModuleImplFv(static_cast<u8*>(obj) + 0x2bc, -1);
        fn_27_82AD4(static_cast<u8*>(obj) + 0x2b8, -1);
        fn_27_CB800(static_cast<u8*>(obj) + 0x1bc, -1);
        fn_27_CCF74(obj, -1);
        if (p1 > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
}
