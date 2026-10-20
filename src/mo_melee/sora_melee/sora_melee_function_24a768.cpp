#include <types.h>
#pragma force_active on

extern "C" bool fn_27_24A768(void* self) {
    u8* node = *(u8**)((u8*)self + 0x44);
    s32 t = (node[8] >> 2) & 0x3f;
    if (t >= 0x17) goto L1;
    if (t == 0xe) goto B;
    if (t >= 0xe) goto EC;
    if (t >= 2) goto EC;
    if (t >= 0) goto B;
    goto EC;
L1:
    if (t == 0x1c) goto B;
    if (t >= 0x1c) goto EC;
    if (t >= 0x19) goto EC;
B:
    if (node[0x14] != 0) goto EC;
    {
        u8* p = *(u8**)((u8*)self + 0xcc);
        if (p[2] == 0) {
            return (1u - p[0xf]) >> 31;
        }
        return (1u - p[0x10]) >> 31;
    }
EC:
    return false;
}
