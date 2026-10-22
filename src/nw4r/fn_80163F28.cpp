#include <types.h>
#pragma force_active on

extern "C" u32 fn_80164DB8(u32 a);
extern "C" u16 fn_8016F198(void* a, void* b, u16 c);

extern "C" s32 fn_80163F28(u8* self) {
    u32 buf[1026];
    u32 sum = 0;
    u16 count = fn_8016F198(self + 0x24, buf, *(u16*)(self + 0x2c));
    for (u16 i = 0; i < count; i++) {
        sum += fn_80164DB8(buf[i]);
    }
    return sum;
}
