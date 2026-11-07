#include <types.h>
#pragma force_active on

s32 fn_8027B4A8(u8* base, s32 idx);
s32 fn_8027B4C4(u8* base, s32 idx, s32 arg);

s32 fn_8027A8EC(u8* obj, s32 arg1) {
    if (fn_8027B4A8(*(u8**)(obj + 0x24), *(s32*)obj) == 0) {
        return 0;
    }
    return fn_8027B4C4(*(u8**)(obj + 0x24), *(s32*)obj, arg1);
}
