#include <types.h>
#pragma force_active on

extern "C" u16 fn_8016F198(void* a, void* b, u16 c);
extern "C" s32 fn_8016C50C(u32 v);

extern "C" s32 fn_80164DB8(u8* self) {
    u32 buf[1024];
    s32 sum = 0;
    u16 count = fn_8016F198(self + 0xC0, buf, *(u16*)(self + 0xC8));
    u16 i;
    for (i = 0; i < count; i++) {
        sum += fn_8016C50C(buf[i]);
    }
    return sum;
}
