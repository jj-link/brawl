#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_C102C(void* obj);

extern "C" void* fn_27_BEF94(void* self) {
    u8* p = (u8*)self;
    u32 flag = 0;
    if (fn_27_C102C(p + 0xb8) == 1) {
        if (fn_27_C102C(p + 0x30) == 1) {
            s32 a = *(s32*)(p + 0x13c);
            s32 b = *(s32*)(p + 0xb4);
            if (a > b) flag = 1;
        } else {
            flag = 1;
        }
    }
    if (flag == 1) return p + 0xb8;
    return p + 0x30;
}
