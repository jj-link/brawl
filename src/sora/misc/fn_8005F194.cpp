#include <types.h>
#pragma force_active on

extern "C" int fn_8005F194(u8* self, s32 arg1) {
    u32 i = 0;
    u32 low = ((u32)arg1 << 16) >> 16;
    s32 off = 0;
    u8* found;

    for (; i < *(u32*)(self + 0x5C); i++) {
        u8* tbl = *(u8**)(self + 0x58);
        u8* e = tbl + off;
        if (*(u32*)e != 0 && (u32)(arg1 >> 16) == *(u32*)(e + 0x10)) {
            found = tbl + i * 0x18;
            goto done;
        }
        off += 0x18;
    }
    found = 0;
done:
    if (found != 0) {
        u8* p = *(u8**)(found + 0xC);
        p += low << 4;
        if (p[0x1C] & 1) return 1;
    }
    return 0;
}